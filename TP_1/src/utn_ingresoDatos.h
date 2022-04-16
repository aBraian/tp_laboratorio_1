//Header

#ifndef UTN_INGRESODATOS_H_
#define UTN_INGRESODATOS_H_

//Prototipos

/// @brief Solicita un numero entero al usuario
///
/// @param pResultado Pasa por referencia el numero ingresado
/// @param mensaje Muestra al usuario que ingresar
/// @param mensajeError Muestra un mensaje de advertencia en caso de ingresar mal los datos
/// @param maximo Establece el valor maximo
/// @param minimo Establece el valor minimo
/// @param reintentos Cantidad de reintentos
/// @return Retorna si se cumplio la condicion
int utn_getInt(int * pResultado, char * mensaje, char * mensajeError, int maximo, int minimo, int reintentos);

/// @brief Solicita un numero flotante al usuario
///
/// @param pResultado Pasa por referencia el numero ingresado
/// @param mensaje Muestra al usuario que ingresar
/// @param mensajeError Muestra un mensaje de advertencia en caso de ingresar mal los datos
/// @param maximo Establece el valor maximo
/// @param minimo Establece el valor minimo
/// @param reintentos Cantidad de reintentos
/// @return Retorna si se cumplio la condicion
int utn_getFloat(float * pResultado, char * mensaje, char * mensajeError, int maximo, int minimo, int reintentos);

#endif /* UTN_INGRESODATOS_H_ */
