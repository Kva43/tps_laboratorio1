#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Passenger.h"
#include <string.h>
#include "utn.h"


static int isValidNombre(char* cadena,int longitud);
static int esNumerica(char* cadena, int limite);
static int esFlotante(char* cadena);
static int esAlfanumerica(char* cadena,int longitud);

Passenger* Passenger_new()
{
	Passenger* auxiliarP = NULL;
	auxiliarP = (Passenger*) malloc(sizeof(Passenger));
	return auxiliarP;
}

Passenger* Passenger_newParametrosTxt(char* idStr,char* nombreStr,char* apellidoStr, char* precioStr,char* tipoPasajeroStr, char* codigoDeVueloStr, char* estadoVuelo)
{
	Passenger* this = NULL;
	this = Passenger_new();
	if(this != NULL && idStr != NULL && nombreStr != NULL && apellidoStr != NULL && precioStr != NULL && codigoDeVueloStr != NULL && tipoPasajeroStr != NULL && estadoVuelo != NULL)
	{
		if(	Passenger_setIdTxt(this,idStr) == -1 ||
			Passenger_setNombre(this,nombreStr) == -1 ||
			Passenger_setApellido(this,apellidoStr) == -1 ||
			Passenger_setPrecioTxt(this,precioStr) == -1 ||
			Passenger_setCodigoVuelo(this,codigoDeVueloStr) == -1 ||
			Passenger_setTipoPasajero(this,tipoPasajeroStr) == -1 ||
			Passenger_setEstadoVuelo(this, estadoVuelo) == -1)
		{
			Passenger_delete(this);
			this = NULL;
		}
	}
	return this;
}

Passenger* Passenger_newParametros(int id,char* nombreStr,char* apellidoStr, float precio,char* tipoPasajeroStr, char* codigoDeVueloStr, char* estadoVuelo)
{
	Passenger* this = NULL;
	this = Passenger_new();
	if(this != NULL && id >= 0 && nombreStr != NULL && apellidoStr != NULL && precio > 0 && codigoDeVueloStr != NULL && tipoPasajeroStr != NULL && estadoVuelo != NULL)
	{
		if(	Passenger_setId(this,id) == -1 ||
			Passenger_setNombre(this,nombreStr) == -1 ||
			Passenger_setApellido(this,apellidoStr) == -1 ||
			Passenger_setPrecio(this,precio) == -1 ||
			Passenger_setCodigoVuelo(this,codigoDeVueloStr) == -1 ||
			Passenger_setTipoPasajero(this,tipoPasajeroStr) == -1 ||
			Passenger_setEstadoVuelo(this, estadoVuelo) == -1)
		{
			Passenger_delete(this);
			this = NULL;
		}
	}
	return this;
}

void Passenger_delete(Passenger* this)
{
	if(this != NULL)
	{
		free(this);
	}
}

int Passenger_setId(Passenger* this,int id)
{
	int retorno = -1;
	if(this != NULL && id >= 0)
	{
		retorno = 0;
		this->id = id;
	}
	return retorno;
}
int Passenger_setIdTxt(Passenger* this,char* id)
{
	int retorno = -1;
	if(this != NULL && id != NULL)
	{
		if(esNumerica(id,NOMBRE_LEN))
		{
			retorno = 0;
			this->id = atoi(id);
		}
	}
	return retorno;
}

int Passenger_getId(Passenger* this,int* id)
{
	int retorno = -1;
	if(this != NULL && id != NULL)
	{
		retorno = 0;
		*id = this->id;
	}
	return retorno;
}

int Passenger_setNombre(Passenger* this,char* nombre)
{
	int retorno = -1;
	if(this != NULL && nombre != NULL)
	{
		if(isValidNombre(nombre,NOMBRE_LEN))
		{
			retorno = 0;
			strncpy(this->nombre,nombre,NOMBRE_LEN);
		}
	}
	return retorno;
}
int Passenger_getNombre(Passenger* this,char* nombre)
{
	int retorno = -1;
	if(this != NULL && nombre != NULL)
	{
		retorno = 0;
		strncpy(nombre,this->nombre,NOMBRE_LEN);
	}
	return retorno;
}

int Passenger_setApellido(Passenger* this,char* apellido)
{
	int retorno = -1;
	if(this != NULL && apellido != NULL)
	{
		if(isValidNombre(apellido,APELLIDO_LEN))
		{
			retorno = 0;
			strncpy(this->apellido,apellido,APELLIDO_LEN);
		}
	}
	return retorno;
}
int Passenger_getApellido(Passenger* this,char* apellido)
{
	int retorno = -1;
	if(this != NULL && apellido != NULL)
	{
		retorno = 0;
		strncpy(apellido,this->apellido,APELLIDO_LEN);
	}
	return retorno;
}

int Passenger_setPrecio(Passenger* this,float precio)
{
	int retorno = -1;
	if(this != NULL && precio >= 0)
	{
		retorno = 0;
		this->precio = precio;
	}
	return retorno;
}

int Passenger_setPrecioTxt(Passenger* this,char* precio)
{
	int retorno = -1;
	if(this != NULL && precio != NULL)
	{
		if(esFlotante(precio))
		{
			retorno = 0;
			this->precio = atof(precio);
		}
	}
	return retorno;
}

int Passenger_getPrecio(Passenger* this,float* precio)
{
	int retorno = -1;
	if(this != NULL && precio != NULL)
	{
		retorno = 0;
		*precio = this->precio;
	}
	return retorno;
}

int Passenger_setCodigoVuelo(Passenger* this,char* codigoVuelo)
{
	int retorno = -1;
	if(this != NULL && codigoVuelo != NULL)
	{
		if(esAlfanumerica(codigoVuelo,NOMBRE_LEN))
		{
			retorno = 0;
			strncpy(this->codigoVuelo,codigoVuelo,NOMBRE_LEN);
		}
	}
	return retorno;
}
int Passenger_getCodigoVuelo(Passenger* this,char* codigoVuelo)
{
	int retorno = -1;
	if(this != NULL && codigoVuelo != NULL)
	{
		retorno = 0;
		strncpy(codigoVuelo,this->codigoVuelo,NOMBRE_LEN);
	}
	return retorno;
}

int Passenger_setTipoPasajero(Passenger* this,char* tipoPasajero)
{
	int retorno = -1;
	if(this != NULL && tipoPasajero != NULL)
	{
		if(esAlfanumerica(tipoPasajero,NOMBRE_LEN))
		{
			retorno = 0;
			strncpy(this->tipoPasajero,tipoPasajero,NOMBRE_LEN);
		}
	}
	return retorno;
}

int Passenger_getTipoPasajero(Passenger* this,char* tipoPasajero)
{
	int retorno = -1;
	if(this != NULL && tipoPasajero != NULL)
	{
		retorno = 0;
		strncpy(tipoPasajero,this->tipoPasajero,NOMBRE_LEN);
	}
	return retorno;
}


int Passenger_setEstadoVuelo(Passenger* this,char* estadoVuelo)
{
	int retorno = -1;
	if(this != NULL && estadoVuelo != NULL)
	{
		if(esAlfanumerica(estadoVuelo,NOMBRE_LEN))
		{
			retorno = 0;
			strncpy(this->estadoVuelo,estadoVuelo,NOMBRE_LEN);
		}
	}
	return retorno;
}
int Passenger_getEstadoVuelo(Passenger* this,char* estadoVuelo)
{
	int retorno = -1;
	if(this != NULL && estadoVuelo != NULL)
	{
		retorno = 0;
		strncpy(estadoVuelo,this->estadoVuelo,NOMBRE_LEN);
	}
	return retorno;
}

/**
 * \brief Verifica si la cadena ingresada es un nombre valido
 * \param cadena Cadena de caracteres a ser analizada
 * \return Retorna 1 (verdadero) si la cadena es valida y 0 (falso) si no lo es
 *
 */
static int isValidNombre(char* cadena,int longitud)
{
	int i=0;
	int retorno = 1;

	if(cadena != NULL && longitud > 0)
	{
		for(i=0 ; cadena[i] != '\0' && i < longitud; i++)
		{
			if((cadena[i] < 'A' || cadena[i] > 'Z' ) && (cadena[i] < 'a' || cadena[i] > 'z' ))
			{
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}

/**
 * \brief Verifica si la cadena ingresada es numerica
 * \param cadena Cadena de caracteres a ser analizada
 * \return Retorna 1 (verdadero) si la cadena es numerica, 0 (falso) si no lo es y -1 en caso de error
 *
 */
static int esNumerica(char* cadena, int limite)
{
	int retorno = -1; // ERROR
	int i;
	if(cadena != NULL && limite > 0)
	{
		retorno = 1; // VERDADERO
		for(i=0;i<limite && cadena[i] != '\0';i++)
		{
			if(i==0 && (cadena[i] == '+' || cadena[i] == '-'))
			{
				continue;
			}
			if(cadena[i] < '0'||cadena[i] > '9')
			{
				retorno = 0;
				break;
			}
			//CONTINUE
		}
		//BREAK
	}
	return retorno;
}

/**
 * \brief Verifica si la cadena ingresada es flotante
 * \param cadena Cadena de caracteres a ser analizada
 * \return Retorna 1 (vardadero) si la cadena es flotante y 0 (falso) si no lo es
 *
 */
static int esFlotante(char* cadena)
{
	int i=0;
	int retorno = 1;
	int contadorPuntos=0;

	if(cadena != NULL && strlen(cadena) > 0)
	{
		for(i=0 ; cadena[i] != '\0'; i++)
		{
			if(i==0 && (cadena[i] == '-' || cadena[i] == '+'))
			{
				continue;
			}
			if(cadena[i] < '0' || cadena[i] > '9' )
			{
				if(cadena[i] == '.' && contadorPuntos == 0)
				{
					contadorPuntos++;
				}
				else
				{
					retorno = 0;
					break;
				}
			}
		}
	}
	return retorno;
}

static int esAlfanumerica(char* cadena,int longitud)
{
	int i=0;
	int retorno = 1;

	if(cadena != NULL && longitud > 0)
	{
		for(i=0 ; cadena[i] != '\0' && i < longitud; i++)
		{
			if((cadena[i] < 'A' || cadena[i] > 'Z' ) && (cadena[i] < 'a' || cadena[i] > 'z' ) && (cadena[i] < '0' || cadena[i] > '9'))
			{
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}

/*
 * #include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Controller.h"
#include "utn.h"
#include "Servicios.h"
#include "LinkedList.h"

static int isValidNombre(char* cadena,int longitud);
static int esNumerica(char* cadena, int limite);
static int esFlotante(char* cadena);

Servicios* new()
{
	Servicios* auxiliarP = NULL;
	auxiliarP = (Servicios*) malloc(sizeof(Servicios));
	return auxiliarP;
}

Servicios* newParametros(char* idStr,char* descripcion,char* Tipo ,char* precioUnitario,char* Cantidad,char* TotalServicio)
{
	Servicios* this;
	this = new();
	if(this != NULL && idStr != NULL && descripcion != NULL && Tipo != NULL && precioUnitario != NULL && Cantidad != NULL && TotalServicio != NULL)
	{

		 if(setIdTxt(this,idStr) == -1 ||
			setDescripcion(this,descripcion) == -1 ||
			setTipoTxt(this, Tipo) == -1 ||
			setFlotanteTxt(this, precioUnitario) == -1 ||
			setCantidadTxt(this, Cantidad) == -1 ||
			setTotalServicioTxt(this,TotalServicio) == -1)
		{
			delete(this);
			this = NULL;
		}
	}
	return this;
}

void delete(Servicios* this)
{
	if(this != NULL)
	{
		free(this);
	}
}

int setId(Servicios* this,int id)
{
	int retorno = -1;
	if(this != NULL && id >= 0)
	{
		retorno = 0;
		this->id_servicio = id;
	}
	return retorno;
}

int setIdTxt(Servicios* this,char* id)
{
	int retorno = -1;
	if(this != NULL && id != NULL)
	{
		if(esNumerica(id,CHAR_LEN)==0)
		{
			retorno = 0;
			this->id_servicio = atoi(id);
		}
	}
	return retorno;
}

int getId(Servicios* this,int* id)
{
	int retorno = -1;
	if(this != NULL && id != NULL)
	{
		retorno = 0;
		*id = this->id_servicio;
	}
	return retorno;
}

int setDescripcion(Servicios* this,char* descripcion)
{
	int retorno = -1;
	if(this != NULL && descripcion != NULL)
	{
		if(isValidNombre(descripcion,CHAR_LEN))
		{
			retorno = 0;
			strncpy(this->descripcion,descripcion,CHAR_LEN);
		}
	}
	return retorno;
}
int getDescripcion(Servicios* this,char* descripcion)
{
	int retorno = -1;
	if(this != NULL && descripcion != NULL)
	{
		retorno = 0;
		strncpy(descripcion,this->descripcion,CHAR_LEN);
	}
	return retorno;
}

int setTipo(Servicios* this,int tipo) //asasdasd
{
	int retorno = -1;
	if(this != NULL && tipo > 0)
	{
		retorno = 0;
		this->tipo = tipo;
	}
	return retorno;
}

int setTipoTxt(Servicios* this,char* tipo)
{
	int retorno = -1;
	if(this != NULL && tipo != NULL)
	{
		if(esNumerica(tipo,CHAR_LEN)==0)
		{
			retorno = 0;
			this->tipo = atoi(tipo);
		}
	}
	return retorno;
}

int getTipo(Servicios* this, int* tipo)
{
	int retorno = -1;
	if(this != NULL && tipo != NULL)
	{
		retorno = 0;
		*tipo = this->tipo;
	}
	return retorno;
}

int setFlotante(Servicios* this,float flotante) //modificar
{
	int retorno = -1;
	if(this != NULL && flotante >= 0)
	{
		retorno = 0;
		this->precioUnitario = flotante;
	}
	return retorno;
}

int setFlotanteTxt(Servicios* this,char* precio)
{
	int retorno = -1;
	if(this != NULL && precio != NULL)
	{
		if(esFlotante(precio) == 0)
		{
			retorno = 0;
			this->precioUnitario = atof(precio);
		}
	}
	return retorno;
}

int getFlotante(Servicios* this,char* precio)
{
	int retorno = -1;
	if(this != NULL && precio != NULL)
	{
		retorno = 0;
		*precio = this->precioUnitario;
	}
	return retorno;
}

int setCantidad(Servicios* this,int cantidad)
{
	int retorno = -1;
	if(this != NULL && cantidad > 0)
	{
		retorno = 0;
		this->cantidad = cantidad;
	}
	return retorno;
}

int setCantidadTxt(Servicios* this,char* cantidad)
{
	int retorno = -1;
	if(this != NULL && cantidad != NULL)
	{
		if(esNumerica(cantidad,CHAR_LEN)==0)
		{
			retorno = 0;
			this->cantidad = atoi(cantidad);
		}
	}
	return retorno;
}

int getCantidad(Servicios* this,int* cantidad)
{
	int retorno = -1;
	if(this != NULL && cantidad != NULL)
	{
		retorno = 0;
		*cantidad = this->cantidad;
	}
	return retorno;
}

int setTotalServicio(Servicios* this,int totalServicio) //modificar
{
	int retorno = -1;
	if(this != NULL && totalServicio >= 0)
	{
		retorno = 0;
		this->totalServicio = totalServicio;
	}
	return retorno;
}

int setTotalServicioTxt(Servicios* this,char* totalServicio)
{
	int retorno = -1;
	if(this != NULL && totalServicio != NULL)
	{
		if(esNumerica(totalServicio,CHAR_LEN) == 0)
		{
			retorno = 0;
			this->totalServicio = atoi(totalServicio);
		}
	}
	return retorno;
}

int getTotalServicio(Servicios* this,int* totalServicio)
{
	int retorno = -1;
	if(this != NULL && totalServicio != NULL)
	{
		retorno = 0;
		*totalServicio = this->totalServicio;
	}
	return retorno;
}

*/
/**
 * \brief Verifica si la cadena ingresada es un nombre valido
 * \param cadena Cadena de caracteres a ser analizada
 * \return Retorna 1 (verdadero) si la cadena es valida y 0 (falso) si no lo es
 *
 */
//static int isValidNombre(char* cadena,int longitud)
//{
//	int i=0;
//	int retorno = -1;
//
//	if(cadena != NULL && longitud > 0)
//	{
//		for(i=0 ; cadena[i] != '\0' && i < longitud; i++)
//		{
//			if((cadena[i] < 'A' || cadena[i] > 'Z' ) && (cadena[i] < 'a' || cadena[i] > 'z' ))
//			{
//				retorno = 0;
//				break;
//			}
//		}
//	}
//	return retorno;
//}

/**
 * \brief Verifica si la cadena ingresada es numerica
 * \param cadena Cadena de caracteres a ser analizada
 * \return Retorna 1 (verdadero) si la cadena es numerica, 0 (falso) si no lo es y -1 en caso de error
 *
 */
//static int esNumerica(char* cadena, int limite)
//{
//	int retorno = -1; // ERROR
//	int i;
//	if(cadena != NULL && limite > 0)
//	{
//		retorno = 0; // VERDADERO
//		for(i=0;i<limite && cadena[i] != '\0';i++)
//		{
//			if(i==0 && (cadena[i] == '+' || cadena[i] == '-'))
//			{
//				continue;
//			}
//			if(cadena[i] < '0'||cadena[i] > '9')
//			{
//				retorno = 1;
//				break;
//			}
//			//CONTINUE
//		}
//		//BREAK
//	}
//	return retorno;
//}

/**
 * \brief Verifica si la cadena ingresada es flotante
 * \param cadena Cadena de caracteres a ser analizada
 * \return Retorna -1 (falso) si la cadena es flotante y 0 (verdadero) si no lo es
 *
 */
//static int esFlotante(char* cadena)
//{
//	int i=0;
//	int retorno = 0;
//	int contadorPuntos=0;
//
//	if(cadena != NULL && strlen(cadena) > 0)
//	{
//		for(i=0 ; cadena[i] != '\0'; i++)
//		{
//			if(i==0 && (cadena[i] == '-' || cadena[i] == '+'))
//			{
//				continue;
//			}
//			if(cadena[i] < '0' || cadena[i] > '9' )
//			{
//				if(cadena[i] == '.' && contadorPuntos == 0)
//				{
//					contadorPuntos++;
//				}
//				else
//				{
//					retorno = -1;
//					break;
//				}
//			}
//		}
//	}
//	return retorno;
//}


