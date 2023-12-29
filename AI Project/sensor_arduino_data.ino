#define LIGHT_SENSOR_PIN_TOP A0    // Arduino analog pin A0
#define LIGHT_SENSOR_PIN_LEFT A1   // Arduino analog pin A1
#define LIGHT_SENSOR_PIN_MIDDLE A3 // Arduino analog pin A2
#define LIGHT_SENSOR_PIN_BOTTOM A4 // Arduino analog pin A3
#define LIGHT_SENSOR_PIN_RIGHT A2  // Arduino digital pin 13
const int analogInPin = A5;  // Analog input pin that the ACS712 is connected to
int sensorValue = 0;        // Variable to store the sensor reading
float voltage = 0;          // Variable to store the voltage calculated from the sensor reading
float current = 0;          // Variable to store the calculated current
int a = 1;

void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
}

void loop() {
  // reads the input on analog pins (value between 0 and 1023 for Arduino)
  int analogValueTop = analogRead(LIGHT_SENSOR_PIN_TOP);
  int analogValueLeft = analogRead(LIGHT_SENSOR_PIN_LEFT);
  int analogValueMiddle = analogRead(LIGHT_SENSOR_PIN_MIDDLE);
  int analogValueBottom = analogRead(LIGHT_SENSOR_PIN_BOTTOM);
  int analogValueRight = analogRead(LIGHT_SENSOR_PIN_RIGHT);

  // Current Sensor Readings
  sensorValue = analogRead(analogInPin);
  voltage = (sensorValue-30) * (5.0 / 1023.0);
  current = (voltage - 2.5) / 0.1;
 // Print all sensor data in a JSON-like format
  Serial.print("{");
  Serial.print("\"top\":");
  Serial.print(analogValueTop);
  Serial.print(",\"left\":");
  Serial.print(analogValueLeft);
  Serial.print(",\"middle\":");
  Serial.print(analogValueMiddle);
  Serial.print(",\"bottom\":");
  Serial.print(analogValueBottom);
  Serial.print(",\"right\":");
  Serial.print(analogValueRight);
  Serial.print(",\"current\":");
  Serial.print(current);
  Serial.println("}");
  delay(15000);
}
