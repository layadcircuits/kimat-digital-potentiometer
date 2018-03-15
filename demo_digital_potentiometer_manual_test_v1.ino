/***************************************************************************
 Description: A demonstration of how to adjust the resistance of the Kimat Digital Potentiometer Breakout
 Connections: https://github.com/layadcircuits/kimat-digital-potentiometer/blob/master/kimat%20digipot%20wiring%20v1.png

 This software is free provided that this notice is not removed and proper attribution 
 is accorded to Layad Circuits and its Author(s).
 Layad Circuits invests resources in producing free software. By purchasing Layad Circuits'
 products or utilizing its services, you support the continuing development of free software
 for all.
  
 Author(s): M.J.Padua for Layad Circuits Electronics Engineering
 Revision: 1.0 - 2018/03/08 - initial creation
 Layad Circuits Electronics Engineering Supplies and Services
 B314 Lopez Bldg., Session Rd. cor. Assumption Rd., Baguio City, Philippines
 www.facebook.com/layadcircuits
 www.layadcircuits.com
 general: info@layadcircuits.com
 sales: sales@layadcircuits.com
 mobile: +63-916-442-8565
 ***************************************************************************/
#include <SPI.h>

byte address = 0x00;
int CS= 10;//53 for Mega

int val; // this is the step value. vary this between 0 and 128 to adjust the resistance

 int digitalPotWrite(int value)
{
  digitalWrite(CS, LOW);
  SPI.transfer(address);
  SPI.transfer(value);
  digitalWrite(CS, HIGH);
}

void setup()
{
  Serial.begin(115200);
  pinMode (CS, OUTPUT);
  SPI.begin();
}

void loop()
{
    digitalPotWrite(val);
    delay(100);
}




