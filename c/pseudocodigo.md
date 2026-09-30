# Lógica en pseudo codigo

LEER temperatura
LEER gas
LEER movimiento

```
SI gas >= umbral_alarma
    estado = ALARMA

    SINO SI temperatura >= umbral_alarma
        estado = ALARMA

        SINO SI gas >= umbral_prealarma
            estado = PREALARMA

            SINO SI temperatura >= umbral_prealarma
                estado = PREALARMA

                SINO
                    estado = NORMAL
                    Después incorporamos el PIR:
                    SI hay movimiento
                        guardar momento del movimiento

                        SI pasó menos de X tiempo desde el último movimiento
                            movimiento_reciente = verdadero
                            SINO
                                movimiento_reciente = falso
                                Y finalmente:
                                SI estado == ALARMA
                                    activar alarma local

                                    SI movimiento_reciente == falso 
                                        generar evento de alerta remota
```


