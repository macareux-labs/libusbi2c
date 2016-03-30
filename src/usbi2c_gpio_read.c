#include <stdio.h>
#include "usbi2c/usbi2c.h"

uint8_t usbi2c_gpio_read ( int usb_handle ) {

	unsigned char msg[2] = { 'I', 'P' } ;

	if ( usbi2c_raw_write( usb_handle, msg, 2 ) != 2 ) {
		fprintf(stderr,"[usbi2c_read_gpio] Error : could not write\n") ;
		return 0x00 ;
	}
	
	if ( usbi2c_raw_read( usb_handle, msg, 1 ) != 1) {
		fprintf(stderr,"[usbi2c_read_gpio] Error : could not read\n") ;
		return 0x00 ;
	}

	return msg[0] ;
}
