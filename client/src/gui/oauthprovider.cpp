#include "oauthprovider.h"

//Парсеры ответов

QVector<YTAlbums> YouTube_Albums(MessageInfo info){
    QVector<YTAlbums> result;
    if(info.status_ == http::status::ok){
        boost::json::object jsonObject = info.body_.as_object();
        boost::json::array itemsArray = jsonObject["items"].as_array();
        for(auto& item : itemsArray){
            boost::json::object itemObject = item.as_object();
            auto elem  = itemObject["snippet"];
            QString title = elem.as_object()["title"].as_string().c_str();
            QString description = elem.as_object()["description"].as_string().c_str();
            QString channelId = elem.as_object()["channelId"].as_string().c_str();
            QString id = itemObject["id"].as_string().c_str();
            YTAlbums album;
            album.channelId = channelId;
            album.id = id;
            album.title = title;
            album.description = description;
            result.push_back(album);
        }
    }
    return result;
}

QVector<QString> YouTube_Albums_DB(MessageInfo info){
    QVector<QString> result;
    if(info.status_ == http::status::ok){
        boost::json::array itemsArray = info.body_.as_array();
        for(auto& item : itemsArray){
            if(item.as_object()["exported_from"] == "YT"){
                QString name = item.as_object()["name"].as_string().c_str();
                result.push_back(name);
            }

        }
    }
    return result;
}
QVector<YTVideo> YouTube_Video(MessageInfo info){
    QVector<YTVideo> result;
    if(info.status_ == http::status::ok){
        boost::json::object jsonObject = info.body_.as_object();
        boost::json::array itemsArray = jsonObject["items"].as_array();
        for (const auto& item : itemsArray) {
            boost::json::object itemObject = item.as_object();
            auto snippet  = itemObject["snippet"];
            QString title = snippet.as_object()["title"].as_string().c_str();
            QString description = snippet.as_object()["description"].as_string().c_str();
            auto contentDetails  = itemObject["contentDetails"];
            QString id = contentDetails.as_object()["videoId"].as_string().c_str();
            YTVideo video;
            video.description = description;
            video.title = title;
            video.id = id;
            result.push_back(video);
        }
    }
    return result;
}
