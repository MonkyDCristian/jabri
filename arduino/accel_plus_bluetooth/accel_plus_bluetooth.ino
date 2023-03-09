/*
Arduino and ADXL345 Accelerometer Tutorial
by Dejan, https://howtomechatronics.com
*/

#include <Wire.h>  // Wire library - used for I2C communication
#include <SoftwareSerial.h>

int PinRX =10;
int PinTX =11;
char EndMsg = '\n';
String serial_data, blue_serial_data;

int ADXL345 = 0x53; // The ADXL345 sensor I2C address
float X_out, Y_out, Z_out;  // Outputs
int dec = 4;

SoftwareSerial BlueSerial(PinRX, PinTX); // RX, TX

void setup_blue_serial();
String read_blue_serial_Buff();
void send_blue_serial_msg();

void setup_accel();
void request_accel_data();

void setup() {
  Serial.begin(9600); // Initiate serial communication for printing the results on the Serial monitor
  setup_blue_serial();
  setup_accel();
}

void loop() {
  request_accel_data();
  send_blue_serial_msg("Xa:"+String(X_out,dec)+ ",Ya:"+String(Y_out,dec)+",Za:"+String(Z_out,dec));
}

void setup_blue_serial(){
  // set the data rate for the SoftwareSerial port
  BlueSerial.begin(9600);
  // wait for serial port to connect. Needed for native USB port only
  while (!BlueSerial) {
    Serial.println("No connection available");
    delay(10); 
  }
  
  Serial.println("Connection available");
}

String read_blue_serial_Buff() {
  String buffArray;
  while (BlueSerial.available() > 0) { //Entro a este while mientras exista algo en el puerto serial
    char buff = BlueSerial.read(); //Leo el byte entrante
   
    if (buff == EndMsg) {
      break; //Si el byte entrante coincide con mi delimitador, me salgo del while
    }

    else {
      buffArray += buff; //Si no, agrego el byte a mi string para construir el mensaje
    }
    delay(10);
  }
  return buffArray;  //Retorno el mensaje
}

void send_blue_serial_msg(String msg){
  const char* cc_msg = msg.c_str();
  BlueSerial.write(cc_msg);
  BlueSerial.write("\n");
}

void setup_accel(){
  Wire.begin(); // Initiate the Wire library
  // Set ADXL345 in measuring mode
  Wire.beginTransmission(ADXL345); // Start communicating with the device 
  Wire.write(0x2D); // Access/ talk to POWER_CTL Register - 0x2D
  // Enable measurement
  Wire.write(8); // (8dec -> 0000 1000 binary) Bit D3 High for measuring enable 
  Wire.endTransmission();
  delay(10);
}

void request_accel_data() {
  // === Read acceleromter data === //
  Wire.beginTransmission(ADXL345);
  Wire.write(0x32); // Start with register 0x32 (ACCEL_XOUT_H)
  Wire.endTransmission(false);
  Wire.requestFrom(ADXL345, 6, true); // Read 6 registers total, each axis value is stored in 2 registers
  
  X_out = ( Wire.read()| Wire.read() << 8); // X-axis value
  X_out = X_out/256; //For a range of +-2g, we need to divide the raw values by 256, according to the datasheet
  
  Y_out = ( Wire.read()| Wire.read() << 8); // Y-axis value
  Y_out = Y_out/256;
  
  Z_out = ( Wire.read()| Wire.read() << 8); // Z-axis value
  Z_out = Z_out/256;
}
