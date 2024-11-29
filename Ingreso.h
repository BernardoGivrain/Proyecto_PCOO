/*
 * Proyecto Control de ingresos y egresos
 * Bernardo Givrain Ortega Bustos
 * A01713350
 * 22/11/2024
 * 
*/


/*
 * Clase Ingreso, es una de las dos clases hijas que en este programa 
 * representa una ganancia, en la cual se incluyen otros detalles
 * como la fecha o el tipo de ingreso.
 * 
 */

#ifndef INGRESO_H_
#define INGRESO_H_

#include "Transaccion.h"
#include<string>

class Ingreso: public Transaccion{

    private:
    //Atributo propio de esta clase
        std::string tipo_ingreso;
    
    public:
    //Constructores
        Ingreso();
        Ingreso(float, std::string, std::string, std::string);
    
        std::string getTipoIngreso();
        void setTipoIngreso(std::string);
        std::string reporte();

};
/**
 * Constructor por defecto
 *
 * @param 
 * @return objeto Ingreso
*/
Ingreso::Ingreso(){
    tipo_ingreso = "";
}
/**
 * Constructor que recibe monto, fecha, descripcion y metodo de pago
 *
 * @param float m: monto gastado, string s: fecha de la transacción, string d:descripcion de la transaccion,string r: tipo de ingreso
 * @return objeto Ingreso
*/
Ingreso::Ingreso(float m, std::string f, std::string d, std::string r) : Transaccion(m, f, d){
    tipo_ingreso = r;
}
/**
 * getter tipo de ingreso
 *
 * @param 
 * @return string: tipo de ingreso
*/
std::string Ingreso::getTipoIngreso(){
    return tipo_ingreso;
}
/**
 * setter tipo de ingreso
 *
 * @param string b: tipo de ingreso
 * @return
*/
void Ingreso::setTipoIngreso(std::string b){
    tipo_ingreso = b;
}
/**
 * Generar un reporte con la información de la transacción
 *
 * @param 
 * @return string: regresa un valor string que contiene todos los atributos del objeto en 
 * un formato más legible, que inclute el tipo de ingreso.
*/
std::string Ingreso::reporte(){
        return "Monto << "+std::to_string(monto) + "\nFecha << "+ fecha + "\nDescripcion << "+descripcion + "\nTipo de ingreso: << " + tipo_ingreso + "\n"; 
}

#endif