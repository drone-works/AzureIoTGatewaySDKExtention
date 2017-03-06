#Copyright (c) Microsoft. All rights reserved.
#Licensed under the MIT license. See LICENSE file in the project root for full license information.

cmake_minimum_required(VERSION 2.8.12)

set(udp_gateway_sources
    ./src/main.c
)

if(WIN32)
#   this sample can work only linux
#
#    set(simulated_device_cloud_upload_sources 
#        ${simulated_device_cloud_upload_sources}
#        ./src/simulated_device_cloud_upload_win.json
#    )
#    set_source_files_properties(./src/simulated_device_cloud_upload_win.json PROPERTIES HEADER_FILE_ONLY ON)
else()
    set(udap_gateway_sources 
        ${udp_gateway_sources}
        ./src/udp_gateway_lin.json
    )
    set_source_files_properties(./src/udp_gateway_lin.json PROPERTIES HEADER_FILE_ONLY ON)
endif()

if(run_as_a_service)
    set(modules_service_c_file ./src/module_service_config_enabled.c)
else()
    set(modules_service_c_file ./src/module_service_config_disabled.c)
endif()

include_directories(./inc ${IOTHUB_CLIENT_INC_FOLDER})
include_directories(${GW_INC})
include_directories(../../modules/common)

add_executable(udp_gateway ${modules_service_c_file} ${udp_gateway_sources})

add_dependencies(udp_gateway identity_map iothub logger)

target_link_libraries(udp_gateway gateway)
linkSharedUtil(udp_gateway)
linkHttp(udp_gateway)
install_broker(udp_gateway ${CMAKE_CURRENT_BINARY_DIR}/$(Configuration) )
copy_gateway_dll(udp_gateway ${CMAKE_CURRENT_BINARY_DIR}/$(Configuration) )
copy_iothub_client_dll(udp_gateway ${CMAKE_CURRENT_BINARY_DIR}/$(Configuration) )

add_sample_to_solution(udp_gateway)

if(install_executables)
    install(TARGETS udp_gateway DESTINATION bin)
endif()
