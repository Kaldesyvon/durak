cmake_minimum_required(VERSION 3.26)
project(durak)

set(CMAKE_CXX_STANDARD 17)

add_executable(durak main.cpp
        Card.h
        Card.cpp
        Player.h
        Player.cpp
        Deck.h
        Deck.cpp)
