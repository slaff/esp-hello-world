#include "ets_sys.h"
#include "osapi.h"
#include "os_type.h"
#include "user_config.h"
 
void user_init()
{
    // This is used to setup the serial communication
    uart_div_modify(0, UART_CLK_FREQ / 115200);

    // And this is used to print some information
    os_printf("Hello, world!\n");
}
