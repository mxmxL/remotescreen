cmake_minimum_required(VERSION 3.16)

project(simulator VERSION 0.1 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_CFLAGS "/utf-8")
set(CMAKE_CXX_FLAGS "/utf-8")

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

include_directories(
    include
    src
    src/signal
    src/window
    src/widget
)

file(GLOB PROJECT_SOURCES
    src/*.h
    src/*.cpp

    src/signal/*.h
    src/window/*.h
    src/widget/*.h

    src/signal/*.cpp
    src/window/*.cpp
    src/widget/*.cpp

    images.qrc

    win32.rc
)

link_directories(
    lib/
)


add_executable(remotescreen
    ${PROJECT_SOURCES}
)

target_link_libraries(remotescreen
    PRIVATE Qt${QT_VERSION_MAJOR}::Widgets
)

set_target_properties(remotescreen PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER www.rising.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

install(TARGETS remotescreen
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})

