//
// Created by Алексей on 01.05.2023.
//

#include "server/session.h"


void Session::Start() {
    net::dispatch(stream_.get_executor(),
                  beast::bind_front_handler(
                          &Session::DoRead,
                          shared_from_this()));
}

void Session::DoRead() {
    request_ = {};

    stream_.expires_after(std::chrono::seconds(30));

    http::async_read(stream_, buffer_, request_,
                     beast::bind_front_handler(
                             &Session::OnRead,
                             shared_from_this()));
}

void Session::OnRead(beast::error_code ec, std::size_t bytes_transferred) {
    boost::ignore_unused(bytes_transferred);

    if (ec == http::error::end_of_stream)
        return DoClose();

    if (ec)
        return fail(ec, "read");

    send_response(
            handle_request(*doc_root_, std::move(req_)));
}

void Session::SendResponse(http::message_generator &&message) {
    bool keep_alive = message.keep_alive();

    beast::async_write(
            stream_,
            std::move(message),
            beast::bind_front_handler(
                    &Session::OnWrite, shared_from_this(), keep_alive));
}

void Session::OnWrite(
        bool keep_alive,
        beast::error_code ec,
        std::size_t bytes_transferred
) {
    boost::ignore_unused(bytes_transferred);

    if (ec)
        return fail(ec, "write");

    if (!keep_alive) {
        return DoClose();
    }

    DoRead();
}

void Session::DoClose() {
    beast::error_code ec;
    stream_.socket().shutdown(tcp::socket::shutdown_send, ec);
}
