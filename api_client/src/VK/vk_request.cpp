#include "vk_request.hpp"
#include "vk_response.hpp"

void VKRequest::execute(){

    std::string url = "https://api.vk.com/method/" + method_ + "?access_token=" + access_token_;

    for (auto& param : params_) {
        url += "&" + param.first + "=" + param.second;
    }

    //Создаем путой объект ответа
    //auto vk_resp = std::make_shared<VKResponse>(true, 0); //Заглушка

    //Запрос к IRequestMaker
    //RequestMaker request(vk_resp) // в конструкторе передаем shared_ptr 
    //на response, метод которого он будет вызывать, чтобы вернуть ответ

    //RequestMAker::get(url);  вызывает метод RequestMaker'a
    //передаем ему готовую ссылку, по которой он будет делать запрос к АПИ
}