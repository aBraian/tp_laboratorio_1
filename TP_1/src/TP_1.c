#include <stdio.h>
#include <stdlib.h>
#include "utn_opcionesMenu.h"
#include "utn_ingresoDatos.h"
int utn_CalcularCostos(float * pDescuento, float * pInteres, float * pBitcoin, float * pPrecioUnitario, float precio, float kilometros, int descuento, int interes, float bitcoin);
int utn_DiferenciaDePrecios(float * pResultado, float precioAerolineas, float precioLatam);
int main(void) {
	setbuf(stdout, NULL);
	int menu;
	int submenu;
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
	kilometros = 0;
	aerolineas = 0;
	latam = 0;
	flagAerolineas = 0;
	flagLatam = 0;
	flagKilometros = 0;
	flagCalculos = 0;
	do{
		printf("\n");
		printf("1. Ingresar Kilometros: (km = %.2f) \n", kilometros);
		printf("2. Ingresar Precios de Vuelos: (Aerolineas = %.2f, Latam = %.2f)\n", aerolineas, latam);
		printf("3. Calcular Todos los Costos\n");
		printf("4. Informar Resultados\n");
		printf("5. Carga forzada de datos\n");
		printf("6. Salir\n");
		retornoValidacion = utn_getInt(&menu, "\nIngrese su opcion: ", "\nERROR. No eligio ninguna de las opciones indicadas\n",6,1,2);
		if(retornoValidacion == 0){
			switch(menu){
				case 1:
					retornoValidacion = utn_getFloat(&kilometros, "\nIngrese la cantidad de kilometros: ", "\nERROR. El kilometraje ingresado NO es VALIDO. Maximo 30000Km / Minimo 1Km\n", 30000, 1, 2);
					if(retornoValidacion == 0){
						flagKilometros++;
					}
					break;
				case 2:
					do{
						printf("\n");
						printf("1. Precio vuelo Aerolineas\n");
						printf("2. Precio vuelo LATAM\n");
						printf("3. Modificar Precios\n");
						printf("4. Volver al menu\n");
						retornoValidacion = utn_getInt(&submenu, "\nIngrese su opcion: ", "\nERROR. No eligio ninguna de las opciones indicadas\n",4,1,2);
						if(retornoValidacion == 0){
							switch(submenu){
								case 1:
									if(flagAerolineas == 0){
										retornoValidacion = utn_getFloat(&aerolineas, "\nPrecio vuelo Aerolineas: $", "\nERROR. El PRECIO ingresado NO es VALIDO. Maximo $1500000 / Minimo $6000\n", 1500000, 6000, 2);
										if(retornoValidacion == 0){
											flagAerolineas+=1;
										}
									}
									else{
										printf("Seleccione la opcion 'Modificar Precios' en caso de querer cambiar los precios\n");
									}
									break;
								case 2:
									if(flagLatam == 0){
										retornoValidacion = utn_getFloat(&latam, "\nPrecio vuelo LATAM: $", "\nERROR. El PRECIO ingresado NO es VALIDO. Maximo $1500000 / Minimo $6000\n", 1500000, 6000, 2);
										if(retornoValidacion == 0){
											flagLatam+=1;
										}
									}
									else{
										printf("Seleccione la opcion 'Modificar Precios' en caso de querer cambiar los precios\n");
									}
									break;
								case 3:
									if(flagAerolineas == 1){
										flagAerolineas-=1;
										printf("\nYa puede modificar el Precio de Aerolineas\n");
									}
									if(flagLatam == 1){
										flagLatam-=1;
										printf("\nYa puede modificar el Precio de LATAM\n");
									}
									break;
								case 4:
									printf("\nMENU\n");
									break;
							}
						}
					}while(submenu != 4);
					break;
				case 3:
						if(flagKilometros > 0 && flagAerolineas > 0 && flagLatam > 0){
							retornoValidacion = utn_CalcularCostos(&precioConDescuentoAerolineas, &precioConInteresAerolineas, &precioBitcoinAerolineas, &precioUnitarioAerolineas, aerolineas, kilometros, 10, 25, 4475419.01);
							retornoValidacion = utn_CalcularCostos(&precioConDescuentoLatam, &precioConInteresLatam, &precioBitcoinLatam, &precioUnitarioLatam, latam, kilometros, 10, 25, 4475419.01);
							retornoValidacion = utn_DiferenciaDePrecios(&diferenciaDePrecios, aerolineas, latam);
							flagCalculos++;
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
							printf("c) Precio pagando con Bitcoin: %.4f BTC\n", precioBitcoinAerolineas);
							printf("d) Precio unitario: $%.2f\n", precioUnitarioAerolineas);
							printf("\nPrecio LATAM: $%.2f\n", latam);
							printf("a) Precio con tarjeta de debito: $%.2f\n", precioConDescuentoLatam);
							printf("b) Precio con tarjeta de credito: $%.2f\n", precioConInteresLatam);
							printf("c) Precio pagando con Bitcoin: %.4f BTC\n", precioBitcoinLatam);
							printf("d) Precio unitario: $%.2f\n", precioUnitarioLatam);
							printf("\nLa diferencia de precio es: $%.2f\n",diferenciaDePrecios);
						}
						else{
							printf("\nPara MOSTRAR resultados se debe CALCULAR antes (OPCION 3)\n");
						}
					break;
				case 5:
					printf("TEST. Caso 5\n");
					break;
				case 6:
					printf("\nSalio correctamente\n");
					break;
			}
		}
	}while(menu != 6);
	return EXIT_SUCCESS;
}

int utn_CalcularCostos(float * pDescuento, float * pInteres, float * pBitcoin, float * pPrecioUnitario, float precio, float kilometros, int descuento, int interes, float bitcoin){
	int retorno;
	float bufferDescuento;
	float bufferInteres;
	float bufferBitcoin;
	float bufferPrecioUnitario;
	retorno = -1;
	if(pDescuento != NULL && pInteres != NULL && pBitcoin != NULL && pPrecioUnitario != NULL){
		bufferDescuento = precio - precio * descuento / 100;
		*pDescuento = bufferDescuento;
		bufferInteres = precio + precio * interes / 100;
		*pInteres = bufferInteres;
		bufferBitcoin = precio / bitcoin;
		*pBitcoin = bufferBitcoin;
		bufferPrecioUnitario = precio / kilometros;
		*pPrecioUnitario = bufferPrecioUnitario;
		retorno = 0;
	}
	return retorno;
}

int utn_DiferenciaDePrecios(float * pResultado, float precioAerolineas, float precioLatam){
	int retorno;
	float bufferResta;
	retorno = -1;
	if(pResultado != NULL){
		if(precioAerolineas >= precioLatam){
			bufferResta = precioAerolineas - precioLatam;
			*pResultado = bufferResta;
		}
		else if(precioAerolineas < precioLatam){
			bufferResta = precioLatam - precioAerolineas;
			*pResultado = bufferResta;
		}
	retorno = 0;
	}
	return retorno;
}
