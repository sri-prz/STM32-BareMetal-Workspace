#ifndef ESP32_H_
#define ESP32_H_

#include "spi.h"
#include <stdint.h>

void esp32_init (void);
void esp32_read(uint8_t address, uint8_t * rxdata);
void esp32_write(uint8_t address, uint8_t value);


#endif /* ESP32_H_ */
