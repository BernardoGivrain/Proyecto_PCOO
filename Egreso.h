/*
 * Proyecto Control de ingresos y egresos
 * Bernardo Givrain Ortega Bustos
 * A01713350
 * 22/11/2024
 * 
*/

/*
 * Clase Egreso, es una de las dos clases hijas que en este programa 
 * representa un gasto o inversión, en la cual se incluyen otros detalles
 * como la fecha o el metodo de pago.
 * 
 */

#ifndef EGRESO_H_
#define EGRESO_H_

#include "Transaccion.h"
#include<string>

class Egreso: public Transaccion{

    private:
    //Atributo propio de esta clase
        std::string  metodo_pago;
    
    public:
    //Constructores
        Egreso();
        Egreso(float, std::string, std::string, std::string);

    //Getters y setters
        void setMetodoPago(std::string);
        std::string getMetodoPago();

        std::string reporte();
};

/**
 * Constructor por defecto
 *
 * @param 
 * @return objeto Egreso
*/
Egreso::Egreso(): Transaccion(){
    metodo_pago = "";
}

/**
 * Constructor que recibe monto, fecha, descripcion y metodo de pago
 *
 * @param float m: monto gastado, string s: fecha de la transacción, string d:descripcion de la transaccion,string r: metodo de pago
 * @return objeto Egreso
*/
Egreso::Egreso(float m, std::string f, std::string d, std::string r) : Transaccion(m, f, d){
    metodo_pago = r;
}

/**
 * setter metodo de pago
 *
 * @param string e: metodo de pago
 * @return
*/
void Egreso::setMetodoPago(std::string e){
    metodo_pago = e;
}

/**
 * getter metodo de pago
 *
 * @param 
 * @return string metodo_pago: metodo de pago
*/
std::string Egreso::getMetodoPago(){
    return metodo_pago;
}

/**
 * Generar un reporte con la información de la transacción
 *
 * @param 
 * @return string: regresa un valor string que contiene todos los atributos del objeto en 
 * un formato más legible que incluye el método de pago.
*/
std::string Egreso::reporte(){
        return "Monto << "+std::to_string(monto) + "\nFecha << "+ fecha + "\nDescripcion << "+descripcion + "\nMetodo de pago: << " + metodo_pago + "\n"; 
}


#endif