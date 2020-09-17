
//define los puertos del esp32 que se utilizan para la comunicación UART
#define RXD2 16
#define TXD2 17 

void setup() {
    // inicializa el puerto serial USB para la visualizacion de datos 
    Serial.begin(115200);
    // inicializa el puerto UART para la comunicación con el sensor Xnode
    Serial2.begin(9600, SERIAL_8N1, RXD2, TXD2);

}//fin del método Setup

void loop() { 
    char valorSensorXnode = ""
    // verifica si esta disponible el puerto UART
    while (Serial2.available()) {

        // comando para obtener valores del modulo Xnode
        Serial2.print("XN001Ag");
        valorSensorXnode = Serial2.read();
        Serial.print("Valor actual del sensor");
        Serial.println(valorSensorXnode)
    }//fin del cíclo while


}//fin del método loop 
