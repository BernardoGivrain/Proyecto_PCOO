
#ifndef PRESUPUESTO_H_
#define PRESUPUESTO_H_
#include "Egreso.h"
#include "Ingreso.h"
#include <iostream>

const int MAX = 100;

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
        Presupuesto(std::string nombre, std::string empresa, std::string telefono) : nombre_titular(nombre), banco(empresa), num_telefono(telefono){};
        void setNombreTitular(std::string);
        void setNumTelefono(std::string);
        void setBanco(std::string);
        std::string getNombreTitular();
        std::string getNumTelefono();
        std::string getBanco();
        void insertarIngreso(float, std::string, std::string, std::string);
        void insertarEgreso(float, std::string, std::string, std::string);
        void agregarIngreso();
        void agregarEgreso();
        void mostrarDatosIngresos();
        void mostrarDatosEgresos();
        void mostrarDatosUsuario();
        void mostrarIngreso();
        void mostrarEgreso();
        void calcularPresupuesto();
};

Presupuesto::Presupuesto(){
    nombre_titular = "";
    banco = "";
    num_telefono = "";
}
void Presupuesto::setNombreTitular(std::string n){
    nombre_titular = n;
}
void Presupuesto::setBanco(std::string b){
    banco = b;
}
void Presupuesto::setNumTelefono(std::string tel){
    num_telefono = tel;
}
std::string Presupuesto::getNombreTitular(){
    return nombre_titular;
}
std::string Presupuesto::getBanco(){
    return banco;
}
std::string Presupuesto::getNumTelefono(){
    return num_telefono;
}

void Presupuesto::agregarIngreso(){

    float _ctd;
    std::string fecha;
    std::string fuente;
    std::string detalles;

    std::cout << "Ingrese la cantidad que se ha ganado: "<< std::endl;
    std::cin >> _ctd;
    std::cout << "Ingrese la fecha que se ha generado el ingreso: "<< std::endl;
    std::cin >> fecha;
    std::cout << "Ingrese la fuente del ingreso: "<< std::endl;
    std::cin >> fuente;
    std::cout << "Ingrese detalles de la transaccion: "<< std::endl;
    std::cin >> detalles;

    Ingreso ingreso(_ctd, fecha, detalles, fuente);
    ingresos[ctd_ingresos] = ingreso;
    suma_ingresos+=_ctd;
    ctd_ingresos++;
}

void Presupuesto::agregarEgreso(){

    float _ctd;
    std::string fecha;
    std::string fuente;
    std::string detalles;

    std::cout << "Ingrese la cantidad gastada: "<< std::endl;
    std::cin >> _ctd;
    std::cout << "Ingrese la fecha que se ha generado la transaccion: "<< std::endl;
    std::cin >> fecha;
    std::cout << "Ingrese el motivo de compra: "<< std::endl;
    std::cin.ignore(1, '\n');
    std::getline(std::cin, fuente);
    std::cout << "Ingrese detalles de la transaccion: "<< std::endl;
    std::cin.ignore(1, '\n');
    std::getline(std::cin, detalles);

    Egreso egreso(_ctd, fecha, detalles, fuente);
    egresos[ctd_egresos] = egreso;
    suma_egresos+=_ctd;
    ctd_egresos++;

}

void Presupuesto::insertarIngreso(float m, std::string f, std::string d, std::string r){
    Ingreso ingreso(m, f, d, r);
    ingresos[ctd_ingresos] = ingreso;
    suma_ingresos+=m;
    ctd_ingresos++;
}

void Presupuesto::insertarEgreso(float m, std::string f, std::string d, std::string r){
    Egreso egreso(m, f, d, r);
    egresos[ctd_egresos] = egreso;
    suma_egresos+=m;
    ctd_egresos++;
}

void Presupuesto::mostrarDatosIngresos(){
    for(int i = 0; i < ctd_ingresos ; i++){
        std::cout << "***************************************"<<std::endl;
        ingresos[i].reporte();
    }
}
void Presupuesto::mostrarDatosEgresos(){
    for(int i = 0; i < ctd_egresos ; i++){
       std::cout << "***************************************"<<std::endl;
       std::cout << egresos[i].reporte();
    }
}
void Presupuesto::mostrarDatosUsuario(){
    std::cout << "Nombre: " << nombre_titular << "\nBanco: " << banco << "\nTelefono: " << num_telefono << std::endl;
    std::cout << "***************************************" <<std::endl;
}
void Presupuesto::mostrarIngreso(){
    std::cout << "El ingreso total es: " << suma_ingresos << std::endl;
}
void Presupuesto::mostrarEgreso(){
    std::cout << "El gasto total es: " << suma_ingresos << std::endl;
}
void Presupuesto::calcularPresupuesto(){

    std::cout << "El presupuesto para este mes es de "<<suma_ingresos-suma_egresos << " pesos." <<std::endl;

}
#endif