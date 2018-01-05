cmake_minimum_required(VERSION 3.1)
project(DevChatDesktop)
find_package(Qt5 COMPONENTS Widgets Sql REQUIRED)

set(CMAKE_INCLUDE_CURRENT_DIR TRUE)
set(CMAKE_AUTOMOC TRUE)


set(DevChatDesktop_SOURCES
    main.cpp
    dbmanager.cpp
    server_list_window.cpp
)

set(DevChatDesktop_HEADERS
    dbmanager.h
    server_list_window.h
)

set(DevChatDesktop_UI
    server_list_window.ui
)

#set(DevChatDesktop_RSC
#    resources.qrc
#)

qt5_wrap_ui(DevChatDesktop_UI_HEADERS ${DevChatDesktop_UI})
#qt5_add_resources(DevChatDesktop_RSC_HEADERS ${DevChatDesktop_RSC})

add_executable(DevChatDesktop
    ${DevChatDesktop_SOURCES}
    ${DevChatDesktop_HEADERS}
    ${DevChatDesktop_UI_HEADERS}
    ${DevChatDesktop_RSC_HEADERS})

target_link_libraries(DevChatDesktop
    Qt5::Widgets
    Qt5::Sql
)