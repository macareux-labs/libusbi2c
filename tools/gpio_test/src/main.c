#include <stdio.h>
#include <usbi2c/usbi2c.h>

int main ( int argc, char** argv, char** envv ) {

	int usb ;
	int ret ;
	int i ;

	usb = usbi2c_open("/dev/ttyUSB0") ;

	usbi2c_gpio_setmode( usb, GPIO_ALL_INPUT  ) ;

	while(1) {
		unsigned char tmp ;
		tmp = usbi2c_gpio_read( usb ) ;
		printf("0x%02x\r",tmp) ;
	}

	usbi2c_close(usb) ;

	return 0 ;
}
