#include <string.h>
#include <unistd.h>

#include "usbi2c/usbi2c.h"


ssize_t usbi2c_writewrite ( int usb_handle, uint8_t addr, 
				uint8_t* msg1, uint8_t bytes1, 
				uint8_t* msg2, uint8_t bytes2 ) 
{
	uint8_t buffer[BUFFER_SIZE] ;
	uint8_t w_addr = ( addr << 1 ) ;
	int count = 0 ;

	buffer[count++] = 'S' ;
	buffer[count++] = w_addr ;
	buffer[count++] = bytes1 ; 
	memcpy(buffer+count, msg1, (size_t) bytes1 ) ;
	count+=bytes1 ;
	buffer[count++] = 'S' ;
	buffer[count++] = w_addr ;
	buffer[count++] = bytes2 ;
	memcpy(buffer+count, msg2, (size_t) bytes2 ) ;
	count += bytes2 ;
	buffer[count++] = 'P' ;

	return usbi2c_raw_write( usb_handle, buffer, (size_t) (count) ) ;

}
