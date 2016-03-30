#include <string.h>
#include <stdio.h>
#include <unistd.h>

#include "usbi2c/usbi2c.h"

ssize_t usbi2c_raw_read  ( int usb_handle, uint8_t* msg, size_t bytes ) {


	unsigned char buf = '\0';
	ssize_t n ;
	ssize_t spot ;

	memset(msg, '\0', bytes );
	
	spot=0 ;
	do {
		  n = read( usb_handle, &buf, 1 );
		  sprintf( &msg[spot], "%c", buf );
		  spot += n;

	} while( (buf != '\r') && ( n > 0 ) && ( spot < bytes ) );

	return spot;
}

