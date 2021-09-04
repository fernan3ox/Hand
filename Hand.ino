#include<Servo.h>

Servo ferna1;

//variables button

int button = 4;
int pin_state1;
int pin_state2;

//variables de dedo

int finger1=6;
int finger_status1;

//variables generales

int flag=0;

//variables del servo motor

int pin_servo1=5;
int time_servo=10;
bool address_state=true;

void setup() {

  for(int i ; i<=255;i++){
    
  }

  ferna1.attach(pin_servo1);
  pinMode(button,INPUT);

  ferna1.write(180);
  

}

void loop() {
  

  pin_state1 = state(button);
  finger_status1 = state2(finger1);

  dedo_accionamiento();
  
  
}

int state(int x){
  boolean A;
  int B;
  A=digitalRead(x);
  if (A==true){
    B=1;
  }else{
    B=0;
  }
  return B;
}

void Giro_de_servo(int a)
{
 
  int j = ferna1.read();
  
    j=j-1;
     
    ferna1.write(j); 
    delay(a);
  
  
}
int state2(int x){
  boolean A;
  int B;
  A=digitalRead(x);
  if (A==true){
    B=1;
  }else{
    B=0;
  }
  return B;
}
  
void girodeservos1 (int a)
{
 
  int j = ferna1.read();
    for(j; j<180; j++){
    
   ferna1.write(j);
    delay(a);
    
   
  }
  }

void dedo_accionamiento(){
  if(pin_state1==1 and finger_status1==0){

  Giro_de_servo(time_servo);
    
  }if(pin_state1==1 and finger_status1==1){
 
    delay (2000);

    pin_state1 = state(button);
  finger_status1 = state2(finger1);
  
  if(pin_state1==1){

      girodeservos1(time_servo);
   }
  }
  
  if (ferna1.read()==0){
    girodeservos1(time_servo);
  }
  
}
