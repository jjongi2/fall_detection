#include "Wire.h"
#include <MPU6050_light.h>

MPU6050 mpu(Wire);

void setup(){
  Serial.begin(115200);
  Wire.begin();
  mpu.begin();
  mpu.calcOffsets(true,true);
}

void loop(){
  mpu.update();
  float ax=mpu.getAccX();
  float ay=mpu.getAccY();
  float az=mpu.getAccZ();
  // Serial.print(ax);
  // Serial.print("\t");
  // Serial.print(ay);
  // Serial.print("\t");
  // Serial.println(az);
  
  float svm=sqrt(pow(ax,2)+pow(ay,2)+pow(az,2));
    float a=0.0;
  float b=1.0;
  float T=100.0;
  float dt=0.01;
  float isvm=0.0;

  for(float t=0.0;t<=T;t+=dt){
    float f=svm;
    isvm +=(f+a*(t-dt)+b)*dt/2.0;
  }
  Serial.println("---------------"); 
  Serial.print("isvm ");
  Serial.print("\t");
  Serial.println(isvm);

  float Iz=0.0;
   float a1=0.0;
  float b1=1.0;
  float T1=100.0;
  float dt1=0.01;

   for(float t1=0.0;t1<=T1;t1+=dt1){
    float fz=az;
    Iz +=(fz+a1*(t1-dt1)+b1)*dt1/2.0;
  }
  Serial.print("z값 ");
  Serial.print("\t");
  Serial.println(Iz);
  Serial.println("---------------"); 
  if(isvm>130 && Iz<10){
    Serial.println("---------------"); 
    Serial.println("낙상감지(왼쪽)");
    Serial.println("---------------"); 
  }
  else if(isvm>130 && Iz>120){
    Serial.println("---------------"); 
    Serial.println("낙상감지(오른쪽)");
    Serial.println("---------------"); 
  } 
   delay(500);
}

