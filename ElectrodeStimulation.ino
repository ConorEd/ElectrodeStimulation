//Manual Pulsing Script -< I will comment later.
int pulsecountdelay = 325; 
int outputTime = 2500; 

int command;
int i;

int electrode2 = 2;
int electrode3 = 3;
int electrode4 = 4;
int electrode5 = 5;
int electrode6 = 6; 
int inputReading; 
 

void setup() {
    Serial.begin(9600);          
    
    for (i=2;i<7;i++) {
        pinMode(i, OUTPUT);
        //Serial.print(i);    //for debugging pin initialisation
    }
    Serial.println("Manual Fire Control. Note: No Need for reupload between positions");
    Serial.println("Enter 3, 4, 5 or 6 to fire pulses on electrodes 3, 4, 5 and 6, respectively.");
    Serial.println("Good Luck! :)");   

}

void loop() {
    while(Serial.available() > 0){
        command = Serial.read();
        switch(command) {
            case '2':
                Serial.println("Firing Channel 2...");
                digitalWrite(electrode2, HIGH); 
                delay(outputTime);
                digitalWrite(electrode2, LOW);
                Serial.println("Channel 2 fire complete.");
                break;
            case '3':
                Serial.println("Firing Channel 3...");
                digitalWrite(electrode3, HIGH); 
                delay(outputTime);
                digitalWrite(electrode3, LOW);
                Serial.println("Channel 3 fire complete.");
                break;
            case '4':
                Serial.println("Firing Channel 4...");
                digitalWrite(electrode4, HIGH); 
                delay(outputTime);
                digitalWrite(electrode4, LOW);
                Serial.println("Channel 4 fire complete.");
                break;
            case '5':
                Serial.println("Firing Channel 5...");
                digitalWrite(electrode5, HIGH); 
                delay(outputTime);
                digitalWrite(electrode5, LOW);
                Serial.println("Channel 5 fire complete.");
                break;
            case '6':
                Serial.println("Firing Channel 6...");
                digitalWrite(electrode6, HIGH); 
                delay(outputTime);
                digitalWrite(electrode6, LOW);
                Serial.println("Channel 6 fire complete.");
                break;
        }
    }
}

