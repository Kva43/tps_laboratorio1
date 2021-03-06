#ifndef PASSENGER_H_
#define PASSENGER_H_
#define NOMBRE_LEN 50
#define APELLIDO_LEN 50

typedef struct
{
	int id;
	char nombre[50];
	char apellido[50];
	float precio;
	char tipoPasajero[50];
	char codigoVuelo[50];
	char estadoVuelo[50];
	int isEmpty;

}Passenger;

Passenger* Passenger_new();
Passenger* Passenger_newParametrosTxt(char* idStr,char* nombreStr,char* apellidoStr, char* precioStr,char* tipoPasajeroStr, char* codigoVueloStr, char* estadoVuelo);
Passenger* Passenger_newParametros(int idStr,char* nombreStr,char* apellidoStr, float precioStr,char* tipoPasajeroStr, char* codigoVueloStr, char* estadoVuelo);
void Passenger_delete();

int Passenger_setId(Passenger* this,int id);
int Passenger_setIdTxt(Passenger* this,char* id);
int Passenger_getId(Passenger* this,int* id);

int Passenger_setNombre(Passenger* this,char* nombre);
int Passenger_getNombre(Passenger* this,char* nombre);

int Passenger_setApellido(Passenger* this,char* apellido);
int Passenger_getApellido(Passenger* this,char* apellido);

int Passenger_setCodigoVuelo(Passenger* this,char* codigoVuelo);
int Passenger_getCodigoVuelo(Passenger* this,char* codigoVuelo);

int Passenger_setTipoPasajero(Passenger* this,char* tipoPasajero);
int Passenger_getTipoPasajero(Passenger* this,char* tipoPasajero);

int Passenger_setEstadoVuelo(Passenger* this,char* estadoVuelo);
int Passenger_getEstadoVuelo(Passenger* this,char* estadoVuelo);

int Passenger_setPrecio(Passenger* this,float precio);
int Passenger_setPrecioTxt(Passenger* this,char* precio);
int Passenger_getPrecio(Passenger* this,float* precio);

//aca hacer criterio para ordenar empleados
//podemos agregar sin problema funciones

#endif /* PASSENGER_H_ */



/**
 * #ifndef SERVICIOS_H_
#define SERVICIOS_H_

#define CHAR_LEN 50

typedef struct
{
	int id_servicio;
	char descripcion[CHAR_LEN];
	int tipo;
	float precioUnitario;
	int cantidad;
	int totalServicio;
}Servicios;

Servicios* new(void);
Servicios* newParametros(char* idStr,char* descripcion,char* Tipo ,char* precioUnitario,char* Cantidad,char* TotalServicio);
void delete(Servicios* this);

int setId(Servicios* this,int id);
int setIdTxt(Servicios* this,char* id);
int getId(Servicios* this,int* id);

int setDescripcion(Servicios* this,char* descripcion);
int getDescripcion(Servicios* this,char* descripcion);

int setTipo(Servicios* this,int tipo);
int setTipoTxt(Servicios* this,char* tipo);
int getTipo(Servicios* this,int* tipo);

int setFlotante(Servicios* this,float flotante);
int setFlotanteTxt(Servicios* this,char* flotante);
int getFlotante(Servicios* this,float* flotante);

int setCantidad(Servicios* this,int cantidad);
int setCantidadTxt(Servicios* this,char* cantidad);
int getCantidad(Servicios* this,int* cantidad);

int setTotalServicio(Servicios* this,int totalServicio);
int setTotalServicioTxt(Servicios* this,char* totalServicio);
int getTotalServicio(Servicios* this,int* totalServicio);

int multiplicar(Servicios* element);*/

