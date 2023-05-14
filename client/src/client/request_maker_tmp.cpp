//
// Created by Алексей on 09.05.2023.
//

#include "client/request_maker_tmp.h"


int MakeRequest() {
    try {
        auto const host = "api.vk.com";
        auto const port = "6543";
        auto const target = "/user?user_id=3";

        net::io_context ioc;

        std::make_shared<Client>(ioc)->Run(host, port, target);
    }
    catch (std::exception const &e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
