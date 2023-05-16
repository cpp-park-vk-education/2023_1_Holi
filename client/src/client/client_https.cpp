//
// Created by Алексей on 14.05.2023.
//

#include "client/client_https.h"

void ClientHttps::Run(
        const std::string &host,
        const std::string &port,
        const std::string &target
) {
    request_.version(11);
    request_.method(http::verb::get);
    request_.target(target);
    request_.set(http::field::host, host);
    request_.set(http::field::user_agent, BOOST_BEAST_VERSION_STRING);

//    std::string s = "{}";
//    request_.body() = s;
//    request_.content_length(s.length());

    if (!SSL_set_tlsext_host_name(stream_.native_handle(), host.c_str())) {
        beast::error_code ec{static_cast<int>(::ERR_get_error()), net::error::get_ssl_category()};
        throw beast::system_error{ec};
    }

    auto const results = resolver_.resolve(host, port);

    beast::get_lowest_layer(stream_).expires_after(std::chrono::seconds(30));

    beast::get_lowest_layer(stream_).connect(results);
    stream_.handshake(ssl::stream_base::client);

    Write();
}

void ClientHttps::Write() {
    std::cout << "\t--- write: start " << std::endl;

    beast::get_lowest_layer(stream_).expires_after(std::chrono::seconds(30));

    http::write(stream_, request_);

    std::cout << "\t--- write: end " << std::endl;

    GetResponse();
}

MessageInfo ClientHttps::GetResponse() {
    buffer_.clear();

    std::cout << "\t--- read: start " << std::endl;

    http::read(stream_, buffer_, response_);

    std::cout << "\t--- read: end " << std::endl;

//    std::cout << response_ << std::endl;
    auto message_info = response_handler->Handle(std::move(response_));
    std::cout << message_info.status_ << std::endl;
    std::cout << message_info.body_ << std::endl;

    beast::error_code ec;
    stream_.shutdown(ec);
    if (ec == net::error::eof)
        ec = {};
    if (ec)
        std::cerr << ec.message() << "\n";

    return message_info;
}
