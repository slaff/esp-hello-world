#include "ets_sys.h"
#include "osapi.h"
#include "os_type.h"
#include "user_config.h"

//Main Timer
static volatile os_timer_t main_timer;

void loop(void *arg) {
	os_prinf(".");
}

void start(void) {
	// And this is used to print some information once the device is initialized
	os_printf("Hello, world!\n");

	//Disarm timer
	os_timer_disarm(&main_timer);

	//Setup timer
	os_timer_setfn(&main_timer, (os_timer_func_t *) loop, NULL);

	//Arm the timer
	//&main_timer is the pointer
	//1000 is the fire time in ms
	//0 for once and 1 for repeating
	os_timer_arm(&main_timer, 1000, 1);
}

/*
 * user_init should be used mainly for initialization
 */
void user_init() {
	// This is used to setup the serial communication
	uart_div_modify(0, UART_CLK_FREQ / 115200);

	// once the initialization is done we can start with our code
	system_init_done_cb(start);
}
