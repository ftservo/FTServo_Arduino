#include <SCServo.h>

HLSCL hlscl;

void setup()
{
  //Serial1.begin(1000000, SERIAL_8N1, 18, 17);//esp32-s3
  Serial1.begin(1000000);//mega2560
  hlscl.pSerial = &Serial1;
  delay(1000);
  hlscl.EleMode(1);//舵机ID1切换至电机恒力模式
}

void loop()
{
  //舵机(ID1)以最大扭矩电流T=300*6.5=1950mA，正向旋转
  hlscl.WriteEle(1, 300);
  delay(5000);
  
  //舵机(ID1/ID2)以扭矩0停止旋转
  hlscl.WriteEle(1, 0);
  delay(2000);
  
  //舵机(ID1)以最大扭矩电流T=300*6.5=1950mA，反向旋转
  hlscl.WriteEle(1, -300);
  delay(5000);
  
  //舵机(ID1)以扭矩0停止旋转
  hlscl.WriteEle(1, 0);
  delay(2000);
}
