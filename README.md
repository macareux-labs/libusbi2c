# libusbi2c

This library was developped as an example on how to use the usbi2c module (http://www.macareux-labs.com) to communicate with 
an I2C device from your own project.

## Installation

### Dependencies

Plug you usbi2c in your computer and type dmesg as root.

You should see a line saying :

	cp210x converter now attached to ttyUSB0

( or any other dev node )

If not, please make sure that the cp210x kernel module is installed and loaded

### Getting the sources

The sources are available on github: https://github.com/macareux-labs/libusbi2c
You can retrieve them as a zip file with your favorite web browser or,better, just use git :

	git clone https://github.com/macareux-labs/libusbi2c.git

### Compiling and installing

Enter the 'build' directory :

	$ cd build

Run CMake, pointing it to the parent directory (where CMakeLists.txt is located)

	$ cmake ..

Now run the make command to build the library and executables:

	$ make

Install the library into the system to use

	$ sudo make install


## Using libusbi2c

### Functions

All the functions you'll need are listed inside the file usbi2c.h, and there are
only 12 of them. Let's have a look on them.

#### Opening, Closing and setting the module

	int usbi2c_open( const char* device ) ;
	int usbi2c_close( int usb_handle ) ;

Those two are pretty straightforward : they will allow you to bind/unbind to the module.
Because you can have several usbi2c modules plugged in simultaneously, you must provide 
the dev node (eg. "/dev/ttyUSB0") to the usbi2c\_open function. The value returned is a handle
used in all other functions.

If you want to specify your I2C bus speed, you can do it by calling:

	int usbi2c_set_speed ( int usb_handle, uint16_t I2CSPEED ) ;

Where I2CSPEED can be :

	I2CSPEED_369KHZ
	I2CSPEED_246KHZ	
	I2CSPEED_147KHZ	
	I2CSPEED_123KHZ	
	I2CSPEED_74KHZ	
	I2CSPEED_61KHZ	
	I2CSPEED_37KHZ


If the exact value you need isn't in this list, pick the closest one.

Simple isn't it ?
 

#### Writing


	ssize_t usbi2c_write ( int usb_handle, uint8_t addr, uint8_t* buffer, uint8_t bytes ) ;

Sends a message to an I2C device, where :

- usb\_handle is the handle returned by usbi2c\_open
- addr is the 7 bit address of the I2C device you want to interact with ( Don't add the RW bit, it will be done automagically )
- buffer is the array of bytes you want to write 
- bytes is the size of the message stored in buffer

#### Reading

	ssize_t usbi2c_read  ( int usb_handle, uint8_t addr, uint8_t* buffer, uint8_t bytes ) ;

Receives a message from an I2C device, where :

- usb\_handle is the handle returned by usbi2c\_open
- addr is the 7 bit address of the I2C device you want to interact with ( Don't add the RW bit, it will be done automagically )
- buffer is the array of bytes where the message will be written
- bytes is the size of buffer


#### Repeated Start

Sometimes, you need to perform two operations (write+write or write+read) in an atomic transmission. 
In such situations, you can use the two following fuctions:

	ssize_t usbi2c_writeread  ( int usb_handle, uint8_t addr, uint8_t* buffer, uint8_t wbytes, uint8_t rbytes ) ;
	ssize_t usbi2c_writewrite ( int usb_handle, uint8_t addr, uint8_t* buffer1, uint8_t bytes1, uint8_t* buffer2, uint8_t bytes2 ) ;

#### GPIOs ?

Yes, Gpios !!! you always need more then you have :)
The 8 gpio lines of the SC18IM700 can be set with the usbi2c\_gpio\_set\_mode function :

	int usbi2c_gpio_setmode ( int usb_handle, uint16_t GPIOMODE ) ;

For you convenience, defines have been written so you can just set the GPIOMODE with an OR expression :

	GPIO0_QUASIBIDIR     Sets GPIO0 to Quasibidir mode	
	GPIO0_INPUT          Sets GPIO0 to Input mode
	GPIO0_PUSHPULL       Sets GPIO0 to PushPull mode
	GPIO0_OPENDRAIN      Sets GPIO0 to Open Drain mode
	...
	GPIO_ALL_QUASIBIDIR  Sets all GPIOs to Quasibidir mode
	GPIO_ALL_INPUT       Sets all GPIOs to Input mode
	GPIO_ALL_PUSHPULL    Sets all GPIOs to PushPull mode
	GPIO_ALL_OPENDRAIN   Sets all GPIOs to Open Drain mode


### Example


	#include <usbi2c.h>

	int main ( int argc, char** argv ) {

		int handle ;
		uint8_t buffer[5]={'H', 'E', 'L', 'L', 'O' } ;

		handle = usbi2c_open( "/dev/ttyUSB0" ) ;
		
		usbi2c_write ( handle, 0x80, buffer, 5 ) ;

		usbi2c_close( handle ) ;
		
		return 0 ;

	}






