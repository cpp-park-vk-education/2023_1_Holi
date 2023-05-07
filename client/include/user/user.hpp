
#pragma once

#include <string>
#include <iostream>
#include <vector>



class User {
    public:
        User(): id(0), name(""), surname(""), email(""), avatar("") {}

        User(int id, std::string name, std::string surname, std::string email, std::string avatar) {
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
        std::string avatar;
        std::string accessToken;
        std::string refreshToken;
        int expriresIn;
        std::vector<int> friends_id;
        bool is_friend;
};