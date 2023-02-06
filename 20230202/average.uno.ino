#include <NewPing.h>
NewPing sensor(12,13,300);
double k 0.8
double old_avg=0;
double new_avg=0;
double distance=0;

void in_sonar (void)
{
    distance = sensor.ping_cm()*10.0;
}

 void average (float a,float b)
 {
    new_avg = (old_avg*b)+(a*(1-b));
    old_avg=new_avg
 }

void setup()
{ 
Serial.begin(115200);
}

void loop() {
 
  in_sensor();
  average(distance,k);
  Serial.print("average");
  Serial.print("  ");
  Serial.println(new_avg);
  }
