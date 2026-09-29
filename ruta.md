# Especificación del proyecto


## 1. Objetivo

Construir un sistema embebido de monitero ambiental y detección de condiciones de alarma para ambientes cerrado.
El sistema medirá temperatura, movimiento de y gases/humo de manera relativa. Los datos se procesaran a traves de un Arduino UNO y se comunicara en serie con una aplicación de PC.

## 2. Hardware
| COMPONENTES | FUNCIÓN |
|-------------|---------|
| Arduino UNO R3 | Procesamiento y control |
| MQ-2 | Medición relativa de humo/gases |
| LM35 | Medición de temperatura |
| PIR | Detección de movimiento |
| LEDs | Estados |
| Buzzer | Alarma |
| LCD | Información local |
| Pulsador | Silenciar |

## 3. Estados del sistema

Vamos a trabajar con tres estados que dependerán principalmente de la temperatura y del gas.

- NORMAL

`Gas < umbral de prealarma & Temperatura < umbral de prealarma`

Su salida:

```
LED verde = ON
LED amarillo = OFF
LED rojo = OFF
Buzzer = OFF
```

- PREALARMA

Cuando al menos 1 de los sensores supera el umbral pero ninguno llega al nivel de alarma.

`Gas >= gas_pre || Temperatura >= temp_pre`

Su salida:

```
LED verde = OFF
LED amarillo = ON
LED rojo = OFF
Buzzer = intermitente
```

- ALARMA

Cuando cualquiera de los sensores llegue al umbral crítico

`Gas >= gas_alarma || Temperatura >= temp_alarma`

Su salida:

```
LED verde = OFF
LED amarillo = OFF
LED rojo = ON
Buzzer = ON
```

## 4. Función del PIR

Esta para dar info contextual y poder definir si hubo movimiento durante un determinado tiempo para confirmar si efectivamente hay alguien en el ambiente o no. Así diferenciar entre una alarma local o una también remota.

# USANDO EL SIMULADOR WOKWI

## 5. Umbrales iniciales

Valores de simulación de prototipo

| VARIABLE | NORMAL | PREALARMA | ALARMA |
|Gas | `<400` | 400-699 | `>=700`|
|Temperatura | `<40°C`| 40-59 °C | `>=60°C`|

---
Inicialmente por defecto:
```
gas_pre = 400
gas_alarma = 700

temp_pre = 40°C
temp_alarma = 60°C

tiempo_alarma = 10 segundos

movimiento = 5 minutos
```
Luego se combina con un sistema configurble de CALIBRACIÓN

# Esquemas

## Qué hará Arduino

- Leer MQ-2
- Leer LM35
- Leer PIR
---
- Procesar valores
- Determinar estado
- Gestionar temporizadores
---
- Controlar LEDs
- Controlar buzzer
- Actualizar LCD
---
- Recibir configuración de calibración
- Enviar datos a la PC

## Qué hará la PC

- Recibir datos
- Mostrar sensores
- Mostrar estado
---
- Configurar umbrales
- Configurar tiempos
---
- Registrar eventos
- Interfaz Qt
---
- Alertas remotas

## General
## Arquitectura general

![Esquema propuesto por el profesor](/home/julieta/Escritorio/tp_info/esquema.jpeg)


