#include "request_maker/requestmaker_https.hpp"

void RequestMaker::Get()
{
    
//    net::io_context ioc;
//    ssl::context ctx(ssl::context::tlsv12_client);
//
//    load_root_certificates(ctx);
//
//    ctx.set_verify_mode(ssl::verify_peer);
//    tcp::resolver resolver(ioc);
//    beast::ssl_stream<beast::tcp_stream> stream(ioc, ctx);

    http::request<http::string_body> request{http::verb::get, target_, 11};
    request.set(http::field::host, host_);
    request.set(http::field::user_agent, BOOST_BEAST_VERSION_STRING);

    client_ = std::make_unique<ClientHttps>(request);
    std::cout << "thread start" << std::endl;
    std::thread thr(&RequestMaker::CallBack, this);
    thr.detach();
//    CallBack();
}

//void RequestMaker::Post(json::value body)
//{
//    std::string path = host_ + target_;
//    net::io_context ioc;
//    ssl::context ctx(ssl::context::tlsv12_client);
//    load_root_certificates(ctx);
//    ctx.set_verify_mode(ssl::verify_peer);
//    tcp::resolver resolver(ioc);
//    beast::ssl_stream<beast::tcp_stream> stream(ioc, ctx);
//    http::request<http::string_body> request{http::verb::post, path, 11};
//    request.set(http::field::host, host_);
//    request.set(http::field::user_agent, BOOST_BEAST_VERSION_STRING);
//    request.set(http::field::content_type, "application/json");
//    request.body() = json::serialize(body);
//    request.prepare_payload();
//
//    client_ = std::make_unique<ClientHttps>(ioc, ctx, request);
//    std::cout << "1" << std::endl;
//    std::thread thr(&RequestMaker::CallBack, this);
//}
//
//void RequestMaker::Delete()
//{
//    std::string path = host_ + target_;
//    net::io_context ioc;
//    ssl::context ctx(ssl::context::tlsv12_client);
//    load_root_certificates(ctx);
//    ctx.set_verify_mode(ssl::verify_peer);
//    tcp::resolver resolver(ioc);
//    beast::ssl_stream<beast::tcp_stream> stream(ioc, ctx);
//    http::request<http::string_body> request{http::verb::delete_, path, 11};
//    request.set(http::field::host, host_);
//    request.set(http::field::user_agent, BOOST_BEAST_VERSION_STRING);
//
//    client_ = std::make_unique<ClientHttps>(ioc, ctx, request);
//    std::thread thr(&RequestMaker::CallBack, this);
//}

void RequestMaker::CallBack()
{
    std::cout << "call back start" << std::endl;
    client_->Run(host_, port_, target_);
    MessageInfo message;
    try
    {
        message = client_->GetResponse();
        std::cout << message << std::endl;
    } 
    catch (const beast::system_error & e) 
    {
        std::cout<< e.what() << std::endl;
    }
    response_->get_response(message);
    std::cout << "call back end" << std::endl;

}
