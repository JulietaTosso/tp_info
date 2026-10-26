# Planificación

### 1. Cada componente

Probar cada componente por separado.
- LM-35 : medir temp ambiente y comproar que la lectura sea razonable
- MQ-2 : comprobar que la lectura analogica cambie con el tiempo ante condiciones de prueba controladas.
- PIR : comprobar que detecte mov y que vuelva al estado sin mov.
- LEDs, buzzer y LCD : comprobar la salida

### 2. Registrar

Anotar que mide cada sensor en condiciones normales, sus variacion y/o errores.

### 3. Probar condiciones especificas

Repetir las mismas mediciones bajo distintas condiciones seguras

- LM35 comparar en varios puntos de temp conocidos
- MQ2 observar lectura de referencia y su variacion
- PIR ensayar diferentes distacias, angulo y tiempos de espera

### 4. Definir umbrales

Con los resultado anteriores definir nuestros estado `NORMAL`,`PREALARMA`y `ALARMA`

### Validar sistema

Hacer pruebas integrales y anotarlas.


## Por sensor

- LM35

El LM35 entrega una tensión proporcional a la temperatura, aproximadamente 19m V/°C. Por eso, con una referencia analógica de 5 V y un ADC de 10 bits, el cálculo inicial es:

T = (ADC.5 / 1023) .100

---

Procedimiento:
1. Coloca el LM35 y un termometro de referencia cerca
2. esperar que se estabilicen
3. Registrar varias lecuras del arduino y la temp del termometro
4. Repetir en distintos puntos de temp
5. Calcula la dferencia entre ambos valores

tabla ilustrativa

|Termometro|LM35|Diferencia|
|----------|----|----------|
|22,0°C|20,8°C|+0,8°C|


- MQ-2

Procedimiento:
1. Revisar el modulo y su alimentacion segun la docu del fabricante
2. Respeta el tiempo de precalentado y estabilizacion 
3. Registra lecturas durante un periodo en condiciones ambientales normales
4. Calcula el valor tipico y observa cuanto fluctua
5. Repeti las mediciones en distintas sesiones para ver si la lectura base cambia

- PIR

Su salida solo indica si detecta movimiento o no

hacer una tabla


## Documentacion

Argumentar el porque de la elccion de cada umbral

- Valor incial
- Datos observado- Criterio de seleccion
- Validacion
- Limitaciones

# Pruebas



