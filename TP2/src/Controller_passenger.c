#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayPassenger.h"
#include "utn.h"
#include "Controller_passenger.h"
#define CANT_PASAJEROS 100

int Controller_passengerAdd(Passenger* pPassenger, int len,	int id)
{
	int retorno = -1;
	char name[TAM_CHAR];
	char lastName[TAM_CHAR];
	float price;
	char flycode[TAM_FLYCODE];
	int typePassenger;
	int statusFlight;

	if(pPassenger != NULL && len > 0 && id >= 0 &&
		utn_getNombre(name, TAM_CHAR, "Nombre?", "\nERROR\n", 2) == 0 &&
		utn_getNombre(lastName, TAM_CHAR, "Apellido?", "\nERROR\n", 2) == 0 &&
		utn_getNumeroFlotante(&price, "Precio?", "\nERROR\n", 1, 90000, 2) == 0  &&
		utn_getAlfanumerica(flycode, TAM_FLYCODE, "Codigo de vuelo?", "\nERROR\n", 2) == 0 &&
		utn_getNumero(&typePassenger, "Tipo de pasajero: 1(CLASE BAJA) 2(CLASE MEDIA) 3(CLASE ALTA)", "\nERROR\n", 1, 3, 2) == 0 &&
		utn_getNumero(&statusFlight, "Estado de vuelo: 1(ACTIVO) 2 (INACTIVO)", "\nERROR\n", 1, 2, 2) == 0 &&
		addPassenger(pPassenger, len, id, name, lastName, price, flycode, typePassenger, statusFlight) == 0)
	{
		retorno = 0;
	}
	return retorno;
}

int Controller_passengerPrint(Passenger* passenger, int len, int cantidad)
{
	int retorno = -1;
	int opciones;
	int orden;
	float auxTotal;
	float auxProm;
	char respuesta;
	int auxAcumulador = 0;

	printPassenger(passenger, len);
	printf("\nOrdenamos? s/n \n");
	scanf("%c",&respuesta);
	if(respuesta == 's')
	{
		if(utn_getNumero(&opciones,"\n1. Listado de los pasajeros ordenados alfabeticamente por Apellido y Tipo de pasajero."
		"\n2. Total y promedio de los precios de los pasajes, y cuantos pasajeros superan el precio promedio."
		"\n3. Listado de los pasajeros por Codigo de vuelo y estados de vuelos activos"
		"\n4. Salir", "\nError", 1, 4, 2)==0)
		{
			switch(opciones)
			{
			case 1:
				if(utn_getNumero(&orden, "\nComo ordenamos?\n0 (ascendente)\n1 (descendente)", "\nError\n", 0, 1, 2)==0 &&
				sortPassengers(passenger, CANT_PASAJEROS, orden)==0 &&
				printPassenger(passenger, CANT_PASAJEROS)==0)
				{
					retorno = 0;
				}
				break;
			case 2:
				if(totalPrice(passenger, CANT_PASAJEROS, &auxTotal)==0)
				{
					if(promedioPrice(cantidad, auxTotal, &auxProm)==0)
					{
						if(superanPricePromedio(passenger, CANT_PASAJEROS, auxProm, &auxAcumulador)==0)
						{
							retorno = 0;
							printf("\nEl total es: %.2f\nEl promedio de precios es: %.2f\nPasajeros que superan promedio: %d\n",auxTotal,auxProm,auxAcumulador);
						}
						else
						{
							printf("\nHubo un error en el calculo\n");
						}
					}
				}
				break;
			case 3:
				if(utn_getNumero(&orden, "\nComo ordenamos?\n0 (ascendente)\n1 (descendente)", "\nError\n", 0, 1, 2)==0 &&
				sortPassengersFlyCode(passenger, CANT_PASAJEROS, orden)==0 &&
				printPassenger(passenger, CANT_PASAJEROS)==0)
				{
					retorno = 0;
				}
				break;
			default:
				break;
			}
		}
	}
	return retorno;
}
