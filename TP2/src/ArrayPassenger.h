#ifndef ARRAYPASSENGER_H_
#define ARRAYPASSENGER_H_

#define TAM_CHAR 51
#define TAM_FLYCODE 10

typedef struct
{
	int id;
	char name[TAM_CHAR];
	char lastName[TAM_CHAR];
	float price;
	char flycode[TAM_FLYCODE];
	int typePassenger;
	int statusFlight;
	int isEmpty;
} Passenger;

#endif /* ARRAYPASSENGER_H_ */

/** \brief 	To indicate that all position in the array are empty,
 * 			this function put the flag (isEmpty) in TRUE in all position of the array
* \param list Passenger* Pointer to array of passenger
* \param len int Array length
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int initPassengers(Passenger* list, int len);

/**
 * Imprimi solo la posicion que recibo por el parametro i
 * @param list		puntero a passenger
 * @param i			posicion que imprimira
 * @return			int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 */
int printPositionPassenger(Passenger* list, int i);

/** \brief add in a existing list of passengers the values received as parameters in the first empty position
 *
* \param list passenger*
* \param len int
* \param id int
* \param name[] char
* \param lastName[] char
* \param price float
* \param typePassenger int
* \param flycode[] char
* \return int Return (-1) if Error [Invalid length or NULL pointer or without
free space] - (0) if Ok*/
int addPassenger(Passenger* list, int len, int id, char name[],char lastName[],float price, char flycode[], int typePassenger, int statusFlight);



/** \brief find a Passenger by Id en returns the index position in array.
*
* \param list Passenger*
* \param len int
* \param id int
* \return Return passenger index position or (-1) if [Invalid length or
NULL pointer received or passenger not found]
*
*/
int findPassengerById(Passenger* list, int len,int id);
/** \brief Remove a Passenger by Id (put isEmpty Flag in 1)
*
* \param list Passenger*
* \param len int
* \param id int
* \return int Return (-1) if Error [Invalid length or NULL pointer or if can't
find a passenger] - (0) if Ok
*
*/
int removePassenger(Passenger* list, int len, int id);
/** \brief Sort the elements in the array of passengers, the argument order
indicate UP or DOWN order
*
* \param list Passenger*
* \param len int
* \param order int [1] indicate UP - [0] indicate DOWN
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int sortPassengers(Passenger* list, int len, int order);

/** \brief print the content of passengers array
*
* \param list Passenger*
* \param length int
* \return int
*
*/
int printPassenger(Passenger* list, int length);

/**
 * Calculo el precio total de todos los vuelos de los clientes
 * @param list		Passenger*
 * @param len		tama?o del array
 * @param total		puntero a la variable que retornara su valor
 * @return			int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 */
int totalPrice(Passenger* list, int len, float* total);

/**
 * Calculo el promedio de todos los precios de vuelos
 * @param len		tama?o del array
 * @param total		valor que recibe para realizar el calculo
 * @param resul		puntero a la variable que retornara su valor
 * @return			int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 */
int promedioPrice(int len, float total, float*resul);

/**
 * Calculo cuantos pasajeros superaron el promedio antes mencionado
 * @param list			Passenger*
 * @param len			tama?o del array
 * @param promedio		valor que recibe para realizar el calculo
 * @param acum			puntero a la variable que retornara su valor
 * @return				int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 */
int superanPricePromedio(Passenger* list, int len, float promedio, int*acum);

/**
 * Ordeno de mayor a menor (o viceversa) seg?n el dato recibido por el usuario los codigos de vuelos
 * @param list		Passenger*
 * @param len		tama?o del array
 * @param order		valor que recibe para realizar un orden u otro
 * @return			int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 */
int sortPassengersFlyCode(Passenger* list, int len, int order);


