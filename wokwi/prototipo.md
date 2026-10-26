# PROTOTIPO

Ya que en el simulador no contamos con el sensor correcto. Vamos a dejar por escrito los cambios necesarios con su respectivo código.

- [codigo completo en wokwi](https://wokwi.com/projects/478962623120899073)


## Diferencias

|Caracteristica|DS18B20|LM35|
|--------------|-------|----|
|Tipo de sensor|Digital|Analogico|
|Pin de señal|Digital4|Analogico A1|
|Bibliotecas|OneWire.h y DallasTemperature.h|No necesita|
|Lectura|getTempCByIndex(0)|analogRead()|
|Conversion|La realiza la biblioteca|Se calcula en el programa|


## Formula

```

T(°C) = (lectura ADC x Vref x 100) / 1023

```

La formula supone que la referencia del ADC es de 5V. 

HAY QUE AJUSTAR LA FORMULA CUANDO TENGAMOS LAS MEDICIONES REALES

## Codigo

Conserva la estuctura y cambia la lectura de la temp para que sirva el LM35

```c++

#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2);

unsigned long ultimoCambioLCD = 0;
const unsigned long INTERVALO_LCD = 2000;

bool mostrarEstadoLCD = false;


const int PIN_GAS = A0
const int PIN_TEMP = A1;
const int PIN_PIR = 2;

// Pines de actuadores
const int LED_VERDE = 8;
const int LED_AMARILLO = 9;
const int LED_ROJO = 10;
const int BUZZER = 11;

// Umbrales provisionales para simulación
const int GAS_PREALARMA = 400;
const int GAS_ALARMA = 930;

const float TEMP_PREALARMA = 40.0;
const float TEMP_ALARMA = 60.0;

// Referencia de tensión del ADC
const float VREF = 5.0;

// Variables de medición
int valorGas = 0;
int lecturaADC = 0;

float tensionLM35 = 0.0;
float temperatura = 0.0;

int movimiento = LOW;


enum Estado {
    NORMAL,
    PREALARMA,
    ALARMA
};


Estado estadoActual = NORMAL;

// Variables para el buzzer
unsigned long ultimoCambioBuzzer = 0;
bool buzzerEncendido = false;

const unsigned long INTERVALO_BUZZER = 500;
const int FRECUENCIA_BUZZER = 1000;

// Declaraciones de funciones
void leerSensores();
void determinarEstado();
void mostrarDatos();
void actualizarAlarmas();
void actualizarLCD();




void setup(){

    Serial.begin(9600);

    pinMode(PIN_PIR, INPUT);

    pinMode(LED_VERDE, OUTPUT);
    pinMode(LED_AMARILLO, OUTPUT);
    pinMode(LED_ROJO, OUTPUT);
    pinMode(BUZZER, OUTPUT);

    lcd.init();
    lcd.blackligth();
    lcd.clear();

    Serial.println("Sistema de monitoreo ambiental");

}


void loop(){

    leerSensores();
    determinarEstado();
    actualizarAlarmas();
    actualiarLCD();
    mostrarDatos();

    delay(1000);
}


void leerSensores(){
    // MQ-2
    valorGas = analogRead(PIN_GAS);

    // LM-35
    lecturaADC = anlogRead(PIN_TEMP);
    // Convertir a tension
    tensionLM35 = lecturaADC * (VREF / 1023.0);
    // Convertir a celsius
    temperatura = tensionLM35 *100.0;

    // PIR
    movimiento = digitalRead(PIN_PIR);
}

void determinarEstado{

idem

}

void mostrarDatos(){

// agrega
    Serial.print(" | ADC LM35: ");
    Serial.print(lecturaADC);

    Serial.print(" | Tension LM35: ");
    Serial.print(tensionLM35, 3);
    Serial.print(" V");

    Serial.print(" | Temperatura: ");
    Serial.print(temperatura, 1);
    Serial.print(" C");

}

```


