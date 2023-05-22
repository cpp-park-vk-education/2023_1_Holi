#include "request_maker/requestmaker_http.hpp"

void RequestMakerHttp::Get()
{
    std::cout<<"GET start"<<std::endl;

    std::cout<<"requestHTTP"<<std::endl;
    http::request<http::string_body> request{http::verb::get, target_, 11};
    request.set(http::field::host, host_);
    request.set(http::field::user_agent, BOOST_BEAST_VERSION_STRING);

    client_ = std::make_unique<ClientHttp>(request);
    std::cout << "thread start" << std::endl;
    std::thread thr(&RequestMakerHttp::CallBack, this);
    thr.detach();

    std::cout<<"GET end"<<std::endl;
}

void RequestMakerHttp::Post(std::string & body)
{

    http::request<http::string_body> request{http::verb::post, target_, 11};
    request.set(http::field::host, host_);
    request.set(http::field::user_agent, BOOST_BEAST_VERSION_STRING);
    request.set(http::field::content_type, "application/json");
    request.body() = json::serialize(body);
    request.prepare_payload();


    client_ = std::make_unique<ClientHttp>(request);
    std::cout << "thread start" << std::endl;
    std::thread thr(&RequestMakerHttp::CallBack, this);
    thr.detach();

}
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

void RequestMakerHttp::CallBack()
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
    window_->get_response(message);
    std::cout << "call back end" << std::endl;

}
