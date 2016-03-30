#include <stdio.h>
#include "usbi2c/usbi2c.h"

int usbi2c_gpio_setmode ( int usb_handle, uint16_t GPIOMODE ) {

	unsigned char* tmp ;
	unsigned char msg[6] = { 'W', PortConf2, 0x00, PortConf1, 0x00 ,'P' } ;

	tmp = (unsigned char*) &GPIOMODE ;

	msg[2] = tmp[0] ;
	msg[4] = tmp[1] ;

	if ( usbi2c_raw_write( usb_handle, msg, 6 ) != 6 ) {
		fprintf(stderr,"[usbi2c_set_gpiomode] Error : could not send message\n") ;
		return -1 ;
	}
	
	return 0 ;
}
