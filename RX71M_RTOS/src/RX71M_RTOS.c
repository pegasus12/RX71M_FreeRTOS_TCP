/***********************************************************************
*
*  FILE        : RX71M_RTOS.c
*  DATE        : 2020-04-11
*  DESCRIPTION : Main Program
*
*  NOTE:THIS IS A TYPICAL EXAMPLE.
*
***********************************************************************/
#include "FreeRTOS.h"
#include "task.h"

/* FreeRTOS+TCP includes. */
#include "FreeRTOS_IP.h"
#include "FreeRTOS_Sockets.h"

/* Use of a "define" and not a "static const" here to be able to
* use pre-compile concatenation on the string. */
#define clientcredentialIOT_THING_NAME "FAMAX_PLC"

#define mainECHO_CLIENT_TASK_STACK_SIZE 				( configMINIMAL_STACK_SIZE * 2 )	/* Not used in the Windows port. */
#define mainECHO_CLIENT_TASK_PRIORITY					( tskIDLE_PRIORITY + 1 )

/* The MAC address array is not declared const as the MAC address will
normally be read from an EEPROM and not hard coded (in real deployed
applications).*/
static uint8_t ucMACAddress[ 6 ] =
{
    configMAC_ADDR0,
    configMAC_ADDR1,
    configMAC_ADDR2,
    configMAC_ADDR3,
    configMAC_ADDR4,
    configMAC_ADDR5
}; //XXX

/* Define the network addressing.  These parameters will be used if either
ipconfigUDE_DHCP is 0 or if ipconfigUSE_DHCP is 1 but DHCP auto configuration
failed. */
static const uint8_t ucIPAddress[ 4 ] =
{
    configIP_ADDR0,
    configIP_ADDR1,
    configIP_ADDR2,
    configIP_ADDR3
};
static const uint8_t ucNetMask[ 4 ] =
{
    configNET_MASK0,
    configNET_MASK1,
    configNET_MASK2,
    configNET_MASK3
};
static const uint8_t ucGatewayAddress[ 4 ] =
{
    configGATEWAY_ADDR0,
    configGATEWAY_ADDR1,
    configGATEWAY_ADDR2,
    configGATEWAY_ADDR3
};

/* The following is the address of an OpenDNS server. */
static const uint8_t ucDNSServerAddress[ 4 ] =
{
    configDNS_SERVER_ADDR0,
    configDNS_SERVER_ADDR1,
    configDNS_SERVER_ADDR2,
    configDNS_SERVER_ADDR3
};


extern void vStartTCPEchoClientTasks_NcTestTasks( uint16_t usTaskStackSize, UBaseType_t uxTaskPriority );

/* Generate a randomized TCP Initial Sequence Number per RFC. */
uint32_t ulApplicationGetNextSequenceNumber(
    uint32_t ulSourceAddress,
    uint16_t usSourcePort,
    uint32_t ulDestinationAddress,
    uint16_t usDestinationPort );

uint32_t ulRand( void )
{
	/* An unsafe example of a 32-bit random number generator. */
	/* Assuming rand() returns a 15-bit number. */
	uint32_t ulResult =
		((((uint32_t) rand()) & 0x7fffuL)       ) |
		((((uint32_t) rand()) & 0x7fffuL) << 15 ) |
		((((uint32_t) rand()) & 0x0003uL) << 30 );
	return ulResult;
}

/******************************************************************************
* Function Name: vApplicationIPNetworkEventHook
* Description  : This function will be called on each network up/down event.
* Arguments    : eNetworkEvent -
*                    Type of network up/down event
* Return Value : None.
******************************************************************************/
void vApplicationIPNetworkEventHook( eIPCallbackEvent_t eNetworkEvent )
{
    uint32_t ulIPAddress, ulNetMask, ulGatewayAddress, ulDNSServerAddress;
    char cBuffer[ 16 ];

    /* If the network has just come up...*/
    if( eNetworkEvent == eNetworkUp )
    {
        /* Print out the network configuration, which may have come from a DHCP
         * server. */
        FreeRTOS_GetAddressConfiguration(
            &ulIPAddress,
            &ulNetMask,
            &ulGatewayAddress,
            &ulDNSServerAddress );

        FreeRTOS_inet_ntoa( ulIPAddress, cBuffer );
        FreeRTOS_printf( ( "IP Address: %s\n", cBuffer ) );

        FreeRTOS_inet_ntoa( ulNetMask, cBuffer );
        FreeRTOS_printf( ( "Subnet Mask: %s\n", cBuffer ) );

        FreeRTOS_inet_ntoa( ulGatewayAddress, cBuffer );
        FreeRTOS_printf( ( "Gateway Address: %s\n", cBuffer ) );

        FreeRTOS_inet_ntoa( ulDNSServerAddress, cBuffer );
        FreeRTOS_printf( ( "DNS Server Address: %s\n", cBuffer ) );
    }
}


void main_task(void *pvParameters)
{
	//R_BSP_NOP();
	while(1)
	{
		vTaskDelay(10000);
	}
}

static void prvMiscInitialization( void )
{
    /* Initialize UART for serial terminal. */
    //uart_config();

#if (MY_BSP_CFG_OTA_ENABLE == 1)
    usb_init();
#endif /* MY_BSP_CFG_OTA_ENABLE == 1 */

    /* Start logging task. */
    //xLoggingTaskInitialize( mainLOGGING_TASK_STACK_SIZE,
    //                        tskIDLE_PRIORITY,
    //                        mainLOGGING_MESSAGE_QUEUE_LENGTH );
}
/*-----------------------------------------------------------*/

void vApplicationDaemonTaskStartupHook( void )
{
    prvMiscInitialization();

    //if( SYSTEM_Init() == pdPASS )
    //{
        /* Initialise the RTOS's TCP/IP stack.  The tasks that use the network
        are created in the vApplicationIPNetworkEventHook() hook function
        below.  The hook function is called when the network connects. */
        FreeRTOS_IPInit( ucIPAddress,
                         ucNetMask,
                         ucGatewayAddress,
                         ucDNSServerAddress,
                         ucMACAddress );

        /* We should wait for the network to be up before we run any demos. */
        while( FreeRTOS_IsNetworkUp() == pdFALSE )
        {
            vTaskDelay(3000);
        }

        /* Attached to the usb before running the demos */
#if (MY_BSP_CFG_OTA_ENABLE == 1)
        while (0U == usb_attached());
#endif /* MY_BSP_CFG_OTA_ENABLE == 1 */

        /* Provision the device with AWS certificate and private key. */
        //vDevModeKeyProvisioning();


        vStartTCPEchoClientTasks_NcTestTasks( mainECHO_CLIENT_TASK_STACK_SIZE, mainECHO_CLIENT_TASK_PRIORITY );
        /* Run all demos. */
        //DEMO_RUNNER_RunDemos();
    //}
}
/*-----------------------------------------------------------*/

const char * pcApplicationHostnameHook( void )
{
    /* Assign the name "FreeRTOS" to this network node.  This function will
     * be called during the DHCP: the machine will be registered with an IP
     * address plus this name. */
    return clientcredentialIOT_THING_NAME;
}
/*-----------------------------------------------------------*/

/**
 * @brief Generate a TCP Initial Sequence Number that is reasonably difficult
 * to predict, per https://tools.ietf.org/html/rfc6528.
 */
uint32_t ulApplicationGetNextSequenceNumber( uint32_t ulSourceAddress,
                                             uint16_t usSourcePort,
                                             uint32_t ulDestinationAddress,
                                             uint16_t usDestinationPort )
{
	( void ) ulSourceAddress;
	( void ) usSourcePort;
	( void ) ulDestinationAddress;
	( void ) usDestinationPort;

	return ulRand();
}
/*-----------------------------------------------------------*/

BaseType_t xApplicationGetRandomNumber( uint32_t *pulNumber )
{
	( void ) pulNumber;

	return ulRand();
}