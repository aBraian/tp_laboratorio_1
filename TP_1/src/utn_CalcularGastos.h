//Header

#ifndef UTN_CALCULARGASTOS_H_
#define UTN_CALCULARGASTOS_H_

//Prototipos

/// @brief Calcula descuento
///
/// @param pDescuento Paso por referencia el descuento
/// @param precio Valor al que se aplica descuento
/// @param descuento Valor del descuento
/// @return
int utn_Descuento(float * pDescuento, float precio, int descuento);

/// @brief Calcula interes
///
/// @param pInteres Paso por referencia el interes
/// @param precio Valor al que se aplica interes
/// @param interes Valor del interes
/// @return
int utn_Interes(float * pInteres, float precio, int interes);

/// @brief Calcula division
///
/// @param pResultado Paso por referencia el resultado de la division
/// @param dividendo Numero a dividir
/// @param divisor Numero que divide
/// @return
int utn_Division(float * pResultado, float dividendo, int divisor);

/// @brief Calcula una resta
///
/// @param pResultado Paso por referencia el resultado de la resta
/// @param precioAerolineas Paso un valor para la resta
/// @param precioLatam Paso otro valor para la resta
/// @return
int utn_DiferenciaDePrecios(float * pResultado, float numero1, float numero2);

#endif /* UTN_CALCULARGASTOS_H_ */
