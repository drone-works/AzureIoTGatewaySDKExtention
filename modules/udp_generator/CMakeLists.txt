#Copyright (c) Microsoft. All rights reserved.
#Licensed under the MIT license. See LICENSE file in the project root for full license information.

cmake_minimum_required(VERSION 2.8.12)

set(udp_generator_sources
    ./src/udp_generator.c
    ../udp/src/udp_sender.cpp
)

set(udp_generator_headers
    ../udp/inc/udp.h
    ../udp/inc/udp2c.h
    ./inc/udp_genetator.h
)

include_directories(./inc ../udp/inc)
include_directories(${GW_INC})

#this builds the udp dynamic library
add_library(udp_generator MODULE ${udp_generator_sources})
target_link_libraries(udp_generator boost_system pthread)

#this builds the udp static library
add_library(udp_generator_static STATIC ${udp_generator_sources})
target_compile_definitions(udp_generator_static PRIVATE BUILD_MODULE_TYPE_STATIC)
target_link_libraries(udp_generator_static boost_system pthread)

linkSharedUtil(udp_generator)
linkSharedUtil(udp_generator_static)

add_module_to_solution(udp_generator)

if(install_modules)
    install(TARGETS udp_generator LIBRARY DESTINATION "${LIB_INSTALL_DIR}/modules") 
endif()

