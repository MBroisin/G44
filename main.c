#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <math.h>

//ChibiOS includes
#include <ch.h>
#include <hal.h>
#include <chprintf.h>

//e-puck_main-processor includes
#include <memory_protection.h>
#include <msgbus/messagebus.h>
#include <main.h>
#include <motors.h>
#include <serial_comm.h>

//Local includes 
#include "comm.h"
#include "localization.h"
#include "macros.h"
#include "obstacles.h"
#include <ch.h>
#include <hal.h>
#include <chprintf.h>
#include <memory_protection.h>
#include <usbcfg.h>
#include <main.h>
#include <motors.h>
<<<<<<< Updated upstream
=======
#include <fft.h>
#include <arm_math.h>
#include <sensors/VL53L0X/VL53L0X.h>

#define SEND_FROM_MIC

static void serial_start(void)
{
	static SerialConfig ser_cfg = {
	    115200,
	    0,
	    0,
	    0,
	};

	sdStart(&SD3, &ser_cfg); // UART3.
}

#define STACK_CHK_GUARD 0xe2dee396
uintptr_t __stack_chk_guard = STACK_CHK_GUARD;

void __stack_chk_fail(void)
{
    chSysHalt("Stack smashing detected");
}
====
messagebus_t bus; //declare in main.h, but defined here
MUTEX_DECL(bus_lock);
CONDVAR_DECL(bus_condvar);

int main(void)
{
	//general initialization
	halInit();
	chSysInit();
	mpu_init();

	messagebus_init(&bus, &bus_lock, &bus_condvar);

	serial_start();

	localization_init();
	obstacle_init();
	/* comm_init(); */
	motors_init();

	//Make the main thread sleep

        //inits the motors
   	 motors_init();

   	 //starts the TOF 
   	 VL53L0X_start();


    /* Infinite loop. */
    while (1) {
        //waits 1 second
        chThdSleepMilliseconds(1000);
    }
}

#define STACK_CHK_GUARD 0xe2dee396
uintptr_t __stack_chk_guard = STACK_CHK_GUARD;

void __stack_chk_fail(void)
{
    chSysHalt("Stack smashing detected");
}