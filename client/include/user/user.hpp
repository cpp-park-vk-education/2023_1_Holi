
#pragma once

#include <memory>
#include <string>
#include <iostream>
#include <vector>
#include <QListWidgetItem>

class RequestMakerHttp;
class MainWindow;

class User {
    public:

        User(): name("name: Алексей") {};

        User(const std::string& email_, const std::string& login_, const std::string& password_):
        name("name: Алексей"),  email(email_), login(login_), password(password_)
        {
        }

      /*User(const std::string& login_, const std::string& password_): login(login_), password(password_)
        {
        }*/

        ~User() {};

        void setId();

        void setName(std::string body);

        void setSurname();

        void setEmail();

        void setAvatar();

        void setFriend(int id_friend);

        void setAccessToken();

        void setRefreshToken();

        void setExpiresIn();

        void getId();

        void getName(MainWindow *window);

        void getSurname();

        void getEmail();

        void getAccessToken();

        void getRefreshToken();

        void getExpiresIn();

        bool isFriend(int id);

        void singin(std::string login, std::string password, MainWindow *window);

        void addPlaylistOrChannel(std::string Playlist, std::string Service, MainWindow *window, QListWidgetItem *item);

        void getPlaylistOrChannel(MainWindow *window);

        void registrate(std::string name, std::string email, std::string password, MainWindow* window);

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
        std::string body;
        int expriresIn;
        std::vector<int> friends_id;
        bool is_friend;
        std::unique_ptr<RequestMakerHttp> request_maker;
};


#include "request_maker/requestmaker_http.hpp"
#include "gui/mainwindow.h"
