/*
* Bluetooh Basic: LED ON OFF - Avishkar
* Coder - Mayoogh Girish
* Website - http://bit.do/Avishkar
* Download the App : https://github.com/Mayoogh/Arduino-Bluetooth-Basic
* This program lets you to control a LED on pin 13 of arduino using a bluetooth module
*/

String power = "off";
String command = "";

/**
 * 2, 3 for right wheel
 * 4, 5 for left wheel
 */
const int IN1 = 2;
const int IN2 = 3;
const int IN3 = 4;
const int IN4 = 5;

void setup() {
  /**
   * Sets the baud for serial data transmission
   */
  Serial.begin(9600);

  pinMode (IN1, OUTPUT);
  pinMode (IN2, OUTPUT);
  pinMode (IN3, OUTPUT);
  pinMode (IN4, OUTPUT);
}
//
void powerOn() {
  power = "on";
}

void powerOff() {
  power = "off";
}

void wheelOff() {
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, LOW);
}

void rightWheel(String action) {
  if (action == "forward") {
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
  } else if (action == "backward") {
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
  }
}

void leftWheel(String action) {
  if (action == "forward") {
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
  } else if (action == "backward") {
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);
  }
}

void forward() {
    rightWheel("forward");
    leftWheel("forward");
}

void backward() {
    rightWheel("backward");
    leftWheel("backward");
}

void turnRight() {
    rightWheel("backward");
    leftWheel("forward");
}

void turnLeft() {
    rightWheel("forward");
    leftWheel("backward");
}

void loop() {
  /**
   * Send data only when you receive data:
   */
  if (Serial.available() > 0) {
    /**
     * Read the incoming data & store into data
     * Print Value inside data in Serial monitor
     */
    command = Serial.readString();
    Serial.println(command);

    /**
     * Checks whether value of data
     */
    if (command == "on") {
      powerOn();
    } else if (command == "off") {
      wheelOff();
      powerOff();
    }

    if (power == "off")
       return;

    if (command == "forward")
      forward();
    else if (command == "backward")
      backward();
    else if (command == "right")
      turnRight();
    else if (command == "left")
      turnLeft();
   }
}
