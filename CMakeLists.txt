cmake_minimum_required(VERSION 3.9.3)

project(client)

set(CMAKE_CXX_STANDARD 11)

include_directories("Client/Headers")

if (WIN32)
    set(BOOST_ROOT "C:/boost_1_65_1")
    set(Boost_USE_STATIC_LIBS ON)
    set(Boost_USE_MULTITHREAD ON)

    include_directories(${BOOST_ROOT})
    link_directories(${BOOST_ROOT}/stage/lib)
endif()

set(SOURCE_FILES Client/Sources/Client.cpp Client/Sources/KeyboardEvent.cpp Client/Sources/MouseEvent.cpp Client/Sources/main.cpp)

add_executable(client ${SOURCE_FILES})

if(NOT MSVC)
    find_package(Boost REQUIRED COMPONENTS date_time filesystem wserialization system serialization thread regex)

    if (Boost_FOUND)
        include_directories(${Boost_INCLUDE_DIRS})
        target_link_libraries(TARGET_NAME ${Boost_LIBRARIES})
    endif()
endif()
