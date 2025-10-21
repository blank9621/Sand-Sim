cmake_minimum_required(VERSION 3.10)
project(Sand-Sim LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)
find_package(SFML 2.6 COMPONENTS system window graphics network audio REQUIRED)

add_executable(app
    src/main.cpp
)

target_link_libraries(app PRIVATE sfml-system sfml-window sfml-graphics sfml-audio sfml-network)
