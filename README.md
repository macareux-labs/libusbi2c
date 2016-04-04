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


