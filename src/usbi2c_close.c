#include <unistd.h>

#include "usbi2c/usbi2c.h"


int usbi2c_close( int USB ) {

	return close(USB);

}
