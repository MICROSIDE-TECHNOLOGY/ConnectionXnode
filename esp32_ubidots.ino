// incluye la libreria de Ubidots 
#include "Ubidots.h"
//define los puertos del esp32 que se utilizan para la comunicación UART
#define RXD2 16
#define TXD2 17 
const char* UBIDOTS_TOKEN = "...";  // Coloca aqui el  TOKEN de Ubidots
const char* WIFI_SSID = "...";      // Coloca aqui el nombre de la red Wi-Fi 
const char* WIFI_PASS = "...";      // Coloca aqui la contraseña del Wi-Fi 
Ubidots ubidots(UBIDOTS_TOKEN, UBI_HTTP); // crea el objeto de tipo Ubidots 

void setup() {

    // inicializa el puerto serial USB para la visualizacion de datos 
    Serial.begin(115200);
    // inicializa el puerto UART para la comunicación con el sensor Xnode
    Serial2.begin(9600, SERIAL_8N1, RXD2, TXD2);
    ubidots.wifiConnect(WIFI_SSID, WIFI_PASS);
    // ubidots.setDebug(true);   descomentar esta linea si se requiere hacer un debug  
}

void loop() {

    char valor = "" ;
    while (Serial2.available()) {
        // comando para obtener valores del modulo Xnode 
        Serial2.print("XN001Ag");
        valorSensorXnode = Serial2.read();
        
        ubidots.add("Variable Temperatura ", valor);  // Change for your variable name
        /*Es posible agregar mas variables o contasntes 
        ubidots.add("Variable_Name_Two", value2);
        ubidots.add("Variable_Name_Three", value3);
        */
        bool bufferSent = false;
        bufferSent = ubidots.send();  // verifica si se envio correctamente el paquete 
        if (bufferSent) {
            // Do something if values were sent properly
            Serial.println("Values sent by the device");
        }//fin del if 
        delay(5000);
    }//fin del cíclo while
}//fin del metodo loop
