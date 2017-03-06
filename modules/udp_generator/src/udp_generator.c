#include <stdlib.h>
#include <unistd.h>
#include "udp_generator.h"

#include "azure_c_shared_utility/threadapi.h"
#include "azure_c_shared_utility/xlogging.h"
#include "azure_c_shared_utility/crt_abstractions.h"
#include "messageproperties.h"
#include "message.h"
#include "module.h"	
#include <parson.h>


#define BUFFER_LENGTH 2048

typedef struct GENERATORDEVICE_TAG
{
    BROKER_HANDLE       broker;
    THREAD_HANDLE       udp_generatorThread;
    unsigned int        udp_generatorRunning : 1;
} GENERATORDEVICE;

int send_udp(char*);

int udp_generator(void) {
    int temperature;
    char buff_s[BUFFER_LENGTH];
    temperature = 10;
    while(1) {
       sprintf(buff_s, "%d", temperature++);
    	send_udp(buff_s);
    	sleep(5);
 	}
 return(0);
}

static void udp_generator_Destroy(MODULE_HANDLE moduleHandle)
{
    if (moduleHandle == NULL)
    {
        LogError("Attempt to destroy NULL module");
    }
    else
    {
        GENERATORDEVICE* module_data = (GENERATORDEVICE*)moduleHandle;
        int result;

        /* Tell thread to stop */
        module_data->udp_generatorRunning = 0;
        /* join the thread */
        ThreadAPI_Join(module_data->udp_generatorThread, &result);
        /* free module data */
        free(module_data);
    }
}
static void udp_generator_Receive(MODULE_HANDLE moduleHandle, MESSAGE_HANDLE messageHandle)
{
    // Print the properties & content of the received message
    CONSTMAP_HANDLE properties = Message_GetProperties(messageHandle);
    if (properties != NULL)
    {
        const char* const * keys;
         const char* const * values;
         size_t count;

         if (ConstMap_GetInternals(properties, &keys, &values, &count) == CONSTMAP_OK)
         {
            const CONSTBUFFER* content = Message_GetContent(messageHandle);
             if (content != NULL)
             {
                (void)printf(
                "Received a message\r\n"
                "Properties:\r\n"
                 );

                for (size_t i = 0; i < count; ++i)
                {
                    (void)printf("  %s = %s\r\n", keys[i], values[i]);
                }

                (void)printf("Content:\r\n");
                (void)printf("  %.*s\r\n", (int)content->size, content->buffer);
                (void)fflush(stdout);
              }
         }
        ConstMap_Destroy(properties);
    }
    return;
}
static void udp_generator_Start(MODULE_HANDLE moduleHandle)
{
    if (moduleHandle == NULL)
    {
        LogError("Attempt to start NULL module");
    }
    else
    {
        GENERATORDEVICE* module_data = (GENERATORDEVICE*)moduleHandle;
        /* OK to start */
        /* Create a udp data generator thread.  */
        if (ThreadAPI_Create(
            &(module_data->udp_generatorThread),
            udp_generator,
            (void*)module_data) != THREADAPI_OK)
        {
            LogError("ThreadAPI_Create failed");
            module_data->udp_generatorThread = NULL;
        }
        else
        {
            /* Thread started, module created, all complete.*/
        }
    }
}

static MODULE_HANDLE udp_generator_Create(BROKER_HANDLE broker, const void* configuration)
{	
    GENERATORDEVICE * result;
    if(broker == NULL)
    {
        LogError("NULL parameter detected broker=%p", broker);
        result = NULL;
    }
    else
    {
        /* allocate module data struct */
        result = (GENERATORDEVICE*)malloc(sizeof(GENERATORDEVICE));
        if (result == NULL)
        {
            LogError("couldn't allocate memory for BLE Module");
        }
        else
        {
	        result = (GENERATORDEVICE*)malloc(sizeof(GENERATORDEVICE));
    	    if (result == NULL)
       	 	{
            	/*Codes_SRS_BLE_CTOD_13_002: [ BLE_C2D_Create shall return NULL if any of the underlying platform calls fail. ]*/
            	LogError("malloc failed");
        	}
        	else
        	{
            	result->broker = broker;
        	}
            	result->udp_generatorRunning = 1;
             	result->udp_generatorThread = NULL;

            }

     }
    return result;
}


static void * udp_generator_ParseConfigurationFromJson(const char* configuration)
{
    return NULL;
}

void udp_generator_FreeConfiguration(void * configuration)
{
	return;
}
/*
 *    Required for all modules:  the public API and the designated implementation functions.
 */
static const MODULE_API_1 udp_generator_APIS_all =
{
    {MODULE_API_VERSION_1},
    udp_generator_ParseConfigurationFromJson,
	udp_generator_FreeConfiguration,
    udp_generator_Create,
    udp_generator_Destroy,
    udp_generator_Receive,
    udp_generator_Start
};

#ifdef BUILD_MODULE_TYPE_STATIC
MODULE_EXPORT const MODULE_API* MODULE_STATIC_GETAPI(GENERATOR_DEVICE_MODULE)(MODULE_API_VERSION gateway_api_version)
#else
MODULE_EXPORT const MODULE_API* Module_GetApi(MODULE_API_VERSION gateway_api_version)
#endif
{
    (void)gateway_api_version;
    return (const MODULE_API *)&udp_generator_APIS_all;
}

