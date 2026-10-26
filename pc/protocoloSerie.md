# codigo


este protocolo sigue suando el el otro sensor no el LM-35
prepara el codigo para poder manipular desde la PC

[codigo en wokwi](https://wokwi.com/projects/478963653942649857)

# Mensajes

## Arduino a PC
|MENSAJE|SIGNIFICADO|
|-------|-----------|
|DATA;TEMP=25.0;GAS=350;PIR=0;STATE=NORMAL|	Envía las mediciones y el estado actual.|
|CONFIG;GAS_PRE=400;GAS_ALARM=930|	Informa los umbrales de gas configurados.|
|CONFIG;TEMP_PRE=40;TEMP_ALARM=60|	Informa los umbrales de temperatura configurados.|
|OK;GAS_PRE=450|	Confirma que aceptó un cambio de configuración.|
|ERROR;INVALID_VALUE|	Informa que rechazó un valor inválido.|

## PC a Arduino

|Comando|	Acción|
|-------|---------|
|GET;CONFIG	|Solicita la configuración actual.|
|SET;GAS_PRE=450|	Cambia el umbral de prealarma de gas.|
|SET;GAS_ALARM=800|	Cambia el umbral de alarma de gas.|
|SET;TEMP_PRE=35|	Cambia el umbral de prealarma de temperatura.|
|SET;TEMP_ALARM=50|	Cambia el umbral de alarma de temperatura.|


