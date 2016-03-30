#include <string.h>
#include <unistd.h>

#include "usbi2c/usbi2c.h"

ssize_t usbi2c_write ( int usb_handle, uint8_t addr, uint8_t* msg, uint8_t bytes ) {
	
	uint8_t buffer[BUFFER_SIZE] ;

	buffer[0] = 'S' ;
	buffer[1] = ( addr << 1 ) ;
	buffer[2] = bytes ; 
	memcpy(buffer+3, msg, (size_t) bytes ) ;
	buffer[bytes+3] = 'P' ;
	
//	int i ;
//	for (i=0; i<bytes+4; i++ )
//		printf("-> %x \n", buffer[i] ) ;

	return usbi2c_raw_write( usb_handle, buffer, (size_t) (bytes+4) ) ;

}
