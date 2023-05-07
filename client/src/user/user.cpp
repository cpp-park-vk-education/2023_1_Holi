
#include "user.hpp"

        void User::setId(int id) {
            this->id = id;
        }

        void User::setName(std::string name) {
            this->name = name;
        }

        void User::setSurname(std::string surname) {
            this->surname = surname;
        }

        void User::setEmail(std::string email) {
            this->email = email;
        }

        void User::setAvatar(std::string avatar) {
            this->avatar = avatar;
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

        void User::setAccessToken(std::string accessToken) {
            this->accessToken = accessToken;
        }

        void User::setRefreshToken(std::string refreshToken) {
            this->refreshToken = refreshToken;
        }

        void User::setExpiresIn(int expiresIn){
            this->expriresIn = expiresIn;
        }

        int User::getId() {
            return id;
        }

        std::string User::getName() {
            return name;
        }

        std::string User::getSurname() {
            return surname;
        }

        std::string User::getEmail() {
            return email;
        }

        std::string User::getAvatar() {
            return avatar;
        }

        std::string User::getAccessToken() {
            return accessToken;
        }

        std::string User::getRefreshToken() {
            return refreshToken;
        }


        int User::getExpiresIn() {
            return expriresIn;
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
