cmake_minimum_required(VERSION 3.15)

project( turkish_checkers )

include_directories(
    ${PROJECT_SOURCE_DIR}/include
    )

set(SOURCES
    src/main.cpp
)

add_executable(${PROJECT_NAME} ${SOURCES})