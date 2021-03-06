#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayPassenger.h"
#include "utn.h"
#include "Controller_passenger.h"
#define CANT_PASAJEROS 100

int main(void)
{
	setbuf(stdout, NULL);

	int opciones;
	int idModificar;
	int id = 0;
	int idBaja;

	Passenger passenger[CANT_PASAJEROS];

	if(initPassengers(passenger, CANT_PASAJEROS)==0)
	{
		printf("Se inicializo correctamente\n");
	}
	do
	{
		if(utn_getNumero(&opciones, "\n\n1.ALTAS\n2.MODIFICAR\n3.BAJA\n4.INFORMAR\n", "\nError\n", 1, 4, 2)==0)
		{
			switch(opciones)
			{
				case 1:
					if(Controller_passengerAdd(passenger, CANT_PASAJEROS, id)==0)
					{
						id++;
						printf("\nCarga realizada\n");
					}
					break;
				case 2:
					if(utn_getNumero(&idModificar,"ID de empleado a modificar: ","\nERROR\n", 0, 99, 2) == 0 &&
					findPassengerById(passenger,CANT_PASAJEROS, idModificar) == 0)
					{
						printf("\nSe modifico correctamente\n");
					}
					break;
				case 3:
					if(utn_getNumero(&idBaja, "ID del empleado a dar de baja: ", "\nERROR\n", 0, 99, 2) == 0 &&
					removePassenger(passenger, CANT_PASAJEROS, idBaja) == 0)
					{
						printf("\nSe elimino con exito\n");
					}
					else
					{
						printf("\nSin datos que eliminar\n");
					}
					break;
				case 4:
					Controller_passengerPrint(passenger, CANT_PASAJEROS, id);
					break;
			}
		}
	} while(opciones != 5);
	return 0;
}
