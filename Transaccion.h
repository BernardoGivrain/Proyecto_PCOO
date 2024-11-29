/*
 * Proyecto Control de ingresos y egresos
 * Bernardo Givrain Ortega Bustos
 * A01713350
 * 22/11/2024
 * 
 */

/*
 * Clase transacción, que funciona como la clase padre de 
 * Ingreso y Egreso, que contiene los atributos y métodos
 * genéricos para dichas clases
 * 
 */

#ifndef TRANSACCION_H_
#define TRANSACCION_H_
#include<string>
#include<iostream>

class Transaccion{

    //Atributos declarados como protected para que las clases heredadas puedan manipularlos
    protected:
        float monto;
        std::string fecha;
        std::string descripcion;
    public:
    //Constructores
        Transaccion();
        Transaccion(float m, std::string s, std::string d): monto(m), fecha(s),descripcion(d){};

    //Getters y setters
        void setMonto(float);
        void setFecha(std::string);
        void setDescripcion(std::string);
        float getMonto();
        std::string getFecha();
        std::string getDescripcion();
        
        std::string reporte();

};
/**
 * Constructor por defecto
 *
 * @param 
 * @return objeto Transaccion
*/
Transaccion::Transaccion(){
    monto = 0.0;
    fecha = "";
    descripcion = "";
}
/**
 * setter monto
 *
 * @param float f: monto de la transaccion
 * @return
*/
void Transaccion::setMonto(float f){
    monto = f;
}
/**
 * setter fecha
 *
 * @param string s: fecha que se realizó la transacción
 * @return
*/
void Transaccion::setFecha(std::string s){
    fecha = s;
}

/**
 * setter descripcion
 *
 * @param string d: descripcion de la transaccion
 * @return
*/
void Transaccion::setDescripcion(std::string d){
    descripcion = d;
}
/**
 * getter monto
 *
 * @param
 * @return float monto: monto de la transaccion
*/
float Transaccion::getMonto(){
    return monto;
}
/**
 * getter fecha
 *
 * @param
 * @return string fecha: fecha que se realizó la transacción
*/
std::string Transaccion::getFecha(){
    return fecha;
}
/**
 * getter descripcion
 *
 * @param
 * @return string descripcion: fecha que se realizó la transacción
*/
std::string Transaccion::getDescripcion(){
    return descripcion;
}
/**
 * setter metodo de pago
 *
 * @param 
 * @return string: regresa un valor string que contiene todos los atributos del objeto en 
 * un formato más legible, incluyendo el monto de compra, la fecha y la descripción
*/
std::string Transaccion::reporte(){
    return "Monto << "+std::to_string(monto) + "\nFecha << "+ fecha + "\nDescripcion << "+descripcion + "\n";
}

    
#endif