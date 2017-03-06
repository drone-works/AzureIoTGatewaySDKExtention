# UDP Sample Extension of Azure IoT Gateway SDK
This sample is extension of [Azure IoT Gateway SDK](http://github.com/azure/azure-iot-gateway-sdk) Please see [sample discription](samples/udp_gateway/src/readme.md).
You can use simulated device that is using UDP and send temperature data to Azure IoT Hub. 

## License 
All contents are derived from [Azure IoT Gateway SDK](http://github.com/azure/azure-iot-gateway-sdk) and [Boost Software License](http://www.boost.org/users/license.html) so that the license follows the license of the site. 
All contents are as-is. I'll not gurantee anything so please use this at your own risk. 
Directory structure

/samples

udp_gateway - Send data to IoTHub from a gateway using a simulated devie which uses UDP instead of using a real device.    

/modules

/udp
This folder contains sending and receiving modules that are using UPD protocol.

/udp_generator
This folder contains udp_packet_generator module that uses in the above modules. 


