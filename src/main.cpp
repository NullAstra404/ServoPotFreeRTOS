#include <Arduino.h>
#include <ESP32Servo.h>

#define SERVO_PIN 25         // PWM para el servomotor
#define POT_PIN 34           // ADC para el potenciómetro

Servo myServo;

// Tarea para leer el potenciómetro
void readPotTask(void *parameter) {
  while (1) {
    int potValue = analogRead(POT_PIN);             // Rango 0 - 4095
    int angle = map(potValue, 0, 4095, 0, 180);      // Mapear a 0° - 180°
    myServo.write(angle);                           // Mover el servo
    vTaskDelay(pdMS_TO_TICKS(100));                 // Esperar 100ms
  }
}

void setup() {
  Serial.begin(115200);
  analogReadResolution(12);                         // Resolución ADC de 12 bits
  myServo.setPeriodHertz(50);                       // Frecuencia PWM para servo
  myServo.attach(SERVO_PIN, 500, 2400);             // Pulso entre 0.5ms y 2.4ms

  xTaskCreatePinnedToCore(                          // Crear tarea en FreeRTOS
    readPotTask,          // Función de la tarea
    "ReadPotTask",        // Nombre
    1024,                 // Stack size
    NULL,                 // Parametros
    1,                    // Prioridad
    NULL,                 // Handle
    1                     // Núcleo (0 o 1)
  );
}

void loop() {
  // Nada aquí, todo está en FreeRTOS
}
