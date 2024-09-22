# carro-a-control-remoto-arduino-sensor-infrarrojo
Proyecto de carro a control remoto con Arduino Uno. Utiliza un sensor IR para recibir señales del control, 4 motores DC para el movimiento, y un relé SPDT para invertir la dirección. Incluye un LED rojo para indicar estado y una resistencia de 1 kΩ. Ideal para aprender sobre robótica y programación en C++.

Componentes Necesarios:

Arduino Uno
Control remoto infrarrojo.
Receptor infrarrojo (IR)
LED.
Motor DC.
Resistencia de 1K omhio
Jumpers
Rele SPDT 

Conexión:
Conecta el receptor IR al pin 2 de la placa Arduino.
Conecta el LED al pin 13, el motor al pin 3 y la bombilla al pin A5.
Asegúrate de realizar las conexiones correctamente y de alimentar los componentes.
Instalación de Bibliotecas:

Asegúrate de tener instalada la biblioteca IRremote. Puedes instalarla desde el Gestor de Bibliotecas de Arduino.
Subir el Código:
Copia y pega el código en el IDE de Arduino.
Conecta tu Arduino a tu computadora y selecciona el puerto correcto.
Sube el código a tu placa.

Uso:
Usa el control remoto para interactuar con los dispositivos:
Botón 16: Encender/apagar el LED.
Botón 17: Encender/apagar el motor.
Botón 18: Encender/apagar la bombilla.
Botón 1: Mover hacia adelante.
Botón 2: Girar a la derecha.
Botón 3: Girar a la izquierda.

