//
// Created by Алексей on 01.05.2023.
//

#include "request_handling/router.h"


MessageInfo Router::Route(const ParsedRequest &request) {
    return {json::parse(R"(
                {
                    "name": "name",
                    "image": "image",
                    "exported_from": "exported_from",
                    "user": "6",
                    "playlists": ["12", "2", "43"]
                }
            )"), http::status::ok};
}

