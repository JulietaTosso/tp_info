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
`LED verde = ON
LED amarillo = OFF
LED rojo = OFF
Buzzer = OFF`

- PREALARMA
Cuando al menos 1 de los sensores supera el umbral pero ninguno llega al nivel de alarma.
`Gas >= gas_pre || Temperatura >= temp_pre`
Su salida:
`LED verde = OFF
LED amarillo = ON
LED rojo = OFF
Buzzer = intermitente`

- ALARMA
Cuando cualquiera de los sensores llegue al umbral crítico
`Gas >= gas_alarma || Temperatura >= temp_alarma`
Su salida:
`LED verde = OFF
LED amarillo = OFF
LED rojo = ON
Buzzer = ON`





