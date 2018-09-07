int relay2 = 5;
int relay3 = 6;
int trunkCtrl = A3;
int lockCtrl = A5;
boolean trunkOn = true;
boolean lockOn = false;
#define ADCVOLTSPERDIVISION 0.0047363  //5V / 1024 units
#define NUMADCSAMPLES      4000 //Number of samples to get before calculating RMS

void setup() {
  
  pinMode(relay2, OUTPUT);
  pinMode(relay3, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  
 double trunkValue = analogRead(trunkCtrl) * ADCVOLTSPERDIVISION; 
 
 if (trunkValue > 0.4) {
   //toggle bit
    trunkOn = trunkOn ^ 1;
    lockOn = false;
    }

digitalWrite(relay2, trunkOn);

 double lockValue = analogRead(lockCtrl) * ADCVOLTSPERDIVISION; 
 
 if (lockValue < 0.4 ) {
   //toggle bit
    lockOn = true;}
    else{ lockOn = false;}
    

digitalWrite(relay3, lockOn);

Serial.print(">Trunk Value: ");
Serial.println(trunkValue);
Serial.print("Lock Value: ");
Serial.println(lockValue);

//trigger delay
delay(500);
}


