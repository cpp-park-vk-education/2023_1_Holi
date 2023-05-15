
#include"request_https.hpp"


    void RequestMaker::Get()
    {
        host_ = host;
        net::io_context ioc;
        ssl::context ctx(ssl::context::tlsv12_client);
        load_root_certificates(ctx);
        ctx.set_verify_mode(ssl::verify_peer);
        tcp::resolver resolver(ioc);
        beast::ssl_stream<beast::tcp_stream> stream(ioc, ctx);
        client(std::make_shared<ClientHttps>(ioc, ctx));
        http::request<http::string_body> request{http::verb::get, path, 11};
        request.set(http::field::host, host_);
        request.set(http::field::user_agent, BOOST_BEAST_VERSION_STRING);
        std::thread thr(CallBack, request);
    }; 


    void RequestMaker::Post(json::value body)
    {
        net::io_context ioc;
        ssl::context ctx(ssl::context::tlsv12_client);
        load_root_certificates(ctx);
        ctx.set_verify_mode(ssl::verify_peer);
        tcp::resolver resolver(ioc);
        beast::ssl_stream<beast::tcp_stream> stream(ioc, ctx);
        client(std::make_shared<ClientHttps>(ioc, ctx));
        http::request<http::string_body> request{http::verb::post, path, 11};
        request.set(http::field::host, host_);
        request.set(http::field::user_agent, BOOST_BEAST_VERSION_STRING);
        request.set(http::field::content_type, "application/json");
        request.body() = json::serialize(body);
        request.prepare_payload();
        std::thread thr(CallBack, request);

    };

    void RequestMaker::Delete()
    {
        net::io_context ioc;
        ssl::context ctx(ssl::context::tlsv12_client);
        load_root_certificates(ctx);
        ctx.set_verify_mode(ssl::verify_peer);
        tcp::resolver resolver(ioc);
        beast::ssl_stream<beast::tcp_stream> stream(ioc, ctx);
        client(std::make_shared<ClientHttps>(ioc, ctx));
        http::request<http::string_body> request{http::verb::delete_, path, 11};
        request.set(http::field::host, host_);
        request.set(http::field::user_agent, BOOST_BEAST_VERSION_STRING);
        std::thread thr(CallBack, request);

    };

    void RequestMaker::CallBack(http::request<http::string_body> request)
    {
        client->Run(host_, port_, target_, request);
        auto messsage = client->GetResponse();
        responce_.get_responce(message);
    };

