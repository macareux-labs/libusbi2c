#include <stdio.h>
#include "usbi2c/usbi2c.h"

ssize_t usbi2c_read  ( int usb_handle, uint8_t addr, uint8_t* msg, uint8_t bytes ) {

	uint8_t buffer[4] = { 'S', 0x00, 0x00, 'P' } ;
	buffer[1] = ( addr << 1 ) | 0x01 ;	
	buffer[2] = (uint8_t) bytes ;	

	if ( usbi2c_raw_write( usb_handle, buffer, 4 ) < 4 ) {

		fprintf(stderr, "[usbi2c_read] ERROR while writing request\n" ) ;
		return -1 ;
	}

	return usbi2c_raw_read( usb_handle, msg, (size_t) bytes ) ;
}
