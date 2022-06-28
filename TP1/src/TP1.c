#include <stdio.h>
#include <stdlib.h>
#include "Calculos.h"
#include "utn.h"

int main(void) {
	setbuf(stdout, NULL);
	int opcion;
	float kilometros;
	float precio1 = 0;
	float precio2 = 0;
	float precio1Debito;
	float precio2Debito;
	float precio1Credito;
	float precio2Credito;
	float precio1BTC;
	float precio2BTC;
	float precio1Unitario;
	float precio2Unitario;
	float diferenciaDePrecios;
	int flagKm = 0;
	int flagPrecio = 0;
	do
	{
		utn_getNumero(&opcion,"1. Ingresar Kilometros\n2. Ingresar Precio de Vuelo\n3. Calcular costos\n4. Informar Resultados\n5. Carga forzada de datos\n6. Salir", "\nERROR", 1, 6, 3);
		switch(opcion)
		{
			case 1:
				if(flagKm == 0 && (km_get(&kilometros,"\nkm : ","\nERROR. Ingrese un numero entre 10 y 99999",10,99999,2)==0))
				{
					flagKm = 1;
					printf("\n(km = %.2f)\n",kilometros);
				}
				else
				{
					printf("\nVolver a ingresar los kilometros? s/n\n");
				}
				break;
			case 2:
				if(flagPrecio == 0 && vuelo_get(&precio1, &precio2,"\nEmpresa disponibles\n1. Aerolineas\n2. Latam", "\nERROR. Ingrese un numero entre 1 y 2", 1, 2, 2)==0)
				{
					if(flagPrecio == 0 && precio1 > 0 && precio2 > 0)
					{
						printf("\nlos 2 mayores a 0");
						flagPrecio = 1;
					}
					if(flagKm == 1)
					{
						printf("\n(km = %.2f)",kilometros);
					}
					printf("\n(Aerolineas = %.2f)",precio1);
					printf("\n(Latam = %.2f)\n\n",precio2);
				}
				else
				{
					printf("\nVolver a ingresar precio? s/n\n");
				}
				break;

			case 3:
				if(flagKm == 1 && flagPrecio == 1 && precio_calcularTodo(precio1, precio2, &precio1Debito, &precio2Debito, &precio1Credito, &precio2Credito, &precio1BTC, &precio2BTC, &precio1Unitario, &precio2Unitario, &diferenciaDePrecios)==0)
				{
					printf("\nSe calculo correctamente\n\n");
				}
				else
				{
					printf("\nIngrese kilometros y precios antes de calcular costos.\n");
				}
				break;
			case 4:
				if(flagKm == 1 && flagPrecio == 1 && precio_imprimir(precio1Debito, precio2Debito, precio1Credito, precio2Credito, precio1BTC, precio2BTC, precio1Unitario, precio2Unitario, diferenciaDePrecios)==0)
				{
					printf("\n\nSe imprimio correctamente\n");
				}
				else
				{
					printf("\nIngrese kilometros y precios antes de calcular costos.\n");
				}
				break;

			case 5:
				if(precio_cargaForzada()==0)
				{
					printf("\n\nCarga forzada realizada\n\n");
				}
				break;

			case 6:
				printf("\nSe cerro sesion");
				break;
		}
	} while(opcion!=6);
	return 0;
}
