#include <stdio.h>
#include <stdlib.h>
#include "utn_opcionesMenu.h"

int main(void) {
	setbuf(stdout, NULL);
	int menu;
	int submenu;
	int retornoValidacion;
	do{
		printf("\n");
		printf("1. Ingresar Kilometros\n");
		printf("2. Ingresar Precios de Vuelos\n");
		printf("3. Calcular Todos los Costos\n");
		printf("4. Informar Resultados\n");
		printf("5. Carga forzada de datos\n");
		printf("6. Salir\n");
		retornoValidacion = utn_getInt(&menu, "\nIngrese su opcion: ", "\nERROR. No eligio ninguna de las opciones indicadas\n",6,1,2);
		if(retornoValidacion == 0){
			switch(menu){
				case 1:
					printf("TEST. Caso 1\n");
					break;
				case 2:
					do{
						printf("\nTEST.\n");
						printf("1. Precio vuelo Aerolineas\n");
						printf("2. Precio vuelo LATAM\n");
						retornoValidacion = utn_getInt(&submenu, "\nIngrese su opcion: ", "\nERROR. No eligio ninguna de las opciones indicadas\n",2,1,2);
						if(retornoValidacion == 0){
							switch(submenu){
								case 1:
									printf("\nTEST. Ingresar Precio: Sb1\n");
									break;
								case 2:
									printf("\nTEST. Ingresar Precio: Sb2\n");
									break;
							}
						}
					}while(submenu != 1 && submenu != 2);
					break;
				case 3:
					printf("TEST. Caso 3\n");
					break;
				case 4:
					printf("TEST. Caso 4\n");
					break;
				case 5:
					printf("TEST. Caso 5\n");
					break;
				case 6:
					printf("TEST. Caso 6\n");
					break;
			}
		}
	}while(menu != 6);
	return EXIT_SUCCESS;
}
