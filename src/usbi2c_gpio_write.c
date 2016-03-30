#include <stdio.h>
#include "usbi2c/usbi2c.h"

int usbi2c_gpio_write( int usb_handle, uint8_t data ) {

	unsigned char msg[3] = { 'O', data, 'P' } ;

	if ( usbi2c_raw_write( usb_handle, msg, 3 ) != 3 ) {
		fprintf(stderr,"[usbi2c_write_gpio] Error : could not send message\n") ;
		return -1 ;
	}
	
	return 0 ;
}
