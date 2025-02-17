#include <ESP32Servo.h>
#include <math.h>

Servo M1 , M2 , M3, M4 , M5,M6;


float l1, l2 , l3 ;

float th = 0,x , y ,z , s, x2 , y2 ;
float xs, ys, l1s , l2s;
int counter = 0;
int M6_angle=0;
float th0 = 0, th1= 0, th2 = 0, th3 = 0 , phi = -10*M_PI/180 ;

void setup() {

 l1 = 0.15;
 l2 = 0.07;
 l3 = 0.186;

  // put your setup code here, to run once:
  M1.attach(17);
  M2.attach(18);
  M3.attach(19);
  M4.attach(21);
  M5.attach(16);
  M6.attach(23);

}

void loop() {
  Serial.begin(9600);
  counter = counter + 1;
  th = th + 0.001;

  x = 0 ;
  y = 0.3 ;
  z = 0.075+ th ;

  
  th0 = M_PI/2 + atan2(-y,x);

  s = sqrt(x*x + y*y);
  y2= z - l3*sin(phi);
  x2= s - l3*cos(phi);
  
  xs = x2*x2;
  ys = y2*y2;

  l1s = l1*l1;
  l2s = l2*l2;

  th1= acos( (xs+ys+l1s-l2s)/2/l1/sqrt(xs+ys)) + atan2(y2,x2);
  th2= atan2( y2-l1*sin(th1),x2-l1*cos(th1));
  
  th2 = th2- th1;
  
  th3 = phi - th2 - th1;

  th1 = 180-(th1 * 180/M_PI);
  th2 = 90 + th2 * 180/M_PI;
  th3 = (90  + th3*180/M_PI)*60/90;
 
  M1.write(int(th0));
  M2.write(int(th1));
  M3.write(int(th2));
  M4.write(int(th3));

  Serial.print(th0);
  Serial.print(" , ");
  Serial.print(th1);
  Serial.print(" , ");
  Serial.println(th2);
  Serial.print(" , ");  
  Serial.println(th3);

  delay(50);
  if ( th >= 0.055){
    delay(1000);
         th = 0;
        if (M6_angle==0){
         M6.write(20);
         M6_angle=20;
         delay(1000);
        }
        else{
          M6.write(0);
          M6_angle=0;
          delay(1000);
        }

    }

}

