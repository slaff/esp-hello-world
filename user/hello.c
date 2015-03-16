#include "ets_sys.h"
#include "osapi.h"
#include "os_type.h"
#include "user_config.h"
 
void start(void)
{
	// And this is used to print some information once the device is initialized
	os_printf("Hello, world!\n");
}

/*
 * user_init should be used mainly for initialization
 */
void user_init()
{
    // This is used to setup the serial communication
    uart_div_modify(0, UART_CLK_FREQ / 115200);

    // once the initialization is done we can start with our code
    system_init_done_cb(start);
}
