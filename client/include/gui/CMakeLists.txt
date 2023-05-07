cmake_minimum_required(VERSION 3.5)

project(CMakeVk VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)


find_package(Boost 1.81.0 COMPONENTS system filesystem url REQUIRED)
include_directories(${Boost_INCLUDE_DIRS})


file(GLOB PROJECT_SOURCES
        main.cpp
        mainwindow.cpp
        mainwindow.h
        mainwindow.ui
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

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(CMakeVk)
endif()

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)


add_library(vk ${PROJECT_SOURCES})
target_link_libraries(vk PUBLIC Qt${QT_VERSION_MAJOR}::Widgets)
target_include_directories(vk PUBLIC templates)


add_subdirectory(tests)


#add_subdirectory(server)
#add_subdirectory(client)
