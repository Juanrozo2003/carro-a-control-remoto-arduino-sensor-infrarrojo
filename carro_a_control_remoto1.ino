#include "Adafruit_LEDBackpack.h" // Incluye la biblioteca para pantallas LED (no utilizada en este código).
#include <IRremote.h> // Incluye la biblioteca para recibir señales de infrarrojos (IR).

int button = 0; // Variable para almacenar el número del botón presionado.
int LED_p = 13; // Pin digital 13 para controlar un LED.
int LED_s = 0; // Estado del LED (0 = apagado, 1 = encendido).
int Motor_p = 3; // Pin digital 3 para controlar un motor.
int Motor_s = 0; // Estado del motor (0 = apagado, 1 = encendido).
int bulb_p = A5; // Pin analógico A5 para controlar una bombilla.
int bulb_s = 0; // Estado de la bombilla (0 = apagada, 1 = encendida).

// Función para convertir un código IR en un número de botón.
int mapCodeToButton(unsigned long code) {
  // Verifica si el código tiene un formato específico.
  if ((code & 0x0000FFFF) == 0x0000BF00) {
    code >>= 16; // Desplaza el código 16 bits a la derecha.
    // Verifica que la parte superior y la inferior del código sean complementarias.
    if (((code >> 8) ^ (code & 0x00FF)) == 0x00FF) {
      return code & 0xFF; // Devuelve el número del botón.
    }
  }
  return -1; // Devuelve -1 si no se cumple la condición.
}

// Función para leer el código del control remoto.
int readInfrared() {
  int result = -1; // Inicializa el resultado como -1 (ningún botón).
  // Intenta decodificar una señal IR.
  if (IrReceiver.decode()) {
    unsigned long code = IrReceiver.decodedIRData.decodedRawData; // Almacena el código decodificado.
    result = mapCodeToButton(code); // Convierte el código en un número de botón.
    IrReceiver.resume(); // Prepara el receptor para recibir la próxima señal.
  }
  return result; // Devuelve el número del botón o -1.
}

void setup() {
  IrReceiver.begin(2); // Inicializa el receptor IR en el pin 2.
  Serial.begin(9600); // Inicia la comunicación serie a 9600 baudios.
  pinMode(LED_p, OUTPUT); // Configura el pin del LED como salida.
  pinMode(Motor_p, OUTPUT); // Configura el pin del motor como salida.
  pinMode(bulb_p, OUTPUT); // Configura el pin de la bombilla como salida.
}

void loop() {
  button = readInfrared(); // Lee el estado del botón desde el control remoto.

  // Control del LED
  if (button == 16) { // Si se presiona el botón 16.
    if (LED_s == 0) { // Si el LED está apagado.
      digitalWrite(LED_p, HIGH); // Enciende el LED.
      LED_s = 1; // Actualiza el estado del LED a encendido.
    } else { // Si el LED está encendido.
      digitalWrite(LED_p, LOW); // Apaga el LED.
      LED_s = 0; // Actualiza el estado del LED a apagado.
    }
  }

  // Control del Motor
  if (button == 17) { // Si se presiona el botón 17.
    if (Motor_s == 0) { // Si el motor está apagado.
      digitalWrite(Motor_p, HIGH); // Enciende el motor.
      Motor_s = 1; // Actualiza el estado del motor a encendido.
    } else { // Si el motor está encendido.
      digitalWrite(Motor_p, LOW); // Apaga el motor.
      Motor_s = 0; // Actualiza el estado del motor a apagado.
    }
  }

  // Control de la Bombilla
  if (button == 18) { // Si se presiona el botón 18.
    if (bulb_s == 0) { // Si la bombilla está apagada.
      digitalWrite(bulb_p, HIGH); // Enciende la bombilla.
      bulb_s = 1; // Actualiza el estado de la bombilla a encendida.
    } else { // Si la bombilla está encendida.
      digitalWrite(bulb_p, LOW); // Apaga la bombilla.
      bulb_s = 0; // Actualiza el estado de la bombilla a apagada.
    }
  }
  
  delay(10); // Añade un pequeño retraso (10 ms) para evitar que el bucle se ejecute demasiado rápido.
}
