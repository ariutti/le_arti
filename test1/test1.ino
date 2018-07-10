#define LEVER_START 2
#define LEVER_STOP 3
#define BUTTON1 4
#define BUTTON2 5
#define BUTTON3 6


bool state_lever_start, prevState_lever_start = false;
bool state_lever_stop, prevState_lever_stop = false;
bool state1, prevState1 = false;
bool state2, prevState2 = false;
bool state3, prevState3 = false;


// set it to true if you want to send serial
// data trough serial communication
bool sendSerial = false;


void setup() 
{
  Serial.begin(9600);
  
  pinMode(LEVER_START, INPUT);
  pinMode(LEVER_STOP, INPUT);
  pinMode(BUTTON1, INPUT);
  pinMode(BUTTON2, INPUT);
  pinMode(BUTTON3, INPUT);
  
}

void loop() 
{
  getSerialData();
  
  state_lever_start = digitalRead(LEVER_START);
  state_lever_stop  = digitalRead(LEVER_STOP);
  state1 = digitalRead(BUTTON1);
  state2 = digitalRead(BUTTON2);
  state3 = digitalRead(BUTTON3);

  // lever TOP
  if(state_lever_start != prevState_lever_start) {
    if(sendSerial) {
      Serial.print("LT-");
      Serial.print(state_lever_start);
      Serial.println(";");
    }
    prevState_lever_start = state_lever_start;
  }

   // lever BOTTOM
  if(state_lever_stop != prevState_lever_stop) {
    if(sendSerial) {
      Serial.print("LB-");
      Serial.print(state_lever_stop);
      Serial.println(";");
    }
    prevState_lever_stop = state_lever_stop;
  }

  // Button 1
  if(state1 != prevState1) {
    if(sendSerial) {
      Serial.print("B1-");
      Serial.print(state1);
      Serial.println(";");
    }
    prevState1 = state1;
  }

  // Button 2
  if(state2 != prevState2) {
    if(sendSerial) {
      Serial.print("B2-");
      Serial.print(state2);
      Serial.println(";");
    }
    prevState2 = state2;
  }

  // Button 3
  if(state3 != prevState3) {
    if(sendSerial) {
      Serial.print("B3-");
      Serial.print(state3);
      Serial.println(";");
    }
    prevState3 = state3;
  }
  
  delay(10);
}




/************************************************************************************
 * SERIAL UTILITY FUNCTIONS
 ***********************************************************************************/
void getSerialData()
{
  if(Serial.available()) {
    char user_input = Serial.read(); // Read user input and trigger appropriate function
      
    if (user_input =='1')  {
       sendSerial = true;
    }
    else if(user_input =='2')  {
      sendSerial = false;
    }
  }
}
