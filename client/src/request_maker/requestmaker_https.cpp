#include "request_maker/requestmaker_https.hpp"
#include "client/root_certificates.hpp"

void RequestMaker::Get()
{
    std::string path = host_ + target_;
    net::io_context ioc;
    ssl::context ctx(ssl::context::tlsv12_client);

    load_root_certificates(ctx);

    ctx.set_verify_mode(ssl::verify_peer);
    tcp::resolver resolver(ioc);
    beast::ssl_stream<beast::tcp_stream> stream(ioc, ctx);

    client_ = std::make_unique<ClientHttps>(ioc, ctx);

    http::request<http::string_body> request{http::verb::get, path, 11};
    request.set(http::field::host, host_);
    request.set(http::field::user_agent, BOOST_BEAST_VERSION_STRING);
    std::thread thr(&RequestMaker::CallBack, this, request);
}


void RequestMaker::Post(json::value body)
{
    std::string path = host_ + target_;
    net::io_context ioc;
    ssl::context ctx(ssl::context::tlsv12_client);
    load_root_certificates(ctx);
    ctx.set_verify_mode(ssl::verify_peer);
    tcp::resolver resolver(ioc);
    beast::ssl_stream<beast::tcp_stream> stream(ioc, ctx);
    client_ = std::make_unique<ClientHttps>(ioc, ctx);
    http::request<http::string_body> request{http::verb::post, path, 11};
    request.set(http::field::host, host_);
    request.set(http::field::user_agent, BOOST_BEAST_VERSION_STRING);
    request.set(http::field::content_type, "application/json");
    request.body() = json::serialize(body);
    request.prepare_payload();
    std::thread thr(&RequestMaker::CallBack, this, request);
}

void RequestMaker::Delete()
{
    std::string path = host_ + target_;
    net::io_context ioc;
    ssl::context ctx(ssl::context::tlsv12_client);
    load_root_certificates(ctx);
    ctx.set_verify_mode(ssl::verify_peer);
    tcp::resolver resolver(ioc);
    beast::ssl_stream<beast::tcp_stream> stream(ioc, ctx);
    client_ = std::make_unique<ClientHttps>(ioc, ctx);
    http::request<http::string_body> request{http::verb::delete_, path, 11};
    request.set(http::field::host, host_);
    request.set(http::field::user_agent, BOOST_BEAST_VERSION_STRING);
    std::thread thr(&RequestMaker::CallBack, this, request);
}

void RequestMaker::CallBack(http::request<http::string_body> request)
{
    client_->Run(host_, port_, target_);
    auto message = client_->GetResponse();
    response_->get_response(message);
}
