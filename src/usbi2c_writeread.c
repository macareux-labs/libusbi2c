#include <unistd.h> 
#include <string.h>
#include <stdio.h>
#include "usbi2c/usbi2c.h"

ssize_t usbi2c_writeread  ( int usb_handle, uint8_t addr, 
				uint8_t* data, uint8_t wbytes, uint8_t rbytes ) 
{

	uint8_t buffer[BUFFER_SIZE] ;
	uint8_t w_addr = ( addr << 1 ) ;
	uint8_t r_addr = w_addr | 0x01 ;
	int count = 0 ;

	buffer[count++] = 'S' ;
	buffer[count++] = w_addr ;
	buffer[count++] = wbytes ; 
	memcpy(buffer+count, data, (size_t) wbytes ) ;
	count+=wbytes ;
	buffer[count++] = 'S' ;
	buffer[count++] = r_addr ;
	buffer[count++] = rbytes ;
	buffer[count++] = 'P' ;


	if ( usbi2c_raw_write( usb_handle, buffer, count ) < count ) {

		fprintf(stderr, "[usbi2c_writeread] ERROR while writing request\n" ) ;
		return -1 ;
	}

	return usbi2c_raw_read( usb_handle, data, (size_t) rbytes ) ;

}
