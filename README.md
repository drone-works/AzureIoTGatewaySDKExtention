# UDP Sample Extension of Azure IoT Gateway SDK
This sample is extension of [Azure IoT Gateway SDK](http://github.com/azure/azure-iot-gateway-sdk)

## License 
All contents are derived from [Azure IoT Gateway SDK](http://github.com/azure/azure-iot-gateway-sdk) and [Boost Software License](http://www.boost.org/users/license.html) so that the license follows the license of the site. 
All contents are as-is. I'll not gurantee anything so please use this at your own risk. 

Directory structure

/samples

udp_gateway - Send data to IoTHub from a gateway using a simulated devie which uses upd protocol instead of using a real device.    

/modules

This folder contains all of the modules included with the Azure IoT Gateway SDK. Each module represents a specific piece of functionality that can be composed into an end to end gateway solution. Details on the implementation of each module can be found in each module's devdoc/ folder.

/core

This folder contains all of the core infrastructure necessary to create a gateway solution. In general, developers only need to use components in the core folder, not modify them. API documentation for core infrastructure can be found here. Details on the implementation of core components can be found in core/devdoc.

/build

This is the default folder that cmake will place the output from our build scripts. The developer always has the final say about the destinaiton of build output by creating a folder, navigating to it, and then running cmake from there. Detailed instructions are contained in each sample doc.
