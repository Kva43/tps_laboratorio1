#ifndef FUNCIONESAUXILIARES_H_
#define FUNCIONESAUXILIARES_H_

/**
 * Pide un numero, si es valido, lo retorna por puntero a entero
 * @param valor			Puntero a entero donde se copiara el numero de la variable
 * @param mensaje		Mensaje que recibe por puntero e imprimira en pantalla
 * @param mensajeError	Mensaje de error que recibe por puntero e imprimira en pantalla
 * @param minimo		Valor minimo que acepta
 * @param maximo		Valor maximo que acepta
 * @param reintentos	Cantidad de reintentos que tendra el usuario de ingresar bien un valor
 * @return 				Retorno 0 (verdadero) , -1 (falso)
 */
int km_get(float* valor, char* mensaje, char* mensajeError, float minimo, float maximo, int reintentos);

/**
 *	Pregunta cual de las 2 empresas de vuelo quiere ingresar su precio
 * @param mensaje		Mensaje que recibe por puntero e imprimira en pantalla
 * @param mensajeError	Mensaje de error que recibe por puntero e imprimira en pantalla
 * @param minimo		Valor minimo que acepta
 * @param maximo		Valor maximo que acepta
 * @param reintentos	Cantidad de reintentos que tendra el usuario de ingresar bien un valor
 * @return				Retorno 0 (verdadero) , -1 (falso)
 */
int vuelo_get(float* precio1, float* precio2, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);

/**
 * Llama funciones esticas que indivualmente calculan el precio final que corresponde
 * @param precio1				valor 1 que entra por parametro
 * @param precio2				valor 2 que entra por parametro
 * @param precio1DesDebito		Puntero a la variable en la que retorna el valor correspondiente
 * @param precio2DesDebito		Puntero a la variable en la que retorna el valor correspondiente
 * @param precio1DesCredito		Puntero a la variable en la que retorna el valor correspondiente
 * @param precio2DesCredito		Puntero a la variable en la que retorna el valor correspondiente
 * @param precio1BTC			Puntero a la variable en la que retorna el valor correspondiente
 * @param precio2BTC			Puntero a la variable en la que retorna el valor correspondiente
 * @param precio1Unitario		Puntero a la variable en la que retorna el valor correspondiente
 * @param precio2Unitario		Puntero a la variable en la que retorna el valor correspondiente
 * @param diferenciaDePrecios	Puntero a la variable en la que retorna el valor correspondiente
 * @return						Retorno 0 (verdadero) , -1 (falso)
 */
int precio_calcularTodo(float precio1, float precio2, float* precio1DesDebito, float* precio2DesDebito, float* precio1DesCredito, float* precio2DesCredito, float* precio1BTC, float* precio2BTC, float* precio1Unitario, float* precio2Unitario, float* diferenciaDePrecios);

/**
 * Imprime todos los varores que recibe por parametro
 * @param precio1Debito			Valor que imprimira
 * @param precio2Debito			Valor que imprimira
 * @param precio1Credito		Valor que imprimira
 * @param precio2Credito		Valor que imprimira
 * @param precio1BTC			Valor que imprimira
 * @param precio2BTC			Valor que imprimira
 * @param precio1Unitario		Valor que imprimira
 * @param precio2Unitario		Valor que imprimira
 * @param diferenciaDePrecios	Valor que imprimira
 * @return						Retorno 0 (verdadero) , -1 (falso)
 */
int precio_imprimir(float precio1Debito, float precio2Debito, float precio1Credito, float precio2Credito, float precio1BTC, float precio2BTC, float precio1Unitario, float precio2Unitario, float diferenciaDePrecios);

/**
 * Imprime todos los valores declarados localmente
 * @return			Retorno 0 (verdadero) , -1 (falso)
 */
int precio_cargaForzada(void);

#endif /* FUNCIONESAUXILIARES_H_ */





