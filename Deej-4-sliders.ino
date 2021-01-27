const int NUM_SLIDERS = 4;
const int analogInputs[NUM_SLIDERS] = {A0, A1, A2, A3};

int analogSliderValues[NUM_SLIDERS];
// Power Button
char switch1 = 0; //name of fist switch
char switch2 = 0; //name of second switch

void setup() { 
  for (int i = 0; i < NUM_SLIDERS; i++) {
    pinMode(analogInputs[i], INPUT);
  }
  pinMode(2, INPUT_PULLUP); // Front Button 1
  pinMode(3, INPUT_PULLUP); // Front Button 2
  pinMode(4, INPUT_PULLUP); // Front Button 3
  pinMode(5, INPUT_PULLUP); // Front Button 4
  pinMode(6, INPUT_PULLUP); // Power Button
  pinMode(7, INPUT_PULLUP); // Channel Button 
  pinMode(8, OUTPUT);  // Front Light 5
  pinMode(9, OUTPUT);  // Front Light 4
  pinMode(10, OUTPUT);  // Front Light 3
  pinMode(11, OUTPUT);  // Front Light 2
  pinMode(12, OUTPUT);  // Front Light 1
  pinMode(A4, OUTPUT);  // Power Button Relay

  Serial.begin(9600);
}

void loop() {
  updateSliderValues();
  sendSliderValues(); // Actually send data (all the time)
  printSliderValues(); // For debug
  frontButtonLights();
  PowerButton();
  ResetButton();
  //delay(10);
  
}

void updateSliderValues() {
 for (int i = 0; i < NUM_SLIDERS; i++) {
     analogSliderValues[i] = analogRead(analogInputs[i]);
  }
}

void sendSliderValues() {
  String builtString = String("");

  for (int i = 0; i < NUM_SLIDERS; i++) {
    builtString += String((int)analogSliderValues[i]);

    if (i < NUM_SLIDERS - 1) {
      builtString += String("|");
    }
  }
  
  Serial.println(builtString);
}

void printSliderValues() {
  for (int i = 0; i < NUM_SLIDERS; i++) {
    String printedString = String("Slider #") + String(i + 1) + String(": ") + String(analogSliderValues[i]) + String(" mV");
    Serial.write(printedString.c_str());

    if (i < NUM_SLIDERS - 1) {
      Serial.write(" | ");
    } else {
      Serial.write("\n");
    }
  }
}
void frontButtonLights(){
  if (digitalRead(7) == HIGH) {
    digitalWrite(12, LOW);
  } else {
    digitalWrite(12, HIGH);
  }
  if (digitalRead(2) == HIGH) {
    digitalWrite(11, LOW);
  } else {
    digitalWrite(11, HIGH);
  }
  if (digitalRead(3) == HIGH) {
    digitalWrite(10, LOW);
  } else {
    digitalWrite(10, HIGH);
  }
  if (digitalRead(4) == HIGH) {
    digitalWrite(9, LOW);
  } else {
    digitalWrite(9, HIGH);
  }
 if (digitalRead(5) == HIGH) {
    digitalWrite(8, LOW);
  } else {
    digitalWrite(8, HIGH);
  }
}
void PowerButton(){
if (digitalRead(7) == LOW){
  if (digitalRead(6) == LOW && (switch1 == 0)){
     digitalWrite(A4, HIGH);
     delay(250); // how long the button press will occur
     digitalWrite(A4, LOW);
     switch1 = 1; // changes the switches char so the switch will not automatically loop
}
  if (digitalRead(6) == HIGH && (switch1 == 1)) {
     digitalWrite(A4, HIGH);
     delay(250); // how long the button press will occur
     digitalWrite(A4, LOW);
     switch1 = 0;
  }
 }
}
void ResetButton(){
if (digitalRead(2) == LOW && digitalRead(3) == LOW && digitalRead(4) == LOW && digitalRead(5) == LOW && (digitalRead(7) == LOW)){
     digitalWrite(A4, HIGH);
  }else {
    digitalWrite (A4,LOW);
  }
}

//  digitalWrite(12, HIGH);   // turn the LED on (HIGH is the voltage level)
//  delay(250);                       // wait for a second
//    digitalWrite(11, HIGH);   // turn the LED on (HIGH is the voltage level)
//  delay(250);                       // wait for a second
//    digitalWrite(10, HIGH);   // turn the LED on (HIGH is the voltage level)
//  delay(250);                       // wait for a second
//    digitalWrite(9, HIGH);   // turn the LED on (HIGH is the voltage level)
//  delay(250);                       // wait for a second
//    digitalWrite(8, HIGH);   // turn the LED on (HIGH is the voltage level)
//  delay(250);                       // wait for a second
// digitalWrite(12, LOW);   // turn the LED on (HIGH is the voltage level)
//  delay(250);                       // wait for a second
//    digitalWrite(11, LOW);   // turn the LED on (HIGH is the voltage level)
//  delay(250);                       // wait for a second
//    digitalWrite(10, LOW);   // turn the LED on (HIGH is the voltage level)
//  delay(250);                       // wait for a second
//    digitalWrite(9, LOW);   // turn the LED on (HIGH is the voltage level)
//  delay(250);                       // wait for a second
//    digitalWrite(8, LOW);   // turn the LED on (HIGH is the voltage level)
//  delay(250);                       // wait for a second
