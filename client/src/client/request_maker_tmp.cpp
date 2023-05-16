//
// Created by Алексей on 09.05.2023.
//

#include "client/request_maker_tmp.h"


int MakeRequest() {
    try {
        auto const host = "localhost";
        auto const port = "8080";
        auto const target = "/video/list/all?user_id=7";
        net::io_context ioc;
        //std::make_unique<ClientHttp>(ioc)->Run(host, port, target);
    }
    catch (std::exception const &e) {

        std::cerr << "Error: " << e.what() << std::endl;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
