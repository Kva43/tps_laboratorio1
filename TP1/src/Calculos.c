#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#define PRECIO_BTC 46064.06

static int vuelo_tipo1(float* precio, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);
static int vuelo_tipo2(float* precio, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);
static int precio_calcularDebito(float precio1, float precio2, float* precio1Descuento, float* precio2Descuento);
static int precio_calcularCredito(float precio1, float precio2, float* precio1Descuento, float* precio2Descuento);
static int precio_calcularBTC(float precio1, float precio2, float* precio1BTC, float* precio2BTC);
static int precio_MostrarUnitario(float precio1, float precio2, float* precio1Unitario, float* precio2Unitario);
static int precio_MostrarDiferencia(float precio1, float precio2, float* diferenciaDePrecios);

int km_get(float* valor, char* mensaje, char* mensajeError, float minimo, float maximo, int reintentos)
{
	int retorno = -1;
	float num;
	if(valor != NULL && mensaje != NULL && mensajeError != NULL && minimo > 0 && maximo < 1000000 && reintentos > 0 &&
	utn_getNumeroFlotante(&num, mensaje, mensajeError, minimo, maximo, reintentos)==0)
	{
		retorno = 0;
		*valor = num;
	}
	return retorno;
}


int vuelo_get(float* precio1, float* precio2, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos)
{
	int retorno = -1;
	int opcion;
	if(precio1 != NULL && precio2 != NULL && mensaje != NULL && mensajeError != NULL && minimo > 0 && maximo < 10 && reintentos > 0 &&
	utn_getNumero(&opcion, mensaje, mensajeError, minimo, maximo, reintentos)==0)
	{
		switch(opcion)
		{
		case 1:
			if(vuelo_tipo1(precio1, "\nPrecio vuelo Aerolineas: ","\nERROR. Ingrese un numero entre 1000 y 9999999",1000,9999999,2)==0)
			{
				retorno = 0;
			}
			break;
		case 2:
			if(vuelo_tipo2(precio2, "\nPrecio vuelo Latam: ","\nERROR. Ingrese un numero entre 1000 y 9999999",1000,9999999,2)==0)
			{
				retorno = 0;
			}
			break;
		}
	}
	return retorno;
}

static int vuelo_tipo1(float* precio, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos)
{
	int retorno = -1;
	float aux;
	if(precio != NULL && mensaje != NULL && mensajeError != NULL && minimo > 0 && maximo <= 9999999 && reintentos > 0)
	{
		if(utn_getNumeroFlotante(&aux, mensaje, mensajeError, minimo, maximo, reintentos)==0)
		{
			*precio = aux;
			retorno = 0;
		}
	}
	return retorno;
}

static int vuelo_tipo2(float* precio, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos)
{
	int retorno = -1;
	float aux;
	if(precio != NULL && mensaje != NULL && mensajeError != NULL && minimo > 0 && maximo <= 9999999 && reintentos > 0)
	{
		if(utn_getNumeroFlotante(&aux, mensaje, mensajeError, minimo, maximo, reintentos)==0)
		{
			*precio = aux;
			retorno = 0;
		}
	}
	return retorno;
}

int precio_calcularTodo(float precio1, float precio2, float* precio1DesDebito, float* precio2DesDebito, float* precio1DesCredito, float* precio2DesCredito, float* precio1BTC, float* precio2BTC, float* precio1Unitario, float* precio2Unitario, float* diferenciaDePrecios)
{
	int retorno = -1;
	if(precio_calcularDebito(precio1, precio2, precio1DesDebito, precio2DesDebito) == 0 &&
		precio_calcularCredito(precio1, precio2, precio1DesCredito, precio2DesCredito) == 0 &&
		precio_calcularBTC(precio1, precio2, precio1BTC, precio2BTC) == 0 &&
		precio_MostrarUnitario(precio1, precio2, precio1Unitario, precio2Unitario) == 0 &&
		precio_MostrarDiferencia(precio1, precio2, diferenciaDePrecios) == 0)
	{
		retorno = 0;
	}
	return retorno;
}

static int precio_calcularDebito(float precio1, float precio2, float* precio1Descuento, float* precio2Descuento)
{
	int retorno = -1;
	if(precio1 > 0 && precio2 > 0 && precio1Descuento != NULL && precio2Descuento != NULL)
	{
		retorno = 0;
		*precio1Descuento = precio1 - (precio1 * 0.1);
		*precio2Descuento = precio2 - (precio2 * 0.1);
	}
	return retorno;
}

static int precio_calcularCredito(float precio1, float precio2, float* precio1Descuento, float* precio2Descuento)
{
	int retorno = -1;
	if(precio1 > 0 && precio2 > 0 && precio1Descuento != NULL && precio2Descuento != NULL)
	{
		retorno = 0;
		*precio1Descuento = precio1 + (precio1 * 0.25);
		*precio2Descuento = precio2 + (precio2 * 0.25);
	}
	return retorno;
}

static int precio_calcularBTC(float precio1, float precio2, float* precio1BTC, float* precio2BTC)
{
	int retorno = -1;
	if(precio1 > 0 && precio2 > 0 && precio1BTC != NULL && precio2BTC != NULL)
	{
		retorno = 0;
		*precio1BTC = precio1 / PRECIO_BTC;
		*precio2BTC = precio2 / PRECIO_BTC;
	}
	return retorno;
}

static int precio_MostrarUnitario(float precio1, float precio2, float* precio1Unitario, float* precio2Unitario)
{
	int retorno = -1;
	if(precio1 > 0 && precio2 > 0 && precio1Unitario != NULL && precio2Unitario != NULL)
	{
		retorno = 0;
		*precio1Unitario = precio1;
		*precio2Unitario = precio2;
	}
	return retorno;
}

static int precio_MostrarDiferencia(float precio1, float precio2, float* diferenciaDePrecios)
{
	int retorno = -1;
	if(precio1 > 0 && precio2 > 0 && diferenciaDePrecios != NULL)
	{
		if(precio1<precio2)
		{
			retorno = 0;
			*diferenciaDePrecios = precio2 - precio1;
		}
		else
		{
			retorno = 0;
			*diferenciaDePrecios = precio1 - precio2;
		}
	}
	return retorno;
}

int precio_imprimir(float precio1, float precio2, float precio1Debito, float precio2Debito, float precio1Credito, float precio2Credito, float precio1BTC, float precio2BTC, float precio1Unitario, float precio2Unitario, float diferenciaDePrecios)
{
	int retorno = -1;
	if(precio1Debito > 0 && precio2Debito > 0 && precio1Credito > 0 &&  precio2Credito > 0 && precio1BTC > 0 && precio2BTC > 0 && precio1Unitario > 0 && precio2Unitario > 0 && diferenciaDePrecios > 0)
	{
		retorno = 0;
		printf("\nLatam: %.2f\na)Precio con tarjeta de debito: %.2f\nb) Precio con tarjeta de crédito: %.2f\nc) Precio pagando con bitcoin: %.6f\nd) Precio unitario: %.2f", precio1, precio1Debito,precio1Credito, precio1BTC, precio1Unitario);
		printf("\n\nAerlineas: %.2f\na)Precio con tarjeta de debito: %.2f\nb) Precio con tarjeta de crédito: %.2f\nc) Precio pagando con bitcoin: %.6f\nd) Precio unitario: %.2f", precio2, precio2Debito,precio2Credito, precio2BTC, precio2Unitario);
		printf("\nLa diferencia de precio es: %.2f",diferenciaDePrecios);
	}
	return retorno;
}


int precio_cargaForzada(void)
{
	int retorno = -1;
	int kilometros = 7090;
	float precio1 = 1335000.66;
	float precio1Debito = 120255.66;
	float precio1Credito = 150666.76;
	float precio1BTC = 33.66;
	float precio1Unitario = 10799.88;
	float diferenciaDePrecios = 30006.66;
	float precio2 = 1350000.76;
	float precio2Debito = 120255.66;
	float precio2Credito = 15066.76;
	float precio2BTC = 33.66;
	float precio2Unitario = 10799.88;

	printf("\nKMs Ingresados: %d\n",kilometros);
	if(precio_imprimir(precio1,precio2,precio1Debito, precio2Debito, precio1Credito, precio2Credito, precio1BTC, precio2BTC, precio1Unitario, precio2Unitario, diferenciaDePrecios)==0)
	{
		retorno = 0;
	}
	return retorno;
}


//int cargaForzada(char*impMensaje, char*impMensaje2)
//{
//
//	int km1=7090;
//	float precio1=162965;
//	float precio2=159339;
//
//	calcularCostos(precio1, precio2, &debito, &credito, &bitcoin, &unitario, &diferencia);
//	calcularCostos(precio2, precio1, &debito2, &credito2, &bitcoin2, &unitario2, &diferencia2);
//
//
//	mensaje2 = printf("KMs ingresados: %d",km1);
//	mensaje = printf("\nPrecio Aerolineas: %.2f\na) Precio con tarjeta de debito: $ %.2f\nb) Precio con tarjeta de credito: $ %.2f\nc) Precio pagando con bitcoin: $ %.5f\nd) Mostrar precio unitario: $ %.2f\n\nLa diferencia de precio es: $ %.2f\n\nPrecio Aerolineas: %.2f\na) Precio con tarjeta de debito: $ %.2f\nb) Precio con tarjeta de credito: $ %.2f\nc) Precio pagando con bitcoin: $ %.5f\nd) Mostrar precio unitario: $ %.2f\n\nLa diferencia de precio es: $ %.2f\n",precio1,debito,credito,bitcoin,unitario,diferencia,precio2,debito2,credito2,bitcoin2,unitario2,diferencia2);
//	*impMensaje = mensaje;
//	*impMensaje2 = mensaje2;
//	return 0;
//}


int validarPrecioIngresado(float*valor1, char*mensaje, char*mensajeError)
{
	float num;

	printf(mensaje);
	scanf("%f",&num);

	while(num<=0)
	{
		printf(mensajeError);
		scanf("%f",&num);
	}
	*valor1 = num;
	return 0;
}



