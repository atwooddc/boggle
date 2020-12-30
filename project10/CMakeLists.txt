cmake_minimum_required(VERSION 3.15)
project(project10)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -Wall -Werror -Wextra -pedantic -pedantic-errors")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})

set(CMAKE_CXX_STANDARD 14)

add_executable(project10
        Trie.cpp
        Trie.h
        TrieNode.cpp
        TrieNode.h
        BoggleDriver.cpp
        Boggle.cpp
        Boggle.h)