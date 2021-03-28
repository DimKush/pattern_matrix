cmake_minimum_required(VERSION 3.14)

set(PROJECT_NAME pattern_matrix)
set(MAJOR_VERSION 0)
set(MINOR_VERSION 1)

set(LIB_NAME Matrix)

message(DEBUG " Build type : ${CMAKE_BUILD_TYPE}")
if(CMAKE_BUILD_TYPE STREQUAL Release)
    if(DEFINED $ENV{TRAVIS_BUILD_NUMBER})
        set(PATCH_VERSION $ENV{TRAVIS_BUILD_NUMBER})
    else()
        set(PATCH_VERSION 1)
    endif()
else()
    set(PATCH_VERSION 1)

endif()

project(${PROJECT_NAME} VERSION ${MAJOR_VERSION}.${MINOR_VERSION}.${PATCH_VERSION})

add_executable(${PROJECT_NAME} ${PROJECT_SOURCE_DIR}/src/main.cpp)

add_library(${LIB_NAME} STATIC
        ${PROJECT_SOURCE_DIR}/src/RealMatrix/RealMatrix.cpp
        ${PROJECT_SOURCE_DIR}/src/Matrix/Matrix.tpp
        ${PROJECT_SOURCE_DIR}/include/Matrix/Matrix.h
        ${PROJECT_SOURCE_DIR}/include/MatrixProxy/MatrixProxy.h
        ${PROJECT_SOURCE_DIR}/include/RealMatrix/RealMatrix.h
        )

target_include_directories(${LIB_NAME} PUBLIC ${PROJECT_SOURCE_DIR}/include ${PROJECT_SOURCE_DIR})
target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR}/include)

