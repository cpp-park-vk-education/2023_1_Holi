//
// Created by Алексей on 09.05.2023.
//

#include "client/https_request_maker_tmp.h"



int MakeHttpsRequest() {
    try {
        auto const host = "api.vk.com";
        auto const port = "443";
        auto const target = "/method/video.getAlbums?access_token=vk1.a.iP6aFDPB3gsmyXIdXpFgGzHDq043Y1tn0k321cYod4mxWP13qdW87ITS6pBShmJiinJ6UDMFYy-sNvkv6X8-_BixjTA5Ba6CBvsz6kSaF62sFmkfqowcyJvBhyB0WPyHsbup3g5OBQpdF9lrwVOpgSLHAiCIwvWTKnt6bcyv3pPAulHrUO5lYtFQNrcIpdkO&v=5.131";
        net::io_context ioc;
        ssl::context ctx(ssl::context::tlsv12_client);

        load_root_certificates(ctx);

        ctx.set_verify_mode(ssl::verify_peer);

        tcp::resolver resolver(ioc);
        beast::ssl_stream<beast::tcp_stream> stream(ioc, ctx);
        std::make_shared<ClientHttps>(ioc, ctx)->Run(host, port, target);
    }
    catch (std::exception const &e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
