cmake_minimum_required(VERSION 4.1)
project(CornerGrocerApp)

set(CMAKE_CXX_STANDARD 20)

add_executable(CornerGrocerApp
        main.cpp
        ItemFrequency.cpp
        FrequencyBackupWriter.cpp
        CornerGrocerApp.cpp
)
