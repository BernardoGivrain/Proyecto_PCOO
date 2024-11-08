#include "Egreso.h"
#include "Ingreso.h"
#include <iostream>

const int MAX = 100;

class Presupuesto{
    private:
        Egreso egresos[MAX];
        Ingreso ingresos[MAX];
        int ctdEgresos = 0, ctdIngresos = 0;
        float suma_ingresos = 0, suma_egresos = 0, egresos_siguiente_mes = 0;



    public:
    //Default constructor
        void insertarIngreso(float, std::string);
        void insertarEgreso(float, std::string, bool);
        void agregarIngreso();
        void agregarEgreso();
        void crearEjemploIngresos();
        void crearEjemploEgresos();
        void mostrarIngreso();
        void mostrarEgreso();
        void calcularPresupuesto();

};

void Presupuesto::agregarIngreso(){

    float _ctd;
    char opcion;
    bool fijo = false;
    std::string fuente;

    std::cout << "Ingrese la cantidad que se ha ganado: "<< std::endl;
    std::cin >> _ctd;
    std::cout << "Ingrese la fuente del ingreso: "<< std::endl;
    std::cin >> fuente;

    Ingreso ingreso(_ctd, fuente);
    ingresos[ctdIngresos] = ingreso;
    ctdIngresos++;

    
}

void Presupuesto::agregarEgreso(){

    float _ctd;
    char opcion;
    bool fijo = false;
    std::string fuente;

    std::cout << "Ingrese la cantidad que se ha gastado: "<< std::endl;
    std::cin >> _ctd;
    std::cout << "Ingrese el motivo del gasto: "<< std::endl;
    std::cin >> fuente;
    std::cout << "El gasto es fijo? s/n: "<< std::endl;
    std::cin >> opcion;

    if(opcion == 's'){
        fijo = true;
    }

    Egreso egreso(_ctd, fuente, fijo);
    egresos[ctdEgresos] = egreso;
    ctdEgresos++;

}

void Presupuesto::insertarIngreso(float f, std::string s){
    Ingreso ingreso(f, s);
    ingresos[ctdIngresos] = ingreso;
    ctdIngresos++;
}

void Presupuesto::insertarEgreso(float f, std::string s, bool b){
    Egreso egreso(f, s, b);
    egresos[ctdEgresos] = egreso;
    ctdEgresos++;
}

void Presupuesto::crearEjemploIngresos(){

    Presupuesto::insertarIngreso(10000, "Salario");
    Presupuesto::insertarIngreso(1000, "Asesorías de programacion");

}
void Presupuesto::crearEjemploEgresos(){

    Presupuesto::insertarEgreso(500, "Recibo de luz", true);
    Presupuesto::insertarEgreso(150, "Recibo de agua", true);
    Presupuesto::insertarEgreso(350, "Mochila nueva", false);

}
void Presupuesto::mostrarEgreso(){

    for(int i = 0; i < ctdEgresos; i++){
        suma_egresos += egresos[i].getGasto();
    }

    std::cout << "El gasto total para este mes es: " << suma_egresos << std::endl;

    for(int i = 0; i < ctdEgresos; i++){
        if(egresos[i].isFijo()){
            egresos_siguiente_mes += egresos[i].getGasto();
        }
    }

    std::cout << "El gasto total estimado para el siguiente mes es de al menos: " << egresos_siguiente_mes << std::endl;

}
void Presupuesto::mostrarIngreso(){

    for(int i = 0; i < ctdIngresos; i++){
        suma_ingresos += ingresos[i].getGanancia();
    }

}
void Presupuesto::calcularPresupuesto(){

    std::cout << "El presupuesto para este mes es de "<<suma_ingresos-suma_egresos << " pesos." <<std::endl;

}