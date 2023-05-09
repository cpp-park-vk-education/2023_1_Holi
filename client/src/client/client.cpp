//
// Created by Алексей on 09.05.2023.
//

#include "client/client.h"


void Client::Close() {

}

void Client::Run(
        const std::string &host,
        const std::string &port,
        const std::string &target
) {

}

void Client::Write(http::request<http::string_body> request) {

}

MessageInfo Client::GetResponse() {
    return {}
}

void Client::Resolve() {

}

void Client::Connect() {

}
