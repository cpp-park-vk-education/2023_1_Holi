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
    request_.version(11);
    request_.method(http::verb::get);
    request_.target(target);
    request_.set(http::field::host, host);
    request_.set(http::field::user_agent, BOOST_BEAST_VERSION_STRING);

    stream_.expires_after(std::chrono::seconds(30));

    stream_.connect(resolver_.resolve(host, port));

    Write();
}

void Client::Write() {
    std::cout << "\t--- write: start " << std::endl;

    stream_.expires_after(std::chrono::seconds(30));

    http::write(stream_, request_);

    std::cout << "\t--- write: end " << std::endl;

    GetResponse();
}

MessageInfo Client::GetResponse() {
    buffer_.clear();

    std::cout << "\t--- read: start " << std::endl;

    http::read(stream_, buffer_, response_);

    std::cout << "\t--- read: end " << std::endl;

    auto message_info = response_handler->Handle(std::move(response_));
    std::cout << message_info.status_ << std::endl;
    std::cout << message_info.body_ << std::endl;

    beast::error_code ec;
    stream_.socket().shutdown(tcp::socket::shutdown_both, ec);

    if (ec && ec != beast::errc::not_connected)
        throw beast::system_error{ec};

    return {};
}
