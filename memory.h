/*

 Copyright (c) 2015 Douglas J. Bakkum

 Permission is hereby granted, free of charge, to any person obtaining
 a copy of this software and associated documentation files (the "Software"),
 to deal in the Software without restriction, including without limitation
 the rights to use, copy, modify, merge, publish, distribute, sublicense,
 and/or sell copies of the Software, and to permit persons to whom the
 Software is furnished to do so, subject to the following conditions:

 The above copyright notice and this permission notice shall be included
 in all copies or substantial portions of the Software.

 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
 OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
 THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES
 OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
 ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
 OTHER DEALINGS IN THE SOFTWARE.

*/



#ifndef _MEMORY_H_
#define _MEMORY_H_

#include <stdint.h>

#define MEM_PAGE_LEN                32
#define MEM_AESKEY_LEN_MIN			10
#define MEM_ERASED_LEN   			1
#define MEM_LED_LEN 				1
#define MEM_TOUCH_THRESH_LEN   		2
#define MEM_TOUCH_TIMEOUT_LEN  		2
#define MEM_TOUCH_ENABLE_LEN    	1
#define MEM_SETUP_LEN       		1
#define MEM_DELAY_LEN       		2

// User Zones: 0x0000 to 0x0FFF
#define MEM_NAME_ADDR   			0x0000// Zone 0
#define MEM_LED_ADDR			    0x0020
#define MEM_TOUCH_TIMEOUT_ADDR	   	0x0022
#define MEM_TOUCH_THRESH_ADDR	    0x0024
#define MEM_TOUCH_ENABLE_ADDR   	0x0026
#define MEM_ERASED_ADDR 	    	0x0028
#define MEM_SETUP_ADDR      		0x0030
#define MEM_DELAY_ADDR      		0x0032
#define MEM_AESKEY_ADDR				0x0040

#define MEM_MASTER_ELECTRUM_ADDR	0x0100// Zone 1
#define MEM_MNEMONIC_ELECTRUM_ADDR	0x0120

#define MEM_MASTER_BIP32_ADDR		0x0200// Zone 2
#define MEM_MASTER_BIP32_CHAIN_ADDR	0x0220
#define MEM_MNEMONIC_BIP32_ADDR_0	0x0240
#define MEM_MNEMONIC_BIP32_ADDR_1	0x0260

// Default settings
#define DEFAULT_erased_             0xFF
#define DEFAULT_setup_              0xFF
#define DEFAULT_led_                0
#define DEFAULT_touch_timeout_      4000
#define DEFAULT_touch_thresh_       100
#define DEFAULT_touch_enable_       1


void memory_erase(void);
void memory_setup(void);
void memory_fill_variables(void);
void memory_clear_variables(void);

int memory_aeskey_write(const char *password, int len);
uint8_t *memory_aeskey_read(void);
uint8_t *memory_name(const char *name);
uint8_t *memory_bip32_master(const uint8_t *master_priv_key);
uint8_t *memory_bip32_chaincode(const uint8_t *chain_code);
uint16_t *memory_bip32_mnemonic(const uint16_t *index);
uint8_t *memory_electrum_master(const uint8_t *master_priv_key);
char *memory_electrum_mnemonic(const char *seed_hex);

uint16_t memory_delay_read(void);
uint16_t memory_touch_timeout_read(void);
uint16_t memory_touch_thresh_read(void);
uint8_t memory_touch_enable_read(void);
uint8_t memory_erased_read(void);
uint8_t memory_setup_read(void);
int memory_led_read(void);

void memory_delay_iterate(const uint16_t d);
void memory_touch_timeout_write(const uint16_t t);
void memory_touch_thresh_write(const uint16_t t);
void memory_touch_enable_write(const uint8_t e);
void memory_erased_write(const uint8_t erase);
void memory_setup_write(const uint8_t setup);
void memory_led_write(const uint8_t led);

#endif  // _MEMORY_H_
