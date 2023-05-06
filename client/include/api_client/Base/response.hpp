#pragma once

#include <vector>
#include <string>

//todo: string поменять на Json::value
class Response{
private:
    bool success_;
    int error_code_;
    std::string result_;
public:
    Response(){}

    Response(bool success, int error_code):
        success_(success), error_code_(error_code) {}

    virtual ~Response(){}

    bool isSuccess() { return success_; }
    int getErrorCode() { return error_code_; }

    void get_response(int error_code, std::string result){
        error_code_ = error_code;
        result_ = result;
        parse_result();
    }

    virtual void parse_result() = 0;
};