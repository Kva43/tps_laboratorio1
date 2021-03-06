#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayPassenger.h"
#include "utn.h"

int initPassengers(Passenger* list, int len)
{
	int retorno = -1;
	int i;
	if(list != NULL && len > 0)
	{
		for(i=0; i<len ;i++)
		{
			list[i].isEmpty = 0;
		}
		retorno = 0;
	}
	return retorno;
}

int addPassenger(Passenger* list, int len, int id, char name[],char lastName[],float price, char flycode[], int typePassenger, int statusFlight)
{
	int retorno = -1;

	if(list != NULL && name != NULL && lastName != NULL && flycode != NULL && id >= 0 && price > 0 && typePassenger >= 0 && statusFlight >= 0)
	{
		for(int i=0; i<len; i++)
		{
			if(list[i].isEmpty == 0)
			{
				list[i].id = id;
				strncpy(list[i].name, name,TAM_CHAR);
				strncpy(list[i].lastName, lastName,TAM_CHAR);
				list[i].price = price;
				strncpy(list[i].flycode, flycode,TAM_CHAR);
				list[i].typePassenger = typePassenger;
				list[i].statusFlight = statusFlight;
				list[i].isEmpty = -1;
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}

int printPassenger(Passenger* list, int len)
{
	int retorno = -1;
	for(int i=0; i<len ;i++)
	{
		if(list[i].isEmpty == -1)
		{
			retorno = 0;
			printf("\n%d. %s - %s - %.1f - %s - %d - %d",list[i].id,list[i].name,list[i].lastName,list[i].price,list[i].flycode,list[i].typePassenger,list[i].statusFlight);
		}
	}
	return retorno;
}

int printPositionPassenger(Passenger* list, int i)
{
	int retorno = -1;

	if(list != NULL && i >= 0 && list[i].isEmpty == -1)
	{
		retorno = 0;
		printf("\nID: %d - Nombre: %s - Apellido: %s - Precio: %.2f - Codigo de vuelo: %s - Tipo de pasajero: %d - Estado de vuelo: %d\n",list[i].id,list[i].name,list[i].lastName,list[i].price,list[i].flycode,list[i].typePassenger,list[i].statusFlight);
	}
	return retorno;
}

int findPassengerById(Passenger* list, int len, int id)
{
	int retorno = -1;
	int i;
	int auxOpcion;
	if(list != NULL && len >= 0 && id >= 0)
	{
		for(i=0; i<len ;i++)
		{
			if(list[i].id == id)
			{
				printPositionPassenger(list, i);
				if(utn_getNumero(&auxOpcion, "\nQue desea modificar: \n1.(nombre) 2.(apellido) 3.(precio) 4.(Codigo de vuelo) 5.(Tipo de pasajero) 6.(Estado de Vuelo)\n", "Error", 1, 6, 3)==0)
				{
					switch(auxOpcion)
					{
					case 1:
						if(utn_getNombre(list[i].name, TAM_CHAR, "\nNombre: ", "\nError", 2)==0)
						{
							retorno = 0;
							break;
						}
						break;
					case 2:
						if(utn_getNombre(list[i].lastName, TAM_CHAR, "\nApellido: ", "\nError", 2)==0)
						{
							retorno = 0;
							break;
						}
						break;
					case 3:
						if(utn_getNumeroFlotante(&list[i].price, "\nPrecio: ", "\nError", 1, 99999, 2)==0)
						{
							retorno = 0;
							break;
						}
						break;
					case 4:
						if(utn_getAlfanumerica(list[i].flycode, TAM_FLYCODE, "\nCodigo de vuelo: ", "\nError", 2)==0)
						{
							retorno = 0;
							break;
						}
						break;
					case 5:
						if(utn_getNumero(&list[i].typePassenger, "\nTipo de pasajero: ", "\nError", 1, 3, 3)==0)
						{
							retorno = 0;
							break;
						}
						break;
					case 6:
						if(utn_getNumero(&list[i].statusFlight, "\nEstado de vuelo: ", "\nError", 1, 2, 2) == 0)
						{
							retorno = 0;
							break;
						}
						break;
					}
				}
			}
		}
	}
	return retorno;
}

int removePassenger(Passenger* list, int len, int id)
{
	int retorno = -1;
	int i;
	char res;
	if(list != NULL && len >= 0 && id >= 0)
	{
		for(i=0; i<len ;i++)
		{
			if(list[i].id == id && list[i].isEmpty == -1)
			{
				printPositionPassenger(list, i);
				printf("\nEliminar pasajero? s/n\n");
				scanf("%c",&res);
				if(res=='s')
				{
					retorno = 0;
					list[i].isEmpty = 0;
					break;
				}
			}
		}
	}
	return retorno;
}

int sortPassengers(Passenger* list, int len, int order)
{
	int ret=-1;
	int i;
	int flagSwap;
	Passenger buffer;

	if(list != NULL && len>=0 && order <= 1 && order >= 0)
	{
		if(order==1)
		{
			do
			{
				flagSwap = 0;
				for(i=0; i<len-1 ;i++)
				{
					if((strncmp(list[i].lastName,list[i+1].lastName, TAM_CHAR)>0)
					|| ((strncmp(list[i].lastName,list[i+1].lastName, TAM_CHAR)==0) && list[i].typePassenger < list[i+1].typePassenger))
					{
						flagSwap=1;
						buffer=list[i];
						list[i]=list[i+1];
						list[i+1]=buffer;
						ret = 0;
					}
				}
				len--;
			} while(flagSwap);
		}
		else if(order == 0)
		{
			do
			{
				flagSwap = 0;
				for(i=0; i<len-1 ;i++)
				{
					if((strncmp(list[i].lastName,list[i+1].lastName, TAM_CHAR) < 0)
					|| ((strncmp(list[i].lastName,list[i+1].lastName, TAM_CHAR)==0) && list[i].typePassenger > list[i+1].typePassenger))
					{
						flagSwap = 1;
						buffer=list[i];
						list[i]=list[i+1];
						list[i+1]=buffer;
						ret = 0;
					}
				}
				len--;
			} while(flagSwap);
		}
	}
	return ret;
}

int totalPrice(Passenger* list, int len, float* total)
{
	int retorno =- 1;
	float aux = 0;
	if(list != NULL && len > 0 && total != NULL)
	{
		for(int i=0; i<len ;i++)
		{
			if(list[i].isEmpty == -1)
			{
				aux = aux + list[i].price;
			}
		}
		*total = aux;
		retorno = 0;
	}
	return retorno;
}

int promedioPrice(int len, float total, float*promedio)
{
	int retorno= - 1;
	if(len > 0 && total > 0 && promedio != NULL)
	{
		*promedio = total / len;
		retorno = 0;
	}
	return retorno;
}

int superanPricePromedio(Passenger* list, int len, float promedio, int* acum)
{
	int retorno = -1;
	int aux = 0;
	if(list != NULL && len > 0 && promedio > 0 && acum != NULL)
	{
		for(int i=0;i<len;i++)
		{
			if(list[i].isEmpty == -1)
			{
				if(list[i].price > promedio)
				{
					aux++;
				}
			}
			*acum = aux;
			retorno = 0;
		}
	}
	return retorno;
}

int sortPassengersFlyCode(Passenger* list, int len, int order)
{
	int retorno = -1;
	int i;
	int flagSwap;
	Passenger buffer;

	if(list != NULL && len >= 0)
	{
		if(order == 1 || order == 0)
		{
			do
			{
				flagSwap = 0;
				for(i=0;i<len-1;i++)
				{
					if((strncmp(list[i].flycode,list[i+1].flycode, TAM_CHAR) > 0) || (strncmp(list[i].flycode,list[i+1].flycode, TAM_CHAR) < 0))
					{
						flagSwap=1;
						buffer=list[i];
						list[i]=list[i+1];
						list[i+1]=buffer;
						retorno=0;
					}
				}
				len--;
			} while(flagSwap);
		}
	}
	return retorno;
}
