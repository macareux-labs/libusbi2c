#ifndef USBI2C_H
#define USBI2C_H

#include <stdint.h>
#include <unistd.h>

#include <usbi2c/SC18IM700.h>
#include <usbi2c/config.h>

int usbi2c_open( const char* device ) ;
int usbi2c_close( int usb_handle ) ;

int usbi2c_set_speed ( int usb_handle, uint16_t I2CSPEED ) ;

ssize_t usbi2c_write ( int usb_handle, uint8_t addr, uint8_t* buffer, uint8_t bytes ) ;
ssize_t usbi2c_read  ( int usb_handle, uint8_t addr, uint8_t* buffer, uint8_t bytes ) ;

ssize_t usbi2c_writeread  ( int usb_handle, uint8_t addr, 
				uint8_t* buffer, uint8_t wbytes, uint8_t rbytes ) ;

ssize_t usbi2c_writewrite ( int usb_handle, uint8_t addr, 
				uint8_t* buffer1, uint8_t bytes1, 
				uint8_t* buffer2, uint8_t bytes2 ) ;


int usbi2c_gpio_setmode ( int usb_handle, uint16_t GPIOMODE ) ;
uint8_t usbi2c_gpio_read ( int usb_handle ) ;
int usbi2c_gpio_write ( int usb_handle, uint8_t data ) ;


ssize_t usbi2c_raw_write ( int usb_handle, uint8_t* msg, size_t bytes ) ;
ssize_t usbi2c_raw_read  ( int usb_handle, uint8_t* msg, size_t bytes ) ;

#endif
