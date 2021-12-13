#include <Adafruit_NeoPixel.h>

#if defined(ESP8266)
#include <ESP8266WiFi.h>          //https://github.com/esp8266/Arduino
#else
#include <WiFi.h>          //https://github.com/esp8266/Arduino
#endif
#if defined(ESP8266)
#include <ESP8266WebServer.h>
#else
#include <WebServer.h>
#endif
#include <WiFiManager.h> 
//needed for library
#include <DNSServer.h>
#if defined(ESP8266)
#include <ESP8266WebServer.h>
#else
#include <WebServer.h>
#endif
#include <WiFiManager.h>          
#include <FirebaseArduino.h>
 
// Configure com suas credenciais
// Credencial está em configuração do projeto, contas e serviços.
#define FIREBASE_HOST "YOUR_PROJECT.firebaseio.com"
#define FIREBASE_AUTH "YOUR_AUTH"
 
#define PIN       2 
#define NUMPIXELS 3

Adafruit_NeoPixel strip(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

int pixel;
int red;
int green;
int blue;
int a;

void setup() {

    Serial.begin(115200);

    WiFiManager wifiManager;
    wifiManager.autoConnect("Luminaria Wifi");
    Serial.println("connected...yeey :)");
  
  //Iniciar Firebase
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);

  strip.begin();
  
}
   
void loop() {

String controle = Firebase.getString("DatabaseStringToken");
Serial.println(controle);
  
String rgba = "rgba";
String pixe = "pixel";
String texto;

if( controle.substring(0, 4) == rgba){
  
controle.trim();
controle.remove(0, 5);
controle.replace(")", "");

texto = controle.substring(0, 5) ;
red = texto.toInt();
texto =String(red);
controle.remove(0, texto.length());
controle.remove(0, 1);

texto = controle.substring(0, 5) ;
green = texto.toInt();
texto =String(green);
controle.remove(0, texto.length());
controle.remove(0, 1);

texto = controle.substring(0, 5) ;
blue = texto.toInt();
texto =String(blue);
controle.remove(0, texto.length());
controle.remove(0, 1);

texto = controle.substring(0, 5) ;
a = texto.toInt();
texto =String(a);
controle.remove(0, texto.length());

uint32_t color = strip.Color(red, green, blue, a);
strip.fill(color);
strip.show();

}

 if( controle.substring(0, 5) == pixe){
  
controle.trim();

controle.remove(0, 6);
String texto = controle.substring(0, 1) ;
pixel = texto.toInt();
texto =String(pixel);
controle.remove(0, texto.length());

controle.remove(0, 5);
controle.replace(")", "");
Serial.println(controle);


texto = controle.substring(0, 5) ;
red = texto.toInt();
texto =String(red);
controle.remove(0, texto.length());
controle.remove(0, 1);

texto = controle.substring(0, 5) ;
green = texto.toInt();
texto =String(green);
controle.remove(0, texto.length());
controle.remove(0, 1);

texto = controle.substring(0, 5) ;
blue = texto.toInt();
texto =String(blue);
controle.remove(0, texto.length());
controle.remove(0, 1);

texto = controle.substring(0, 5) ;
a = texto.toInt();
texto =String(a);
controle.remove(0, texto.length());

  uint32_t color = strip.Color(red, green, blue, a);
  strip.setPixelColor(pixel, color);
  strip.show();
  Serial.println(pixel);
}
Serial.print("rgba(");
Serial.print(red);
Serial.print(",");
Serial.print(green);
Serial.print(",");
Serial.print(blue);
Serial.print(",");
Serial.print(a);
Serial.print(")");
Serial.println("");
}
