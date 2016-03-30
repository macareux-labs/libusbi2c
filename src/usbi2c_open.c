#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <termios.h>
#include <unistd.h>

#include "usbi2c/usbi2c.h"

int usbi2c_open( const char* device ) {

    int handle ;
    struct termios tty ;

    handle = open(device, O_RDWR | O_NOCTTY);
    if (handle < 0) {
		fprintf(stderr, "Error %d opening %s : %s\n", errno, device, strerror(errno) ) ;
		return handle ;
    }

   // Initialize device with 115200bauds 8N1

    memset(&tty, 0, sizeof tty);

    if (tcgetattr(handle, &tty) != 0) {
		fprintf(stderr, "Error %d from tcgetattr : %s \n", errno, strerror(errno) ) ;
		close(handle) ;
		return -1 ;
    }

    cfsetospeed(&tty, B115200 );
    cfsetispeed(&tty, B115200 );

    tty.c_cflag &= ~PARENB;				// Format : 8N1
    tty.c_cflag &= ~CSTOPB;
    tty.c_cflag &= ~CSIZE;
    tty.c_cflag |= CS8;
    tty.c_cflag &= ~CRTSCTS;				// no flow control ( RTS/CTS )
    tty.c_lflag = 0;					// no signalling chars, no echo, no canonical processing
    tty.c_oflag = 0;					// no remapping, no delays
    tty.c_cc[VMIN] = 0;					// read doesn't block
    tty.c_cc[VTIME] = 5;				// 0.5 seconds read timeout
    tty.c_cflag |= CREAD | CLOCAL;			// turn on READ & ignore ctrl lines
    tty.c_iflag &= ~(IXON | IXOFF | IXANY);		// turn off s/w flow ctrl
    tty.c_lflag &= ~(ICANON | ECHO | ECHOE | ISIG);	// make raw
    tty.c_oflag &= ~OPOST;				// make raw

    tcflush(handle, TCIFLUSH);

    if (tcsetattr(handle, TCSANOW, &tty) != 0) {
		fprintf(stderr, "Error %d from tcsetattr : %s \n", errno, strerror(errno) ) ;
		close(handle) ;
		return -1 ;
    }
   
    // Check if SC18IM700 is set to 155200 bauds, and sets it if needed
    
    char msg_R[4] = { 'R', BRG0, BRG1, 'P' } ;
    
    usbi2c_raw_write( handle, msg_R, 4 ) ;
    usbi2c_raw_read ( handle, msg_R, 4 ) ;

    if ( (msg_R[0] != 0x30) || (msg_R[1] != 0x00) ) {

	cfsetospeed(&tty, B9600 );
	cfsetispeed(&tty, B9600 );

        if (tcsetattr(handle, TCSANOW, &tty) != 0) {
		fprintf(stderr, "Error %d from tcsetattr : %s \n", errno, strerror(errno) ) ;
		close(handle) ;
		return -1 ;
	}

    	char msg[6] = { 'W', BRG0, 0x30, BRG1, 0x00, 'P' } ;
    	usbi2c_raw_write( handle, msg, 6 ) ;

    	usleep( 500000 ) ;	// 

	cfsetospeed(&tty, B115200 );
	cfsetispeed(&tty, B115200 );

        if (tcsetattr(handle, TCSANOW, &tty) != 0) {
		fprintf(stderr, "Error %d from tcsetattr : %s \n", errno, strerror(errno) ) ;
		close(handle) ;
		return -1 ;
	}

    }

    return handle ;

}

