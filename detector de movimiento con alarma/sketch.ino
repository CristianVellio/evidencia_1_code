#define MOTION_SENSOR_PIN  19  // ESP32 pin GPIO19 conectado al OUTPUT pin del sensor de movimiento
#define BUZZER_PIN         2  // ESP32 pin GPIO17 conectado al pin del Buzzer
int motionStateCurrent  = LOW; // estado del pin sensor de movimiento
int motionStatePrevious = LOW; // anterior estado del pin sensor de movimiento

void setup() {
  Serial.begin(9600);                // inicizlizado serial
  pinMode(MOTION_SENSOR_PIN, INPUT); // dispone ESP32 pin a modo input
  pinMode(BUZZER_PIN, OUTPUT);          // dispone ESP32 pin a modo output
}

void loop() {
  motionStatePrevious = motionStateCurrent;            // salva viejo estado
  motionStateCurrent  = digitalRead(MOTION_SENSOR_PIN); // lee nuevo estado

  if (motionStatePrevious == LOW && motionStateCurrent == HIGH) { // el estado de pin cambia: LOW -> HIGH
    Serial.println("Motion detected!, making sound");
    digitalWrite(BUZZER_PIN, HIGH); // apagar
  } else if (motionStatePrevious == HIGH && motionStateCurrent == LOW) { // el estado de pin cambia: HIGH -> LOW
    Serial.println("Motion stopped!, stops making sound");
    digitalWrite(BUZZER_PIN, LOW);  // apagar
  }
}
