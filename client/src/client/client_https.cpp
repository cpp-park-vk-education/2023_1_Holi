//
// Created by Алексей on 14.05.2023.
//

#include "client/client_https.h"


ClientHttps::ClientHttps(http::request<http::string_body> request) :
        request_(std::move(request)),
        ctx_(ssl::context::tlsv12_client),
        resolver_(ioc_),
        stream_(ioc_, ctx_),
        response_handler_(std::make_unique<ResponseHandler>()){

    load_root_certificates(ctx_);
    ctx_.set_verify_mode(ssl::verify_peer);
//    stream_ = beast::ssl_stream<beast::tcp_stream>(ioc_, ctx_);
}

void ClientHttps::Run(
        const std::string &host,
        const std::string &port,
        const std::string &target
) {
    std::cout << "client run start" << std::endl;
//    std::this_thread::sleep_for(std::chrono::minutes(1));

    if (!SSL_set_tlsext_host_name(stream_.native_handle(), host.c_str())) {
        beast::error_code ec{static_cast<int>(::ERR_get_error()), net::error::get_ssl_category()};
        throw beast::system_error{ec};
    }

    std::cout << "11" << std::endl;
    auto const results = resolver_.resolve(host, port);

    std::cout << "22" << std::endl;

    beast::get_lowest_layer(stream_).expires_after(std::chrono::seconds(30));

    std::cout << "33" << std::endl;

    beast::get_lowest_layer(stream_).connect(results);
    std::cout << "44" << std::endl;
    stream_.handshake(ssl::stream_base::client);
    std::cout << "55" << std::endl;

    Write();
}

void ClientHttps::Write() {
    std::cout << "\t--- write: start " << std::endl;

    beast::get_lowest_layer(stream_).expires_after(std::chrono::seconds(30));

    http::write(stream_, request_);

    std::cout << "\t--- write: end " << std::endl;
}

MessageInfo ClientHttps::GetResponse() {
    buffer_.clear();

    std::cout << "\t--- read: start " << std::endl;

    http::read(stream_, buffer_, response_);

    std::cout << "\t--- read: end " << std::endl;

    auto message_info = response_handler_->Handle(std::move(response_));
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
