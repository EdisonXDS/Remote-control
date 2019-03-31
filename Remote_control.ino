#include <ir_Lego_PF_BitStreamEncoder.h>
#include <boarddefs.h>
#include <IRremoteInt.h>
#include <IRremote.h>

#include <IRremote.h>
 
int IR_Recv = 10;  
int bluPin = 9;
int grnPin = 8;
int yelPin = 7;
 
IRrecv irrecv(IR_Recv);
decode_results results;
 
void setup(){
  Serial.begin(9600);  
  irrecv.enableIRIn(); 
  pinMode(bluPin, OUTPUT);     
  pinMode(grnPin, OUTPUT);      
  pinMode(yelPin, OUTPUT);      

}
 
void loop(){
  //decodes the infrared input
  if (irrecv.decode(&results)){
    long int decCode = results.value;
    Serial.println(results.value);
    switch (results.value){
      case 551520375: //press the 1 button
        digitalWrite(bluPin, HIGH);//turn on blue led
        break;
      case 551504055: //press the 2 button
        digitalWrite(bluPin, LOW);//turn off blue led
        break; 
       case 551536695: //press the 3 button
        digitalWrite(grnPin, HIGH);//turn on green led
        break;                   
      case 551495895: //4 button
        digitalWrite(grnPin, LOW);//turn off green led   
        break;
       case 551528535: //press the 5 button
        digitalWrite(yelPin, HIGH);//turn on yellow led
        break;       
       case 551512215: //press the 6 button
        digitalWrite(yelPin, LOW);//turn off yellow led
        break;
    }
    irrecv.resume(); // Receives the next value from the button you press
  }
  delay(10);
}
