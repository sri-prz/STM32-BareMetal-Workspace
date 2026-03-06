#include "esp32.h"



void esp32_read (uint8_t address, uint8_t * rxdata)
{

	uint8_t data[3] = {0,0,0};

	//pull cs line low to enable slave
	cs_enable();

	//send address
	spi1_transmit(data,3);
	for(int i = 0; i < 10000000;i++)
	//read 3 bytes
	spi1_receive(rxdata,3);
	//pull cs line high to disable slave
	cs_disable();



}

void esp32_write(uint8_t address, uint8_t value)
{
	uint8_t data[2];



	//pull cs line low to enable slave
	cs_enable();

	//transmit data and address
	spi1_transmit(data,2);

	//pull cs line high to disable slave
	cs_disable();

}

void esp32_init(void){
	//enable spi gpio module
	spi_gpio_init();
	//configure SPI1 router
	spi1_config();
}

