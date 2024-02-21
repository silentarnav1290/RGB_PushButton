long time = 0; //sets the time variable, and uses 'long' syntax as the time variable could be large.
int counter = 0; //counter to count how many times the button has been pressed
const int redPin = 7; 
const int greenPin = 5;
const int bluePin = 6; 
int buttonState = 0; //buttonState for either HIGH or LOW, depending on if the button is pressed. 
const int buttonPin = 8; 
int delayTime = 150; //variable for the time within the delay function (not needed)
long debounce = 200; //the time (in milliseconds) which is the minimum needed for the RGB LED to change colors

void setup() {
  pinMode(redPin, OUTPUT); 
  pinMode(greenPin, OUTPUT); 
  pinMode(bluePin, OUTPUT); 
  pinMode(buttonPin, INPUT); 
}

void loop() {
  buttonState = digitalRead(buttonPin); //reads the button 
  if (buttonState == LOW && millis() - time > debounce) //checks if the button has been pressed 
  //AND if the current milliseconds since the program has been initiated minus the milliseconds 
  //since the button has been pressed is greater than 200 milliseconds (debounce variable)
  {
  counter++; //increments the counter variable by one, button has been pressed
  time = millis(); //sets the time variable to however many milliseconds since the program began as that was when the button is pressed, when the time variable is being changed
  }

  if (counter == 0){ 
    setColor(0, 0, 0); 
  }
  else if (counter == 1) { 
    setColor(255, 0, 0); 
  }
  else if (counter == 2) { 
    setColor(0, 255, 0); 
  }
  else if (counter == 3) { 
    setColor(0, 0, 255); 
  }
  else if (counter == 4) { 
    setColor(255, 255, 0); 
  }
  else if (counter == 5){ 
    setColor(80, 0, 80); 
  }
  else if (counter == 6) {
    setColor(0, 255, 255); 
  }
  else if (counter == 7) {
    setColor(255, 105, 0); 
  }
  else if (counter == 8) { 
    setColor(255, 105, 185); 
  }
  else if (counter > 8){ //if there are no more colors to switch to, it resets to off and goes again
    counter = 0; //resets LED to off and restarts the 'loop'
  }
}

void setColor(int redValue, int greenValue, int blueValue){ 
  analogWrite(redPin, redValue); 
  analogWrite(greenPin, greenValue); 
  analogWrite(bluePin, blueValue); 
}