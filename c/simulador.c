// programa que "reciba" valores de temperatura y de nivel de gas
// lógica de un detector de presencia usando booleano de movimiento con un rango de tiempo
// juntar los 3 valores y determinar ESTADOS DE ALARMA con sus umbrales y tipos de alarma

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){

int estado, mov;
float temp, gas;

srand(time(NULL));
	mov = rand() % 2;

printf("Ingrese valores de temperatura y gas respectivamente: \n");
scanf("%f %f", &temp, &gas);

if(temp >= 60 || gas >= 700){
	estado = 1;
}

else if (temp >= 40 && temp < 60){
	estado = 2;
}	
else if (gas >= 400 && gas < 700){
	estado = 2;
}
	
else{
	estado = 3;
}

if(estado == 1){
	printf("ALARMA | LED ROJO | BUZZER CONTINUO\n"); 
	if(mov == 1){
		printf("Presencia detectada\n");
	}
	else{
		printf("Presencia NO detectada. AVISO DE ALARMA REMOTA\n");
	}
}

if(estado == 2){
    printf("PREALARMA | LED AMARILLO | BUZZER INTERMITENTE\n");
}

if(estado == 3){
	printf("NORMAL | LED VERDE | NO BUZZER\n");
}

return 0;
}
