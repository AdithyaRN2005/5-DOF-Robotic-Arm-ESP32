#include <ESP32Servo.h>
#include "BluetoothSerial.h" 


#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif


// init Class:
BluetoothSerial ESP_BT; 



Servo servo_M1;
Servo servo_M2;
Servo servo_M3;
Servo servo_M4;
Servo servo_M5;
Servo servo_M6;



int servo_M1_pin= 17;   //P17 M1
int servo_M2_pin= 18;   //P18 M2
int servo_M3_pin= 19;   //P19 M3
int servo_M4_pin= 21;   //P21 M4
int servo_M5_pin= 16;   //P16 M5
int servo_M6_pin= 23;   //P22 M6


//Initialize the zero position for each motor
int zero_M1=50;
int zero_M2=180;
int zero_M3=90;
int zero_M4=70;
int zero_M5=77;
int zero_M6=0;


//Set current angle to home position
int cur_pos_M1=zero_M1;
int cur_pos_M2=zero_M2;
int cur_pos_M3=zero_M3;
int cur_pos_M4=zero_M4;
int cur_pos_M5=zero_M5;
int cur_pos_M6=zero_M6;

int new_pos_M1;
int new_pos_M2;
int new_pos_M3;
int new_pos_M4;
int new_pos_M5;
int new_pos_M6;

int t_delay=10; //Time Delay during looping through angless

void motor_control(int angle){  
  if (angle >= 1000 && angle <= 1180) {
        new_pos_M1 = (angle - 1000 - zero_M1);
        if (new_pos_M1 > cur_pos_M1) {
            for (cur_pos_M1; cur_pos_M1 <= new_pos_M1; cur_pos_M1++) {
                servo_M1.write(cur_pos_M1);
                delay(50);
            }
        } else if (new_pos_M1 < cur_pos_M1) {
            for (cur_pos_M1; cur_pos_M1 >= new_pos_M1; cur_pos_M1--) {
                servo_M1.write(cur_pos_M1-zero_M1);
                delay(50);
            }
        }
    } else if (angle >= 2000 && angle <= 2180) {
        new_pos_M2 = (angle - 2000 - zero_M2);
        if (new_pos_M2 > cur_pos_M2) {
            for (cur_pos_M2; cur_pos_M2 <= new_pos_M2; cur_pos_M2++) {
                servo_M2.write(cur_pos_M2-zero_M2);
                delay(t_delay);
            }
        } else if (new_pos_M2 < cur_pos_M2) {
            for (cur_pos_M2; cur_pos_M2 >= new_pos_M2; cur_pos_M2--) {
                servo_M2.write(cur_pos_M2-zero_M2);
                delay(t_delay);
            }
        }
    } else if (angle >= 3000 && angle <= 3180) {
        new_pos_M3 = (angle - 3000 + zero_M3);
        if (new_pos_M3 > cur_pos_M3) {
            for (cur_pos_M3; cur_pos_M3 <= new_pos_M3; cur_pos_M3++) {
                servo_M3.write(cur_pos_M3);
                delay(t_delay);
            }
        } else if (new_pos_M3 < cur_pos_M3) {
            for (cur_pos_M3; cur_pos_M3 >= new_pos_M3; cur_pos_M3--) {
                servo_M3.write(cur_pos_M3);
                delay(t_delay);
            }
        }
    } else if (angle >= 4000 && angle <= 4180) {
        new_pos_M4 = (angle - 4000);
        if (new_pos_M4 > cur_pos_M4) {
            for (cur_pos_M4; cur_pos_M4 <= new_pos_M4; cur_pos_M4++) {
                servo_M4.write(cur_pos_M4);
                delay(t_delay);
            }
        } else if (new_pos_M4 < cur_pos_M4) {
            for (cur_pos_M4; cur_pos_M4 >= new_pos_M4; cur_pos_M4--) {
                servo_M4.write(cur_pos_M4);
                delay(t_delay);
            }
        }
    } else if (angle >= 5000 && angle <= 5180) {
        new_pos_M5 = (angle - 5000);
        if (new_pos_M5 > cur_pos_M5) {
            for (cur_pos_M5; cur_pos_M5 <= new_pos_M5; cur_pos_M5++) {
                servo_M5.write(cur_pos_M5);
                delay(t_delay);
            }
        } else if (new_pos_M5 < cur_pos_M5) {
            for (cur_pos_M5; cur_pos_M5 >= new_pos_M5; cur_pos_M5--) {
                servo_M5.write(cur_pos_M5);
                delay(t_delay);
            }
        }
    } else if (angle >= 6030 && angle <= 6150) {
        new_pos_M6 = (angle - 6000);
        if (new_pos_M6 > cur_pos_M6) {
            for (cur_pos_M6; cur_pos_M6 <= new_pos_M6; cur_pos_M6++) {
                servo_M6.write(cur_pos_M6);
                delay(t_delay);
            }
        } else if (new_pos_M6 < cur_pos_M6) {
            for (cur_pos_M6; cur_pos_M6 >= new_pos_M6; cur_pos_M6--) {
                servo_M6.write(cur_pos_M6);
                delay(t_delay);
            }
        }
    }
}
void setup(){

  Serial.begin(115200);

  ESP_BT.begin("ROBOTIC_ARM_NEW"); //Name of your Bluetooth interface -> will show up on your phone
  
  Serial.println("The device started, now you can pair it with bluetooth!");

  servo_M1.attach(servo_M1_pin);
  servo_M2.attach(servo_M2_pin);
  servo_M3.attach(servo_M3_pin);
  servo_M4.attach(servo_M4_pin);
  servo_M5.attach(servo_M5_pin);
  servo_M6.attach(servo_M6_pin);



//Set each motor to home position

  servo_M1.write(zero_M1);
  delay(1000);
  servo_M2.write(zero_M2);
  delay(1000);
  servo_M3.write(zero_M3);
  delay(1000);
  servo_M4.write(zero_M4);
  delay(1000);
  servo_M5.write(zero_M5);
  delay(1000);
  servo_M6.write(zero_M6);
  delay(1000);

}

void loop(){
  

//Controlling using Bluetooth

if (Serial.available()) {
  ESP_BT.write(Serial.read());
}

if (ESP_BT.available()) {
  int angle;

    int MAX_STRING_LENGTH=4 ;

    String receivedData = ESP_BT.readStringUntil('\n'); // Read the data until newline character
    int dataLength = receivedData.length(); // Get the length of received data

    if (dataLength > MAX_STRING_LENGTH) { // If data length is more than 4
      int startIndex = 0;
      int endIndex = MAX_STRING_LENGTH;
      
      while (endIndex <= dataLength) {
        String subData = receivedData.substring(startIndex, endIndex); // Extract substring
        Serial.println("Received Data: " + subData); // Print the substring
        angle = subData.toInt();
        motor_control(angle);

        startIndex = endIndex; // Update start index
        endIndex += MAX_STRING_LENGTH; // Update end index
      }

      if (startIndex < dataLength) { // If there are remaining characters
        String remainingData = receivedData.substring(startIndex); // Extract remaining characters
        Serial.println("Received Data: " + remainingData); // Print the remaining characters
        angle = remainingData.toInt();
        motor_control(angle);
      
      }
    } else {
      Serial.println("Received Data: " + receivedData); // Print the received data
      angle =receivedData.toInt();
      motor_control(angle);
    }
  }
}
    


  




