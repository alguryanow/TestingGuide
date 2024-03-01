cmake_minimum_required(VERSION 3.1)
project(testing_guide)                         # <---- 

set(TARGET_ARCH lib-linux64)

#-- файл, в котором указан путь до SystemC.
#-- Этот файл не должен быть в репозитории, потому что
#-- у каждого разработчика этот путь свой
include("systemc_path.txt")

include_directories(${CMAKE_PREFIX_PATH}/include)

link_directories(${CMAKE_PREFIX_PATH}/${TARGET_ARCH})

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_CXX_STANDARD_REQUIRED ON) 

set(CMAKE_CXX_EXTENSIONS OFF)

aux_source_directory(../src SRC_LIST)
add_executable(${PROJECT_NAME} ${SRC_LIST})

target_link_libraries(${PROJECT_NAME} systemc)       

# testing
add_executable(unit_test ../tests/unit_test.cpp)
target_link_libraries(unit_test systemc)


