cmake_minimum_required(VERSION 3.12)
project(Cpp_Project_Memory_Game)

set(CMAKE_CXX_STANDARD 17)

add_executable(Cpp_Project_Memory_Game main.cpp player.cpp player.h reward.cpp reward.h card.cpp card.h board.cpp board.h carddeck.cpp carddeck.h game.cpp game.h rules.cpp rules.h rewarddeck.cpp rewarddeck.h)