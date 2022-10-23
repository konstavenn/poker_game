cmake_minimum_required(VERSION 3.13)
project(poker)
set(CMAKE_CXX_STANDARD 20)

set(SOURCE_FILES main.cpp game.cpp player.cpp deck.cpp pair.cpp card.cpp)

add_executable(poker ${SOURCE_FILES})
