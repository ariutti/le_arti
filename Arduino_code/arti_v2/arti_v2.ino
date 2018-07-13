// SERIAL STUFF ////////////////////////////////////////////////////////
bool bSendSerial = false;


// BUTTON STUFF ////////////////////////////////////////////////////////
// (ButtonDebounce Library is written and maintained 
// by Maykon L. Capellari <maykonluiscapellari@gmail.com>
// https://github.com/maykon/ButtonDebounce

#include "ButtonDebounce.h"

ButtonDebounce LEVER_TOP(2, 50);
ButtonDebounce LEVER_BOTTOM(3, 50);
ButtonDebounce BUTTON1(4, 50);
ButtonDebounce BUTTON2(5, 50);
ButtonDebounce BUTTON3(6, 50);

void lever_top_changed(int state){
  if( bSendSerial)
  {
    Serial.print("LT-");
    Serial.print(state);
    Serial.println(";");
  }
}

void lever_bottom_changed(int state){
  if( bSendSerial)
  {
    Serial.print("LB-");
    Serial.print(state);
    Serial.println(";");
  }
}

void button1_changed(int state){
  if( bSendSerial )
  {
    Serial.print("B1-");
    Serial.print(state);
    Serial.println(";");
  }
}

void button2_changed(int state){
  if( bSendSerial )
  {
    Serial.print("B2-");
    Serial.print(state);
    Serial.println(";");
  }
}

void button3_changed(int state){
  if( bSendSerial )
  {
    Serial.print("B3-");
    Serial.print(state);
    Serial.println(";");
  }
}


// SETUP ///////////////////////////////////////////////////////////////
void setup() 
{
  Serial.begin(9600);

  LEVER_TOP.setCallback( lever_top_changed );
  LEVER_BOTTOM.setCallback( lever_bottom_changed );
  BUTTON1.setCallback( button1_changed );
  BUTTON2.setCallback( button2_changed );
  BUTTON3.setCallback( button3_changed ); 
}

// LOOP ////////////////////////////////////////////////////////////////
void loop() 
{
  getSerialData();

  LEVER_TOP.update();
  LEVER_BOTTOM.update();
  BUTTON1.update();
  BUTTON2.update();
  BUTTON3.update();
    
  delay(10);
}




// SERIAL UTILITY FUNC /////////////////////////////////////////////////
void getSerialData()
{
  if(Serial.available()) {
    char user_input = Serial.read(); // Read user input and trigger appropriate function
      
    if (user_input =='1')  {
       bSendSerial = true;
    }
    else if(user_input =='2')  {
      bSendSerial = false;
    }
  }
}
