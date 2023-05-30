//
// Created by Алексей on 01.05.2023.
//

#include "server/session.h"


void fail(beast::error_code ec, char const *what) {
    std::cerr << what << ": " << ec.message() << "\n";
}

//
//http::response<http::string_body> HandleRequest(http::request<http::string_body> &&request) {
//    http::response<http::string_body> response{http::status::ok, request.version()};
//
//    response.set(http::field::host, "localhost");
//    response.set(http::field::server, BOOST_BEAST_VERSION_STRING);
//    response.keep_alive(request.keep_alive());
//
//    std::string body = R"(
//        {
//            "name": "name",
//            "image": "image",
//            "exported_from": "exported_from",
//            "user": "6",
//            "playlists": ["12", "2", "43"]
//        }
//    )";
//
//    response.set(http::field::content_type, "application/json");
//    response.set(http::field::content_length, std::to_string(body.length()));
//    response.body() = body;
//    response.prepare_payload();
//
//    return response;
//}

void Session::Start() {
    net::dispatch(stream_.get_executor(),
                  beast::bind_front_handler(
                          &Session::DoRead,
                          shared_from_this()));
}

void Session::DoRead() {
    request_ = {};

    stream_.expires_after(std::chrono::seconds(30));
    std::cout << "\t--- read: start " << std::this_thread::get_id() << std::endl;

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
    std::cout << "\t--- read: done " << std::this_thread::get_id() << std::endl;
    std::cerr << request_.target() << std::endl;
    std::cerr << request_.body() << std::endl;
    SendResponse(request_handler_->Handle(std::move(request_)));
}

void Session::SendResponse(http::message_generator &&message) {
    bool keep_alive = message.keep_alive();

    std::cout << "\t--- write: start " << std::this_thread::get_id() << std::endl;

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
        std::cout << "CLOSE" << std::endl;
        return DoClose();
    }

    std::cout << "\t--- write: done " << std::this_thread::get_id() << std::endl << std::endl;

    DoRead();
}

void Session::DoClose() {
    beast::error_code ec;
    stream_.socket().shutdown(tcp::socket::shutdown_send, ec);
}
