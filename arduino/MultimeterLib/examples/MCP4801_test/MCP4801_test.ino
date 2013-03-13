/*
  MCP4801_test.ino - Arduino Library Example sketch for the Microchip MCP4801 
                     8-Bit Voltage Output Digital-to-Analog Converter
                     with Internal VREF and SPI Interface.
  Created by Craig Wm. Versek, 2012-05-13
  Released into the public domain.
*/

#include <SPI.h>
#include <MCP4801.h>

#define V_MIN 0.0
#define V_MAX 3.0
#define NUM_STEPS 30
#define DELAY_ms 2000

//configure the DAC chip
MCP4801Class voltageDAC(9,  //slaveSelectLowPin
                        8,  //ldacLowPin
                        10  //shutdownLowPin
                       );


void setup() {
  //start up the SPI bus                   
  SPI.begin();
  SPI.setBitOrder(MSBFIRST);
  SPI.setDataMode(SPI_MODE0);
  //start controlling the voltage supply
  voltageDAC.begin();
}

void loop() {
  float voltage_step = (V_MAX - V_MIN)/NUM_STEPS;
  float voltage = V_MIN; 
  for (int i=0; i < NUM_STEPS; i++){
    voltage = V_MIN + voltage_step*i;
    voltageDAC.setVoltageOutput(voltage);
    delay(DELAY_ms);
  }  
}
