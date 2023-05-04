cmake_minimum_required(VERSION 3.5)

project(CMakeVk VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

find_package(Qt6 REQUIRED COMPONENTS NetworkAuth)

file(GLOB PROJECT_SOURCES
        main.cpp
        mainwindow.cpp
        mainwindow.h
        mainwindow.ui
        QTest.cpp
       # templates/albums.cpp
       # templates/albums.h
       # templates/albums.ui

        #templates/chat/chat.cpp
        #templates/chat/chat.h
        #templates/chat/chat.ui

        #templates/config/config.cpp
        #templates/config/config.h
        #templates/config/config.ui

        #templates/friends/friends.cpp
        #templates/friends/friends.h
        #templates/friends/friends.ui

        #templates/friends_in/friends_in.cpp
        #templates/friends_in/friends_in.h
        #templates/friends_in/friends_in.ui

        #templates/friends_out/friends_out.cpp
        #templates/friends_out/friends_out.h
        #templates/friends_out/friends_out.ui

        #templates/login/login.cpp
        #templates/login/login.h
        #templates/login/login.ui

        #templates/main_page/main_page.cpp
        #templates/main_page/main_page.h
        #templates/main_page/main_page.ui

        #templates/onvk/onvk.cpp
        #templates/onvk/onvk.h
        #templates/onvk/onvk.ui

        #templates/onyoutube/onyoutube.cpp
        #templates/onyoutube/onyoutube.h
        #templates/onyoutube/onyoutube.ui

        #templates/signup/signup.cpp
        #templates/signup/signup.h
        #templates/signup/signup.ui

        #lib/OAuthProvider/oauthprovider.h
        #lib/OAuthProvider/oauthprovider.cpp
        templates/*.cpp
        templates/*.h
        templates/*.ui


    )

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(CMakeVk
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET CMakeVk APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(CMakeVk SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(CMakeVk
            ${PROJECT_SOURCES}
        )
    endif()
endif()





target_link_libraries(CMakeVk PRIVATE Qt${QT_VERSION_MAJOR}::Widgets )
target_link_libraries(CMakeVk PRIVATE Qt6::NetworkAuth)
set_target_properties(CMakeVk PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

install(TARGETS CMakeVk
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})


include_directories(CMakeVk PUBLIC templates)

#add_subdirectory(tests)
if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(CMakeVk)
endif()

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)


add_library(vk ${PROJECT_SOURCES})
target_link_libraries(vk PUBLIC Qt${QT_VERSION_MAJOR}::Widgets)
target_include_directories(vk PUBLIC templates)


add_subdirectory(tests)
