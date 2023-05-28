
#include "user.hpp"
#include <QSettings>
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

        void User::getName(MainWindow *window) {
            
            std::cout<<"getName start"<<std::endl;
            std::string target = "/user?user_id=1";
            //std::unique_ptr<MainWindow> window_ = std::move(window);
            request_maker = std::make_unique<RequestMakerHttp>(target, window);
            std::cout<<"GET user"<<std::endl;
            request_maker->Get(0);
            std::cout<<"getName end"<<std::endl;
        }

        void User::getSurname() {
            
        }
        void User::addPlaylistOrChannel(std::string Playlist, std::string Service, MainWindow *window, QListWidgetItem *item){
            std::cout<<"getName start"<<std::endl;
            QSettings current("Holi", "CurrentUser");
            std::string id = current.value("id").toString().toStdString();
            std::string target = "/video/list?user_id="+id;
            std::cout << target;
            //std::unique_ptr<MainWindow> window_ = std::move(window);
            request_maker = std::make_unique<RequestMakerHttp>(target, window);
            json::object obj;
            obj["name"] = Playlist;
            obj["exported_from"] = Service;

            std::string str = boost::json::serialize( boost::json::value_from(obj));
            std::cout << str;
            request_maker->Post(str,0);
            std::cout<<"getName end"<<std::endl;

            window->MP_VK_SuccesfullImportPlaylists(item);
        }

        void User::getPlaylistOrChannel(MainWindow *window){
            std::cout<<"getName start"<<std::endl;
            QSettings current("Holi", "CurrentUser");
            std::string id = current.value("id").toString().toStdString();
            std::string target = "/video/list/all?user_id="+id;

            request_maker = std::make_unique<RequestMakerHttp>(target, window);
            std::cout<<"GET user"<<std::endl;




            request_maker->Get(100);



        }
        void User::getEmail() {
            
        }

        void User::getAccessToken() {
            
        }

        void User::getRefreshToken() {
            
        }


        void User::getExpiresIn() {
            
        }

        void User::registrate(std::string name, std::string email, std::string password, MainWindow* window){
            std::cout<<"Регистрируем пользователя..."<<std::endl;
            std::string target = "/user/auth";

            request_maker = std::make_unique<RequestMakerHttp>(target,window);

            json::object obj;
            obj["email"] = email;
            obj["login"] = name;
            obj["name"] = name;
            obj["surname"] = name;
            obj["password"] = password;

            std::string str = boost::json::serialize( boost::json::value_from(obj));
            std::cout << str;
            request_maker->Post(str,1);
            std::cout<<"Запрос отправлен"<<std::endl;


        }

        void User::auth(std::string username, std::string password, MainWindow* window){
            std::string target = "/user/auth/login";
            request_maker = std::make_unique<RequestMakerHttp>(target, window);
            json::object obj;
            obj["login"] = username;
            obj["password"] = password;

            std::string str = boost::json::serialize(boost::json::value_from(obj));
            request_maker->Post(str, 2);
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


