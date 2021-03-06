#include <stdio.h>
#include <stdlib.h>
#include "Controller.h"
#include "LinkedList.h"
#include "Passenger.h"
#include "utn.h"

/** \brief Parsea los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int parser_FromText(FILE* pFile , LinkedList* pArrayListServicios)
{
	int retorno = -1;
	Passenger* puntero = NULL;
	char id[4096];
	char nombre[4096];
	char apellido[4096];
	char precio[4096];
	char tipoPasajero[4096];
	char codigoVuelo[4096];
	char estadoVuelo[4096];
	int idContador = 0;

	if(pFile != NULL)
	{
		do
		{
			if(fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",id,nombre,apellido,precio,tipoPasajero,codigoVuelo, estadoVuelo) == 7)
			{
				puntero = Passenger_newParametrosTxt(id,nombre,apellido,precio,tipoPasajero,codigoVuelo,estadoVuelo);
				if(puntero != NULL)
				{
					if(ll_add(pArrayListServicios, puntero)==0)
					{
						retorno = idContador++;;
						puntero->isEmpty = -1;
					}
				}
			}
			else
			{
				break;
			}
		} while(feof(pFile) == 0);
	}
	fclose(pFile);
	return retorno;
}

int parser_FromBinary(FILE* pFile , LinkedList* pArrayListPassenger)
{
	int retorno = -1;
	return retorno;
}
