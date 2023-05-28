#include "api_client/YT/yt_client.hpp"
#include "api_client/YT/yt_request.hpp"

void YTClient::GetPlaylists(MainWindow* window, int flag){
    std::string method = "youtube/v3/playlists";
    std::map<std::string, std::string> params = 
    {

        {"part", "snippet,contentDetails"},
        {"mine", "true"},


    };
    yt_request = std::make_unique<YTRequest>();

    yt_request->setAccessToken(access_token_);
    yt_request->setMethod(method);
    yt_request->setParams(params);

    yt_request->execute(window, flag);
}

void YTClient::GetVideos(MainWindow* window, int flag, std::string  PlaylistID){
    std::string method = "youtube/v3/playlistItems";
    std::map<std::string, std::string> params =
    {

        {"part", "snippet,contentDetails"},
        {"mine", "true"},
        {"playlistId", PlaylistID}


    };
    yt_request = std::make_unique<YTRequest>();

    yt_request->setAccessToken(access_token_);
    yt_request->setMethod(method);
    yt_request->setParams(params);

    yt_request->execute(window, flag);
}

//https://content-youtube.googleapis.com/youtube/v3/playlists?maxResults=25&part=snippet,contentDetails&mine=true&key=AIzaSyAa8yy0GdcGPHdtD083HiGGx_S0vMPScDM

/* Response:
{
  "error": {
    "code": 401,
    "message": "Request had invalid authentication credentials. Expected OAuth 2 access token, login cookie or other valid authentication credential. See https://developers.google.com/identity/sign-in/web/devconsole-project.",
    "errors": [
      {
        "message": "Invalid Credentials",
        "domain": "global",
        "reason": "authError",
        "location": "Authorization",
        "locationType": "header"
      }
    ],
    "status": "UNAUTHENTICATED"
  }
}
*/

