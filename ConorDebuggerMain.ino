/* Simple Debugging script for Arduino-Picolog-Pulse circuit. Three modes of operation. 
Conor Edwards - 20-08-18 
Channels 1-6 correspond to electrodes 1-6.
Note: Channels 1 and 2 are controls:
      - Channel 1 is grounded prior to the relay. (Hence pin D1 is not initialised as there is no relay to trigger). 
      - Channel 2 is grounded after the relay.
      Channels 3/4 and 5/6 are connected to channels 1 (yellow) and 2 (blue) on the signal generator, respectively (specific to Tektronix Arbitrary Function Generator). 
*/

void setup() {
  Serial.begin(9600);          
  for (int thisPin = 2; thisPin < 7; thisPin++) {
  pinMode(thisPin, OUTPUT);
  }
  Serial.print("|                Pulse Debugger Script.               |\n=======================================================\n| Enter 'o' to turn on all pins and 'x' to turn off.  |\n| 'm' will trigger sequential pulsing of each channel.|\n| Entering a channel number will trigger it,          |\n| i.e. enter 6 to turn on channel 6 (position 6).     |\n=======================================================");   
}

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available() > 0) {
    int inByte = Serial.read();

    switch (inByte) {
      case 'o':
      Serial.print("\nTurning pins on.");
      for (int thisPin = 2; thisPin < 7; thisPin++) {
        digitalWrite(thisPin, HIGH);
      }
      break;

      case 'x':
      Serial.print("\nTurning pins off.");
      for (int thisPin = 2; thisPin < 7; thisPin++) {
        digitalWrite(thisPin, LOW);
      }
      break;

      case 'm':
      Serial.write("\nInitialising sequential pulsing, 1 second interval...");
      delay(1000);
      for (int thisPin = 2; thisPin < 7; thisPin++) {
      String pinLab = String(thisPin);
      Serial.print("\nPulsing Channel " + pinLab + "...");
      digitalWrite(thisPin, HIGH);
      delay(1500);
      digitalWrite(thisPin, LOW); 
      Serial.print("Done!");
      }
      break;

      case '1':
      Serial.print("\nPin 1 On");
      digitalWrite(1, HIGH);
      break;

      case '2':
      Serial.print("\nPin 2 On");
      digitalWrite(2, HIGH);
      break;

      case '3':
      Serial.print("\nPin 3 On");
      digitalWrite(3, HIGH);
      break;

      case '4':
      Serial.print("\nPin 4 On");
      digitalWrite(4, HIGH);
      break;

      case '5':
      Serial.print("\nPin 5 On");
      digitalWrite(5, HIGH);
      break;

      case '6':
      Serial.print("\nPin 6 On");
      digitalWrite(6, HIGH);
      break;
  }
}
}
