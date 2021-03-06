#include <stdio.h>
#include <stdlib.h>
#include "Controller.h"
#include "LinkedList.h"
#include "Passenger.h"
#include "utn.h"
#define CHAR_LEN 50

int main()
{
	setbuf(stdout,NULL);
    int option = 0;
    int idMax = 0;
    LinkedList* listaPassenger = ll_newLinkedList();
    do
    {
    	utn_getNumero(&option, "\nMenu:\n"
    		    "1. Cargar los datos de los pasajeros desde el archivo data.csv (modo texto).\n"
				"2. Cargar los datos de los pasajeros desde el archivo data.csv (modo binario).\n"
				"3. Alta de pasajero\n"
				"4. Modificar datos de pasajero\n"
				"5. Baja de pasajero\n"
				"6. Listar pasajeros\n"
				"7. Ordenar pasajeros\n"
				"8. Guardar los datos de los pasajeros en el archivo data.csv (modo texto).\n"
				"9. Guardar los datos de los pasajeros en el archivo data.csv (modo binario).\n"
				"10. Salir\n", "\nERROR", 1, 10, 2);
        switch(option)
        {
            case 1:
                idMax = controller_loadFromText("data.csv",listaPassenger);
                if(idMax < 0)
                {
                	printf("\nERROR. El id es negativo");
                }
                break;
            case 2:
            	//al final en binario
				break;
            case 3:
            	if(controller_addPassenger(listaPassenger, idMax) == 0)
            	{
            		idMax++;
    				printf("\nSe agrego correctamente\n");
            	}
				break;
            case 4:
            	//controller_
				break;
            case 5:
            	//controller_
				break;
            case 6:
            	controller_ListPassenger(listaPassenger);
				break;
            case 7:
            	//controller_
				break;
            case 8:
            	//controller_
				break;
            case 9:
            	//controller_
				break;
            case 10:
				break;
        }
    } while(option != 10);
    return 0;
}

