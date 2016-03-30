#include <unistd.h>

#include "usbi2c/usbi2c.h"

ssize_t usbi2c_raw_write ( int usb_handle, uint8_t* msg, size_t bytes ) {

	return write( usb_handle, msg, bytes );

}
