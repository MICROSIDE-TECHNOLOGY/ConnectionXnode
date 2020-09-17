
#include <SoftwareSerial.h>

SoftwareSerial mySerial(2, 3); // RX, TX

void setup()
{
  // Open serial communications and wait for port to open:
    Serial.begin(9600);
    char valorModuloXnode = ""; 
    mySerial.begin(9600);
}//fin del setup 

void loop() // run over and over
{
    if (mySerial.available()){
        mySerial.write("XN001Ag");
        valorModuloXnode = mySerial.read();
        serial.println(valorModuloXnode);

    }//fin del if 

}//fin del método Loop

