# Práctica 3: Control de un Servomotor de 180° con Potenciómetro usando FreeRTOS

Este proyecto implementa el control de un servomotor SG90 de 180° utilizando un potenciómetro conectado a un ESP32, gestionado por tareas bajo FreeRTOS. Es parte de la materia **Sistemas en Tiempo Real** de la Maestría en Ciencias y Tecnologías de Seguridad en el INAOE.

## 🎯 Objetivo

Controlar la posición de un servomotor de 180° con la lectura de un potenciómetro mediante tareas paralelas usando FreeRTOS.

## 🧰 Hardware utilizado

- ESP32 Dev Module  
- Servomotor SG90  
- Potenciómetro 10kΩ  
- Protoboard y jumpers  
- Fuente USB o externa (si el servo consume mucho)

## 🔧 Conexiones

| Componente    | GPIO ESP32 | Descripción         |
|---------------|------------|---------------------|
| Potenciómetro | GPIO 34    | Lectura analógica   |
| Servomotor    | GPIO 25    | Señal PWM (50 Hz)   |

📌 Se utilizó una resistencia de protección (220 ohms) a tierra para evitar voltaje flotante en el potenciómetro.

## 📺 Video de demostración

[![Ver en YouTube](https://img.youtube.com/vi/_MZ3FISpCQs/0.jpg)](https://youtube.com/shorts/_MZ3FISpCQs)

## 💻 Código principal

El código está en `src/main.cpp` y utiliza la librería `ESP32Servo`.  
También se hace uso de FreeRTOS para separar las tareas de lectura y control.

## 🚀 Cómo compilar y subir el código

1. Abre la carpeta del proyecto en VS Code con PlatformIO.
2. Asegúrate de que el ESP32 esté conectado por USB.
3. Ejecuta:

```bash
# Compilar
Ctrl + Alt + B

# Subir al ESP32
Ctrl + Alt + U

# Abrir el monitor serial
Ctrl + Alt + M
