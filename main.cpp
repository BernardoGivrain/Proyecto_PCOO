#include <iostream>
#include "Presupuesto.h"

using namespace std;

int main(){

    Presupuesto p;
    p.crearEjemploEgresos();
    p.crearEjemploIngresos();
    p.mostrarIngreso();
    p.mostrarEgreso();
    p.calcularPresupuesto();


    return 0;
}