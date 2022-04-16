#include <stdio.h>
#include <stdlib.h>
#include "utn_CalcularGastos.h"
#include "utn_IngresoDatos.h"

int main(void) {
	setbuf(stdout, NULL);
	int menu;
	int submenuKilometros;
	int submenuPrecios;
	int retornoValidacion;
	int flagLatam;
	int flagAerolineas;
	int flagKilometros;
	int flagCalculos;
	float kilometros;
	float aerolineas;
	float latam;
	float precioConDescuentoAerolineas;
	float precioConInteresAerolineas;
	float precioBitcoinAerolineas;
	float precioUnitarioAerolineas;
	float precioConDescuentoLatam;
	float precioConInteresLatam;
	float precioBitcoinLatam;
	float precioUnitarioLatam;
	float diferenciaDePrecios;
	float cargaForzadaPrecioConDescuentoAerolineas;
	float cargaForzadaPrecioConDescuentoLatam;
	float cargaForzadaPrecioConInteresAerolineas;
	float cargaForzadaPrecioConInteresLatam;
	float cargaForzadaPrecioBitcoinAerolineas;
	float cargaForzadaPrecioBitcoinLatam;
	float cargaForzadaPrecioUnitarioAerolineas;
	float cargaForzadaPrecioUnitarioLatam;
	float cargaForzadaDiferenciaDePrecios;
	kilometros = 0;
	aerolineas = 0;
	latam = 0;
	flagAerolineas = 0;
	flagLatam = 0;
	flagKilometros = 0;
	flagCalculos = 0;
	do{
		printf("\n-------------------------------------------------------------------\n");
		printf("\nMENU\n");
		printf("1. Ingresar Kilometros: (km = %.2f) \n", kilometros);
		printf("2. Ingresar Precios de Vuelos: (Aerolineas = %.2f, Latam = %.2f)\n", aerolineas, latam);
		printf("3. Calcular Todos los Costos\n");
		printf("4. Informar Resultados\n");
		printf("5. Carga forzada de datos\n");
		printf("6. Salir\n");
		printf("\n-------------------------------------------------------------------\n");
		retornoValidacion = utn_getInt(&menu, "\nIngrese su opcion: ", "\nERROR. No eligio ninguna de las opciones indicadas\n",6,1,2);
		if(retornoValidacion == 0){
			switch(menu){
				case 1:
					do{
						printf("\nSubmenu kilometros\n");
						printf("1. Ingresar kilometros\n");
						printf("2. Modificar kilometros\n");
						printf("3. Volver al menu\n");
						retornoValidacion = utn_getInt(&submenuKilometros, "\nIngrese su opcion: ", "\nERROR. No eligio ninguna de las opciones indicadas\n",3,1,2);
						if(retornoValidacion == 0){
							switch(submenuKilometros){
							case 1:
									if(flagKilometros == 0){
										retornoValidacion = utn_getFloat(&kilometros, "\nIngrese la cantidad de kilometros: ", "\nERROR. El kilometraje ingresado NO es VALIDO. Maximo 100000Km / Minimo 1Km\n", 100000, 1, 2);
											if(retornoValidacion == 0){
											flagKilometros = 1;
											}
									}
									else{
										printf("\nSeleccione la opcion 'Modificar kilometros' en caso de querer cambiar los kilometros\n");
									}
									break;
							case 2:
								if(flagKilometros == 1){
									kilometros = 0;
									flagKilometros = 0;
									flagCalculos = 0;
									printf("\nYa puede modificar los kilometros\n");

								}
								break;
							case 3:
								break;
								}
							}
					}while(submenuKilometros != 3);
					break;
				case 2:
					do{
						printf("\nSubmenu precios\n");
						printf("1. Precio vuelo Aerolineas\n");
						printf("2. Precio vuelo LATAM\n");
						printf("3. Modificar Precios\n");
						printf("4. Volver al menu\n");
						retornoValidacion = utn_getInt(&submenuPrecios, "\nIngrese su opcion: ", "\nERROR. No eligio ninguna de las opciones indicadas\n",4,1,2);
						if(retornoValidacion == 0){
							switch(submenuPrecios){
								case 1:
									if(flagAerolineas == 0){
										retornoValidacion = utn_getFloat(&aerolineas, "\nPrecio vuelo Aerolineas: $", "\nERROR. El PRECIO ingresado NO es VALIDO. Maximo $1500000 / Minimo $6000\n", 1500000, 6000, 2);
										if(retornoValidacion == 0){
											flagAerolineas = 1;
										}
									}
									else{
										printf("\nSeleccione la opcion 'Modificar Precios' en caso de querer cambiar los precios\n");
									}
									break;
								case 2:
									if(flagLatam == 0){
										retornoValidacion = utn_getFloat(&latam, "\nPrecio vuelo LATAM: $", "\nERROR. El PRECIO ingresado NO es VALIDO. Maximo $1500000 / Minimo $6000\n", 1500000, 6000, 2);
										if(retornoValidacion == 0){
											flagLatam = 1;
										}
									}
									else{
										printf("\nSeleccione la opcion 'Modificar Precios' en caso de querer cambiar los precios\n");
									}
									break;
								case 3:
									if(flagAerolineas == 1){
										aerolineas = 0;
										flagAerolineas = 0;
										flagCalculos = 0;
										printf("\nYa puede modificar el Precio de Aerolineas\n");
									}
									if(flagLatam == 1){
										latam = 0;
										flagLatam = 0;
										flagCalculos = 0;
										printf("Ya puede modificar el Precio de LATAM\n");
									}
									break;
								case 4:
									break;
							}
						}
					}while(submenuPrecios != 4);
					break;
				case 3:
						if(flagKilometros > 0 && flagAerolineas > 0 && flagLatam > 0){
							utn_Descuento(&precioConDescuentoAerolineas, aerolineas, 10);
							utn_Descuento(&precioConDescuentoLatam, latam, 10);
							utn_Interes(&precioConInteresAerolineas, aerolineas, 25);
							utn_Interes(&precioConInteresLatam, latam, 25);
							utn_Division(&precioBitcoinAerolineas, aerolineas, 4475419.01);
							utn_Division(&precioBitcoinLatam, latam, 4475419.01);
							utn_Division(&precioUnitarioAerolineas, aerolineas, kilometros);
							utn_Division(&precioUnitarioLatam, latam, kilometros);
							utn_DiferenciaDePrecios(&diferenciaDePrecios, aerolineas, latam);
							printf("\nCostos calculados correctamente\n");
							flagCalculos = 1;
						}
						else{
							printf("\nPara calcular se deben ingresar: Kilometros, Precios Aerolineas, Precios LATAM\n");
						}
					break;
				case 4:
						if(flagCalculos > 0){
							printf("\nKMs Ingresados: %.2f km\n", kilometros);
							printf("\nPrecio Aerolineas: $%.2f\n", aerolineas);
							printf("a) Precio con tarjeta de debito: $%.2f\n", precioConDescuentoAerolineas);
							printf("b) Precio con tarjeta de credito: $%.2f\n", precioConInteresAerolineas);
							printf("c) Precio pagando con Bitcoin: %f BTC\n", precioBitcoinAerolineas);
							printf("d) Precio unitario: $%.2f\n", precioUnitarioAerolineas);
							printf("\nPrecio LATAM: $%.2f\n", latam);
							printf("a) Precio con tarjeta de debito: $%.2f\n", precioConDescuentoLatam);
							printf("b) Precio con tarjeta de credito: $%.2f\n", precioConInteresLatam);
							printf("c) Precio pagando con Bitcoin: %f BTC\n", precioBitcoinLatam);
							printf("d) Precio unitario: $%.2f\n", precioUnitarioLatam);
							printf("\nLa diferencia de precio es: $%.2f\n",diferenciaDePrecios);
						}
						else{
							printf("\nPara MOSTRAR resultados se debe CALCULAR antes (OPCION 3)\n");
						}
					break;
				case 5:
					utn_Descuento(&cargaForzadaPrecioConDescuentoAerolineas, 162965, 10);
					utn_Descuento(&cargaForzadaPrecioConDescuentoLatam, 159339, 10);
					utn_Interes(&cargaForzadaPrecioConInteresAerolineas, 162965, 25);
					utn_Interes(&cargaForzadaPrecioConInteresLatam, 159339, 25);
					utn_Division(&cargaForzadaPrecioBitcoinAerolineas, 162965, 4475419.01);
					utn_Division(&cargaForzadaPrecioBitcoinLatam, 159339, 4475419.01);
					utn_Division(&cargaForzadaPrecioUnitarioAerolineas, 162965, 7090);
					utn_Division(&cargaForzadaPrecioUnitarioLatam, 159339, 7090);
					utn_DiferenciaDePrecios(&cargaForzadaDiferenciaDePrecios, 162965, 159339);
					printf("\nKMs Ingresados: 7090 km\n");
					printf("\nPrecio Aerolineas: $162965\n");
					printf("a) Precio con tarjeta de debito: $%.2f\n", cargaForzadaPrecioConDescuentoAerolineas);
					printf("b) Precio con tarjeta de credito: $%.2f\n", cargaForzadaPrecioConInteresAerolineas);
					printf("c) Precio pagando con Bitcoin: %f BTC\n", cargaForzadaPrecioBitcoinAerolineas);
					printf("d) Precio unitario: $%.2f\n", cargaForzadaPrecioUnitarioAerolineas);
					printf("\nPrecio LATAM: $159339\n");
					printf("a) Precio con tarjeta de debito: $%.2f\n", cargaForzadaPrecioConDescuentoLatam);
					printf("b) Precio con tarjeta de credito: $%.2f\n", cargaForzadaPrecioConInteresLatam);
					printf("c) Precio pagando con Bitcoin: %f BTC\n", cargaForzadaPrecioBitcoinLatam);
					printf("d) Precio unitario: $%.2f\n", cargaForzadaPrecioUnitarioLatam);
					printf("\nLa diferencia de precio es: $%.2f\n", cargaForzadaDiferenciaDePrecios);
					break;
				case 6:
					printf("\nSalio correctamente\n");
					break;
			}
		}
	}while(menu != 6);
	return EXIT_SUCCESS;
}
