#ifndef SC18IM700_H
#define SC18IM700_H

// I2C bus speeds

#define I2CSPEED_369KHZ		0x0505
#define I2CSPEED_246KHZ		0x0807
#define I2CSPEED_147KHZ		0x0D0C
#define I2CSPEED_123KHZ		0x0F0F
#define I2CSPEED_74KHZ		0x1919
#define I2CSPEED_61KHZ		0x1E1E
#define I2CSPEED_37KHZ		0x3232

// Status

#define I2C_OK			0xF0
#define I2C_NACK_ON_ADDRESS	0xF1
#define I2C_NACK_ON_DATA	0xF2
#define I2C_TIME_OUT		0xF8

// GPIO configs

#define GPIO0_QUASIBIDIR	0x0000
#define GPIO0_INPUT		0x0001
#define GPIO0_PUSHPULL		0x0002
#define GPIO0_OPENDRAIN		0x0003
#define GPIO1_QUASIBIDIR	0x0000
#define GPIO1_INPUT		0x0004
#define GPIO1_PUSHPULL		0x0008
#define GPIO1_OPENDRAIN		0x000C
#define GPIO2_QUASIBIDIR	0x0000
#define GPIO2_INPUT		0x0010
#define GPIO2_PUSHPULL		0x0020
#define GPIO2_OPENDRAIN		0x0030
#define GPIO3_QUASIBIDIR	0x0000
#define GPIO3_INPUT		0x0040
#define GPIO3_PUSHPULL		0x0080
#define GPIO3_OPENDRAIN		0x00C0
#define GPIO4_QUASIBIDIR	0x0000
#define GPIO4_INPUT		0x0100
#define GPIO4_PUSHPULL		0x0200
#define GPIO4_OPENDRAIN		0x0300
#define GPIO5_QUASIBIDIR	0x0000
#define GPIO5_INPUT		0x0400
#define GPIO5_PUSHPULL		0x0800
#define GPIO5_OPENDRAIN		0x0C00
#define GPIO6_QUASIBIDIR	0x0000
#define GPIO6_INPUT		0x1000
#define GPIO6_PUSHPULL		0x2000
#define GPIO6_OPENDRAIN		0x3000
#define GPIO7_QUASIBIDIR	0x0000
#define GPIO7_INPUT		0x4000
#define GPIO7_PUSHPULL		0x8000
#define GPIO7_OPENDRAIN		0xC000

#define GPIO_ALL_QUASIBIDIR	0x0000
#define GPIO_ALL_INPUT		0x5555
#define GPIO_ALL_PUSHPULL	0xAAAA
#define GPIO_ALL_OPENDRAIN	0xFFFF

// SC19IM700 Registers

#define BRG0			0x00
#define BRG1			0x01
#define PortConf1		0x02
#define PortConf2		0x03
#define IOState			0x04
#define I2CAdr			0x06
#define I2CClkL			0x07
#define I2CClkH			0x08
#define I2CTO			0x09
#define I2CStat			0x0A

#endif