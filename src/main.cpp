#include <Arduino.h>
#include <SPI.h>
#include <MFRC522.h>

#define SS_PIN D4  //--> SDA / SS is connected to pinout D4
#define RST_PIN D3  //--> RST is connected to pinout D3
MFRC522 mfrc522(SS_PIN, RST_PIN);  //--> Create MFRC522 instance.


unsigned long previousMillis = 0;
const long interval = 60000; // Reset interval in milliseconds
bool loopingForReset = true;


byte readcard[4];
char str[32] = "";
String StrUID;

void array_to_string(byte array[], unsigned int len, char buffer[]) {
    for (unsigned int i = 0; i < len; i++)
    {
        byte nib1 = (array[i] >> 4) & 0x0F;
        byte nib2 = (array[i] >> 0) & 0x0F;
        buffer[i*2+0] = nib1  < 0xA ? '0' + nib1  : 'A' + nib1  - 0xA;
        buffer[i*2+1] = nib2  < 0xA ? '0' + nib2  : 'A' + nib2  - 0xA;
    }
    buffer[len*2] = '\0';
}

int getid() {  
  if(!mfrc522.PICC_IsNewCardPresent()) {
    return 0;
  }
  if(!mfrc522.PICC_ReadCardSerial()) {
    return 0;
  }
  
  for(int i=0;i<4;i++){
    readcard[i]=mfrc522.uid.uidByte[i]; //storing the UID of the tag in readcard
    array_to_string(readcard, 4, str);
    StrUID = str;
  }
  Serial.println(StrUID);

  mfrc522.PICC_HaltA();
  return 1;
}

void setup() {
  Serial.begin(115200);
  SPI.begin(); 
  mfrc522.PCD_Init(); 
}

void loop() {

  
  while (loopingForReset){


    Serial.println(" ");
    Serial.println("ON");
    delay(1000);

    String command = Serial.readStringUntil('\n');
    if (command == "CONNECTED") {
      Serial.println("ConnectToPython");
      break;
    }

    delay(1000);
    
    ESP.restart();

  }

  loopingForReset = false;
  
  if (loopingForReset == false){
    
    getid();

    if (Serial.available()) {
    previousMillis = millis();
    while (Serial.available()) {
      Serial.read(); // Clear the serial buffer
    }
  } else {
    // If no message received for a certain time, reset NodeMCU
    unsigned long currentMillis = millis();
    if (currentMillis - previousMillis >= interval) {
      ESP.restart();
    }
  }

  }

}