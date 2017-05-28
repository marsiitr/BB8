 //bb8 original
#include <SoftwareSerial.h>
#include<Servo.h>

SoftwareSerial bluetooth(6, 7); // RX, TX
Servo myServo;

int pwm_2=3;
int pwm_1=5;
int dir_2=10;
int dir_1=11;
int pwm_3=9;
int dir_3=12;
int state;
int last_state=0;
int flag = 0;
int angle =0;
int servo_flag=0;
int pwm_val,u;
void setup() {
   pinMode(pwm_2, OUTPUT);
   pinMode(pwm_1, OUTPUT);
   pinMode(dir_1, OUTPUT);
   pinMode(dir_2, OUTPUT);
   pinMode(dir_3,OUTPUT);
   pinMode(pwm_3,OUTPUT);
   //myServo.attach(9);
   //myServo.write(90);
  
  // Open serial communications and wait for port to open:
  Serial.begin(9600);
  Serial.println("Starting Project");
  bluetooth.begin(9600);
  
}

void loop() { // run over and over
  if (bluetooth.available()) {
    state = bluetooth.read();
    if( state== 83)
      flag=1;
    else if(state != 83){
      flag =0;
      last_state = state;
      Serial.println(state);
      Serial.println(" ");
      Serial.println(last_state);
  }
  }



u=state-last_state;

//forward

if (state == 73) {
      if(pwm_val<200)
      {  pwm_val++; }
        analogWrite(pwm_1, pwm_val);
        analogWrite(pwm_2, pwm_val); 
        digitalWrite(dir_1, HIGH);
        digitalWrite(dir_2, HIGH);
        if(flag==0)
          Serial.println("Go Forward!");
          delay(5);
          
        }
    
    
    // turn left
    else if (state == 74) {
        if(pwm_val<200)
        {  pwm_val++; }
        analogWrite(pwm_1, pwm_val);
        analogWrite(pwm_2, pwm_val); 
        digitalWrite(dir_1, LOW); 
        //for(i=80;i<=200;i=i+10)
        //{analogWrite(pwm_2, i);delay(500);}
        digitalWrite(dir_2, HIGH);
        
         if(flag==0)
          Serial.println("Turn LEFT");
    }
  //turn right
    
    else if (state == 71) {
        if(pwm_val<200)
        {  pwm_val++;}
    //for(i=80;i<=200;i=i+10)
        analogWrite(pwm_1,pwm_val);
        digitalWrite(dir_1, HIGH); 
        analogWrite(pwm_2,pwm_val);
        digitalWrite(dir_2, LOW);

        if(flag==0)
          Serial.println("Turn RIGHT");
    }
    //Reverse
    else if (state == 72) {
      if(pwm_val<200)
        {  pwm_val++; }
    //for(i=80;i<=200;i=i+5)
        analogWrite(pwm_1, pwm_val);
        //for(i=80;i<=200;i=i+5)
        analogWrite(pwm_2, pwm_val); 
        digitalWrite(dir_1, LOW);
        digitalWrite(dir_2, LOW);

        if(flag==0)
          Serial.println("Reverse!");
          delay(5);
         
    }
  //forward
    if (state == 70) {
        digitalWrite(pwm_1, HIGH);
        digitalWrite(pwm_2, HIGH); 
        digitalWrite(dir_1, HIGH);
        digitalWrite(dir_2, HIGH);
        if(flag==0)
          Serial.println("Go Forward!");
          delay(5);
          
        }
    
    
    // turn left
    else if (state == 82) {
        analogWrite(pwm_1, 80); 
        digitalWrite(dir_1, LOW); 
        analogWrite(pwm_2, 160);
        digitalWrite(dir_2, HIGH);
        
        
          if(flag==0)
          Serial.println("Turn LEFT");
    }
  //brake
    else if (state == 83) {
        digitalWrite(pwm_1, LOW); 
        digitalWrite(pwm_2, LOW); 
        digitalWrite(dir_1, LOW);
        digitalWrite(dir_2, LOW);

        if(flag==0)
          Serial.println("STOP!");
         
        
        
    }
    //turn right
    else if (state == 76) {
         analogWrite(pwm_1,160); 
        digitalWrite(dir_1, HIGH); 
        analogWrite(pwm_2,80);
        digitalWrite(dir_2, LOW);

        if(flag==0)
          Serial.println("Turn RIGHT");
    }
    //Reverse
    else if (state == 66) {
        digitalWrite(pwm_1, HIGH);
        digitalWrite(pwm_2, HIGH); 
        digitalWrite(dir_1, LOW);
        digitalWrite(dir_2, LOW);

        if(flag==0)
          Serial.println("Reverse!");
          delay(5);
         
    }

   /* //servo
    else if( state==88||state==120)
    { myServo.write(s_pos+20);
    delay(1000);
      s_pos+=20;
      
    }


    //servo turns left
    else if( state==86||state==118)
    { myServo.write(s_pos-20);
    delay(1000);
      s_pos-=20;
    }//servo goes to 90degrees
    



     
  //servo  
    if(state==87)
    {
      servo_flag = 0;
      myServo.write(90);
    }
    else if(state==119){
      servo_flag = 1;
    }
     

  if(servo_flag == 1){
  if(state >= 48 && state <= 57){
    angle = map(state,48,57,0,180);
  }
  myServo.write(angle);
  }
  Serial.print(last_state);
    Serial.print("\t");
    Serial.println(angle);
}*/
else if (state==87)

{
 analogWrite(pwm_3,30);
 digitalWrite(dir_3,HIGH);
 
 
 
}
else if(state==117||state==119)
{
  digitalWrite(pwm_3,LOW);
  digitalWrite(dir_3,LOW);
 
}
else if(state==85)
{analogWrite(pwm_3,30);
 digitalWrite(dir_3,LOW);
}
if(state!=last_state){
  pwm_val=80;}

}
