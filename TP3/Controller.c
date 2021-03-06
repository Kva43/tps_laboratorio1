#include <stdio.h>
#include <stdlib.h>
#include "Controller.h"
#include "LinkedList.h"
#include "parser.h"
#include "Passenger.h"
#include "utn.h"


/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListPassenger)
{
	FILE* pFile;
	int idMaximo;
	if(pArrayListPassenger != NULL && path != NULL)
	{
		pFile = fopen(path,"r");
		idMaximo = parser_FromText(pFile, pArrayListPassenger);
	}
	return idMaximo;
}

/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListPassenger)
{
    return 1;
}

/** \brief Alta de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */

int controller_addPassenger(LinkedList* pArrayListPassenger, int id)
{
	int retorno = -1;
	Passenger b;
	char nombre[CHAR_LEN];
	char apellido[CHAR_LEN];
	float precio;
	char tipoPasajero[CHAR_LEN];
	char codigoVuelo[CHAR_LEN];
	char estadoVuelo[CHAR_LEN];

	if(pArrayListPassenger != NULL && id >= 0 &&
	utn_getNombre(nombre, CHAR_LEN, "\nNombre?", "\nERROR\n", 2) == 0 &&
	utn_getNombre(apellido, CHAR_LEN, "\nApellido?", "\nERROR\n", 2) == 0 &&
	utn_getNumeroFlotante(&precio, "\nPrecio?", "\nERROR\n", 1, 900000, 2) == 0 &&
	utn_getAlfanumerica(tipoPasajero,CHAR_LEN, "\nTipo de pasajero?", "\nERROR\n", 2) == 0 &&
	utn_getAlfanumerica(codigoVuelo, CHAR_LEN, "\nCodigo de vuelo?", "\nERROR\n", 2) == 0 &&
	utn_getAlfanumerica(estadoVuelo, CHAR_LEN, "\nEstado de vuelo?", "\nERROR\n", 2) == 0)
	{
		if(Passenger_setId(&b, id) == 0 &&
		Passenger_setNombre(&b, nombre) == 0 &&
		Passenger_setApellido(&b, apellido) == 0 &&
		Passenger_setPrecio(&b, precio)== 0 &&
		Passenger_setTipoPasajero(&b, tipoPasajero) == 0 &&
		Passenger_setCodigoVuelo(&b, codigoVuelo) == 0 &&
		Passenger_setEstadoVuelo(&b, estadoVuelo) == 0)
		{
			if(ll_add(pArrayListPassenger, &b)==0)
			{
				retorno = 0;
			}
		}
	}
    return retorno;
}

/** \brief Modificar datos de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_editPassenger(LinkedList* pArrayListPassenger)
{
    return 1;
}

/** \brief Baja de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_removePassenger(LinkedList* pArrayListPassenger)
{
    return 1;
}

/** \brief Listar pasajeros
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_ListPassenger(LinkedList* pArrayListPassenger)
{
	int retorno = -1;
	int id;
	char nombre[CHAR_LEN];
	char apellido[CHAR_LEN];
	float precio;
	char tipoPasajero[CHAR_LEN];
	char codigoVuelo[CHAR_LEN];
	char estadoVuelo[CHAR_LEN];
	Passenger* b;
	if(pArrayListPassenger != NULL)
	{
		for(int i=0; i < ll_len(pArrayListPassenger) ;i++)
		{
			b = ll_get(pArrayListPassenger, i);
			if(Passenger_getId(b, &id) == 0 &&
				Passenger_getNombre(b, nombre) == 0 &&
				Passenger_getApellido(b, apellido) == 0 &&
				Passenger_getPrecio(b, &precio) == 0 &&
				Passenger_getTipoPasajero(b, tipoPasajero) == 0 &&
				Passenger_getCodigoVuelo(b, codigoVuelo) == 0 &&
				Passenger_getEstadoVuelo(b, estadoVuelo) == 0)
			{
				retorno = 0;
				printf("%d, %s, %s, %.1f, %s, %s, %s\n",id,nombre,apellido,precio,tipoPasajero,codigoVuelo,estadoVuelo);
			}
		}
	}
	return retorno;
}

/** \brief Ordenar pasajeros
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_sortPassenger(LinkedList* pArrayListPassenger)
{
    return 1;
}

/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListPassenger)
{
    return 1;
}

/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListPassenger)
{
    return 1;
}


