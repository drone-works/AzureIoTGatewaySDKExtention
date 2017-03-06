#Copyright (c) Microsoft. All rights reserved.
#Licensed under the MIT license. See LICENSE file in the project root for full license information.

cmake_minimum_required(VERSION 2.8.12)

set(udp_sources
    ./src/udp2c.c
    ./src/udp_sender.cpp
    ./src/udp_receiver.cpp
)

set(udp_headers
    ./inc/udp2c.h
    ./inc/udp.h  
)

include_directories(./inc)
include_directories(${GW_INC})

#this builds the udp dynamic library
add_library(udp MODULE ${udp_sources})
target_link_libraries(udp boost_system pthread)

#this builds the udp static library
add_library(udp_static STATIC ${udp_sources})
target_compile_definitions(udp_static PRIVATE BUILD_MODULE_TYPE_STATIC)
target_link_libraries(udp_static boost_system pthread)

linkSharedUtil(udp)
linkSharedUtil(udp_static)

add_module_to_solution(udp)

if(install_modules)
    install(TARGETS udp LIBRARY DESTINATION "${LIB_INSTALL_DIR}/modules") 
endif()

