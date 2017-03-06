# Raspberry Pi3(Raspbian) and Ubuntu(14.0.4) Sample 
This sample is extention of simulated_device. Extended features are following. 
- Generate fake temperature data and send it to udp_gateway using UDP.

## Setup 
* Raspberry Pi3 or ubuntu - please refer [https://github.com/Azure/azure-iot-gateway-sdk/blob/master/doc/devbox_setup.md#linux](https://github.com/Azure/azure-iot-gateway-sdk/blob/master/doc/devbox_setup.md#linux) 
* Overwrite copy modules and samples directories. Modified and added files are 
    * modules/CMakeLists.txt 
    * modules/udp/inc/ 
        * udp2c.h 
        * udp.h 
    * modules/udp/src/ 
        * udp2c.c 
        * udp_receiver.c 
        * udp_sender.c 
    * modules/upd_generator/inc 
        * udp_generator.h 
    * modules/udp_generator/src 
        * udp_generator.c 
    * samples/CMakeLists.txt 
    * samples/udp_gateway <- this is the sample! 
* Then run build.sh in build directory 

## Run 
Please edit samples/udp_gateway/src/udp_gateway_sample_lin.json. Specify your IoT Hub, Device Id of Simulated device and Device Key for Device Id on IoT Hub. 
Run! 
```shell
$ cd azure-iot-gateway-sdk/build
$ ./samples/udp_gateway/udp_gateway ./../samples/udp_gateway/src/udp_gateway_sample_lin.json
```
## Architecture
![Architecure](./udp_gateway_architecture.png)



