/*
 * Proyecto Control de ingresos y egresos
 * Bernardo Givrain Ortega Bustos
 * A01713350
 * 22/11/2024
 * 
*/

#ifndef PRESUPUESTO_H_
#define PRESUPUESTO_H_
#include "Egreso.h"
#include "Ingreso.h"
#include <iostream>

const int MAX = 100;

/*
 *Clase presupuesto, que guarda la información de todos los ingresos y egresos
 *que el usuario desee ingresar. Además, funciona como una especie de cuenta 
 * bancaria al tener información básica del usuario
 */

class Presupuesto{
    private:
        std::string nombre_titular;
        std::string banco;
        std::string num_telefono;
        Egreso egresos[MAX];
        Ingreso ingresos[MAX];
        int ctd_egresos = 0, ctd_ingresos = 0;
        float suma_ingresos = 0, suma_egresos = 0;
    public:
        Presupuesto();

        //Constructor con parametros
        Presupuesto(std::string nombre, std::string empresa, std::string telefono) : nombre_titular(nombre), banco(empresa), num_telefono(telefono){};

        //Getters y Setters
        void setNombreTitular(std::string);
        void setNumTelefono(std::string);
        void setBanco(std::string);
        std::string getNombreTitular();
        std::string getNumTelefono();
        std::string getBanco();

        void insertarIngreso(float, std::string, std::string, std::string);
        void insertarEgreso(float, std::string, std::string, std::string);
        void mostrarDatosEgresos();
        void mostrarDatosIngresos();
        void mostrarDatosUsuario();
        void mostrarIngreso();
        void mostrarEgreso();
        void calcularPresupuesto();
};

/**
 * Constructor por defecto
 *
 * @param 
 * @return objeto Presupuesto
 */
Presupuesto::Presupuesto(){
    nombre_titular = "";
    banco = "";
    num_telefono = "";
}

/**
 * setter nombre
 *
 * @param string n: nombre del titular de la cuenta
 * @return
 */
void Presupuesto::setNombreTitular(std::string n){
    nombre_titular = n;
}

/**
 * setter banco
 *
 * @param string b: nombre del banco al que pertenece la cuenta
 * @return
*/
void Presupuesto::setBanco(std::string b){
    banco = b;
}

/**
 * setter telefono
 *
 * @param string tel: numero de telefono del titular de la cuenta
 * @return
*/
void Presupuesto::setNumTelefono(std::string tel){
    num_telefono = tel;
}


/**
 * getter nombre del titular
 *
 * @param 
 * @return string nombre_titular: nombre del titular
*/
std::string Presupuesto::getNombreTitular(){
    return nombre_titular;
}
/**
 * getter banco
 *
 * @param 
 * @return string banco: nombre del banco al que pertenece la cuenta: 
 */
std::string Presupuesto::getBanco(){
    return banco;
}

/**
 * getter numero de telefono
 *
 * @param 
 * @return string num_telefono: numero de telefono del titular de la cuenta
*/
std::string Presupuesto::getNumTelefono(){
    return num_telefono;
}

/*
 *Solicita varios parámetros que permitan crear un ingreso 
 *y guardarlo dentro del arreglo de dicha clase
 */
void Presupuesto::insertarIngreso(float m, std::string f, std::string d, std::string r){
    ingresos[ctd_ingresos] = Ingreso(m, f, d, r);
    suma_ingresos+=m;
    ctd_ingresos++;
}

/*
 * Solicita varios parámetros que permitan crear un egreso 
 * y guardarlo dentro del arreglo de dicha clase
 */

/*
 * Solicita varios parámetros que permitan crear un egreso 
 * y guardarlo dentro del arreglo de dicha clase
 * 
 * @param 
 * @return  
*/
void Presupuesto::insertarEgreso(float m, std::string f, std::string d, std::string r){
    egresos[ctd_egresos] = Egreso(m, f, d, r);
    suma_egresos+=m;
    ctd_egresos++;
}

/*
 * Muestra los datos de cada ingreso guardado en el arreglo de dicho tipo de dato
 * 
 * @param 
 * @return 
*/
void Presupuesto::mostrarDatosIngresos(){
    for(int i = 0; i < ctd_ingresos ; i++){
        std::cout << "***************************************"<<std::endl;
        std::cout<<ingresos[i].reporte();
    }
}

/*
 * Muestra los datos de cada egreso guardado en el arreglo de dicho tipo de dato
 * 
 * @param 
 * @return 
*/
void Presupuesto::mostrarDatosEgresos(){
    for(int i = 0; i < ctd_egresos ; i++){
       std::cout << "***************************************"<<std::endl;
       std::cout << egresos[i].reporte();
    }
}

/*
 * Imprime con un pequeño formato los datos del usuario (nombre del titular, nombre del banco y 
 * numero de telefono)
 * 
 * @param 
 * @return 
*/
void Presupuesto::mostrarDatosUsuario(){
    std::cout << "Nombre: " << nombre_titular << "\nBanco: " << banco << "\nTelefono: " << num_telefono << std::endl;
    std::cout << "***************************************" <<std::endl;
}

/*
 * Muestra la suma total del monto de ganancias (ingresos)
 * 
 * @param 
 * @return 
*/
void Presupuesto::mostrarIngreso(){
    std::cout << "El ingreso total es: " << suma_ingresos << std::endl;
}

/*
 * Muestra la suma total del monto de perdidas (egresos)
 * 
 * @param 
 * @return 
*/
void Presupuesto::mostrarEgreso(){
    std::cout << "El gasto total es: " << suma_egresos << std::endl;
}

/*
 * Calcula el presupuesto mostrando la diferencia entre la suma de ingresos y de egresos
 * 
 * @param 
 * @return 
*/
void Presupuesto::calcularPresupuesto(){

    std::cout << "El presupuesto de esta cuenta es de: "<<suma_ingresos-suma_egresos << " pesos." <<std::endl;

}
#endif