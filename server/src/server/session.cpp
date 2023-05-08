//
// Created by Алексей on 01.05.2023.
//

#include "server/session.h"


void Session::Start() {

}

void Session::DoRead() {

}

void Session::OnRead(beast::error_code ec, std::size_t bytes_transferred) {

}

void Session::SendResponse(http::message_generator &&message) {

}

void Session::OnWrite(
        bool keep_alive,
        beast::error_code ec,
        std::size_t bytes_transferred
) {

}

void Session::DoClose() {

}
