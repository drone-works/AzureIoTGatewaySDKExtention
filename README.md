# UDP Sample Extension of Azure IoT Gateway SDK
This sample is extension of [Azure IoT Gateway SDK](http://github.com/azure/azure-iot-gateway-sdk) Please see [sample discription](samples/udp_gateway/src/README.md).
You can use simulated device that is using UDP and send temperature data to Azure IoT Hub. 

## License 
All contents are derived from [Azure IoT Gateway SDK](http://github.com/azure/azure-iot-gateway-sdk) and [Boost Software License](http://www.boost.org/users/license.html) so that the license follows the license of the site. 
All contents are as-is. I'll not gurantee anything so please use this at your own risk. 

## Prepare your hardware
This tutorial assumes you are using the [Libboost](http://www.boost.org/). 


### Install Libboost 
The UDP modules use asio objects which are involved Libboost.
You need version 1.54 of Libboost for the modules to work correctly. 
These instructions make sure that the correct version of Libboost is installed.

    sudo apt-get update
    sudo apt-get install libboost-all-dev
