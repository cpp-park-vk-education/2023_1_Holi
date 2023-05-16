
#pragma once

#include <string>
#include <iostream>
#include <vector>



class User {
    public:
        User(const std::string& email_, const std::string& login_, const std::string& password_): 
        id(0), name(""), surname(""), avatar(""), email(email_), login(login_), password(password_) {}

        User(const std::string& login_, const std::string& password_): login(login_), password(password_){
            setId(id);
            setName(name);
            setSurname(surname);
            setEmail(email);
            setAvatar(avatar);
        }

        ~User() {};

        void setId(int id);

        void setName(std::string name);

        void setSurname(std::string surname);

        void setEmail(std::string email);

        void setAvatar(std::string avatar);
        
        void setFriend(int id_friend);

        void setAccessToken(std::string accessToken);

        void setRefreshToken(std::string refreshToken);

        void setExpiresIn(int expiresIn);

        int getId();

        std::string getName();

        std::string getSurname();

        std::string getEmail();

        std::string getAvatar();

        std::string getAccessToken();

        std::string getRefreshToken();

        int getExpiresIn();

        bool isFriend(int id);

    public:
        int id;
        std::string name;
        std::string surname;
        std::string email;
        std::string login;
        std::string password;
        std::string avatar;
        std::string accessToken;
        std::string refreshToken;
        int expriresIn;
        std::vector<int> friends_id;
        bool is_friend;
};