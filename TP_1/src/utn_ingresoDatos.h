//Header de mi biblioteca

#ifndef UTN_INGRESODATOS_H_
#define UTN_INGRESODATOS_H_

//Prototipos

int utn_getInt(int * pResultado, char * mensaje, char * mensajeError, int maximo, int minimo, int reintentos);
int utn_getFloat(float * pResultado, char * mensaje, char * mensajeError, int maximo, int minimo, int reintentos);

#endif /* UTN_INGRESODATOS_H_ */
