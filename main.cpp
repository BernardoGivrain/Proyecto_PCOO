#include <iostream>
#include "Presupuesto.h"

void menu(){
    std::cout << "********** MENU  DE OPCIONES **********" << std::endl;
    std::cout << "1 - Cambiar de cuenta bancaria" <<std::endl;
    std::cout << "2 - Ver historial de egresos" <<std::endl;
    std::cout << "3 - Ver historial de ingresos" <<std::endl;
    std::cout << "4 - Calcular el presupuesto de la cuenta bancaria" <<std::endl;
    std::cout << "5 - Ingresar nuevo egreso" <<std::endl;
    std::cout << "6 - Ingresar nuevo ingreso" <<std::endl;
    std::cout << "7 - Crear nueva cuenta" <<std::endl;
    std::cout << "8 - Ver datos de la cuenta" <<std::endl;
    std::cout << "9 - Editar perfil" <<std::endl;          
    std::cout << "0 - Salir" <<std::endl;
}


int main(){

    Presupuesto cuentas[100];
    char respuesta_usuario = ' ';
    int num_cuentas = 1;
    int cuenta_actual = 0;
    
    while(respuesta_usuario != '0'){
        menu();
        std::cout << "Que desea hacer?: ";
        std::cin >> respuesta_usuario;

        switch(respuesta_usuario){
            case '1':{
                if(num_cuentas > 1){
                    std::cout << "N. de cuentas disponibles: " << num_cuentas <<std::endl;
                        for(int i = 0; i < num_cuentas; i++){
                            std::cout << (i+1);
                            cuentas[i].mostrarDatosUsuario();
                        }
                    std::cout << "Seleccione una cuenta: " << std::endl;
                    std::cin >> cuenta_actual;
                    cuenta_actual--;
                }
                else{
                    std::cout << "Lo sentimos, no hay otras cuentas que mostrar :(" << std::endl;
                }
            }
            case '2':{
                cuentas[cuenta_actual].mostrarDatosEgresos();
                break;
            }
            case '3':{
                cuentas[cuenta_actual].mostrarDatosIngresos();
                break;
            }
            case '4':{
                cuentas[cuenta_actual].calcularPresupuesto();
                break;
            }
            case '5':{
                cuentas[cuenta_actual].agregarEgreso();
                break;
            }
            case '6':{
                cuentas[cuenta_actual].agregarIngreso();
                break;
            }
            case '7':{
                std::string nombre, banco, telefono;
                std::cout << "Ingrese el nombre del titular de la cuenta: ";
                std::cin.ignore(1, '\n');
                std::getline(std::cin, nombre);
                std::cout << "Ingrese el banco al que pertenece la cuenta: ";
                std::cin >> banco;
                std::cout << "Ingrese el telefono de contacto del titular de la cuenta: ";
                std::cin >> telefono;
                std::cout << std::endl;
                cuentas[num_cuentas-1] = Presupuesto(nombre, banco, telefono);
                num_cuentas++;
                break;
            }
            case '8':{
                cuentas[cuenta_actual].mostrarDatosUsuario();
                 break;
            }
            case '9':{
                std::string nombre, banco, telefono;
                std::cout << "Ingrese el nombre del titular de la cuenta: ";
                std::cin.ignore(1, '\n');
                std::getline(std::cin, nombre);
                std::cout << "Ingrese el banco al que pertenece la cuenta: ";
                std::cin >> banco;
                std::cout << "Ingrese el telefono de contacto del titular de la cuenta: ";
                std::cin >> telefono;
                std::cout << std::endl;
                
                cuentas[cuenta_actual].setNombreTitular(nombre);
                cuentas[cuenta_actual].setBanco(banco);
                cuentas[cuenta_actual].setNumTelefono(telefono);
                 break;
            }
        }
    }

    std::cout << "Gracias por usar el programa!";

    return 0;
}