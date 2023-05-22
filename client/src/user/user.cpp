
#include "user.hpp"

        void User::setId() {
            
        }

        void User::setName(std::string body) {

        }

        void User::setSurname() {
            
        }

        void User::setEmail() 
        {
 
        }

        void User::setFriend(int id_friend){
            isFriend(id_friend);
            if( is_friend == true)
            {
                std::cout<<"Already friend"<<std::endl;
            }
            else
            {
                friends_id.push_back(id_friend);
            }
        }

        void User::setAccessToken()
        {
        }

        void User::setRefreshToken() {
            
        }

        void User::setExpiresIn(){
            
        }

        void User::getId() {
            
        }

        void User::getName(std::unique_ptr<MainWindow> window) {
            
            std::cout<<window<<std::endl;
            std::cout<<"user"<<std::endl;
            std::string target = "/user?user_id=7";
            //std::unique_ptr<MainWindow> window_ = std::move(window);
            request_maker = std::make_unique<RequestMakerHttp>(target, std::move(window));
            std::cout<<"GET user"<<std::endl;
            request_maker->Get(); 
        }

        void User::getSurname() {
            
        }

        void User::getEmail() {
            
        }

        void User::getAccessToken() {
            
        }

        void User::getRefreshToken() {
            
        }


        void User::getExpiresIn() {
            
        }

        bool User::isFriend(int id){
            is_friend = false;
            for (int i = 0; i < friends_id.size(); i++ ){
                if (id == friends_id[i])
                {
                    is_friend = true;
                    break;
                } 
            }
            return is_friend;
        }
