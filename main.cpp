/*
 * Proyecto Control de ingresos y egresos
 * Bernardo Givrain Ortega Bustos
 * A01713350
 * 22/11/2024
 * 
*/

// Bibliotecas
#include <iostream>
#include "Presupuesto.h"

/*
 * La función menu muestra todas las 
 * opciones disponibles para las acciones 
 * que puede realizar el usuario
 * 
 * 
*/

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

/*
 * El presente programa está hecho para la clase de 
 * Pensamiento Computacional Orientado a Objtos. Consiste 
 * en un sistema de ingresos y egresos que busca ser similar a 
 * Paypal, donde podemos tener varias cuentas a las que registramos
 * dichas transacciones.
*/

int main(){

    Presupuesto cuentas[50];
    char respuesta_usuario = ' ';
    int num_cuentas = 1;
    int cuenta_actual = 0;
    
    // Ciclo que mantiene el programa funcionando hasta que el usuario decida detenerlo
    while(respuesta_usuario != '0'){
        menu();
        std::cout << "Que desea hacer?: ";
        std::cin >> respuesta_usuario;

        switch(respuesta_usuario){

            /*
            * 
            * El el primer caso, se muestran todas las cuentas disponibles 
            * creadas por el usuario. Posteriormente, se pide que seleccione
            * una para cambiar a dicha cuenta. En caso de no haber más que una cuenta, 
            * no se permitirá realizar ningún cambio
            * 
            */
            case '1':{
                if(num_cuentas > 1){
                    std::cout << "N. de cuentas disponibles: " << num_cuentas <<std::endl;
                        for(int i = 0; i < num_cuentas; i++){
                            std::cout << (i+1) << "."<< std::endl;
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

            //En este segundo caso, se muestran los datos de todos los egresos de la cuenta.
            case '2':{
                cuentas[cuenta_actual].mostrarDatosEgresos();
                break;
            }

            //EPara el tercer caso, se hace lo mismo que en el caso anterior, ahora para los ingresos
            case '3':{
                cuentas[cuenta_actual].mostrarDatosIngresos();
                break;
            }

            //Calcula el presupuesto total de esta cuenta 
            case '4':{
                cuentas[cuenta_actual].calcularPresupuesto();
                break;
            }


            /*
             * Quinto caso. Se solicita información para crear un nuevo egreso y 
             * colocarlo en la cuenta actual
            */
            case '5':{
                float _ctd;
                std::string fecha;
                std::string fuente;
                std::string detalles;

                std::cout << "Ingrese la cantidad que se ha gastado: "<< std::endl;
                std::cin >> _ctd;
                std::cout << "Ingrese el metodo de pago: "<< std::endl;
                std::cin.ignore(1, '\n');
                std::getline(std::cin, fuente);
                std::cout << "Ingrese la fecha que se ha generado la compra: "<< std::endl;
                std::cin >> fecha;
                std::cout << "Ingrese detalles de la compra: "<< std::endl;
                std::cin.ignore(1, '\n');
                std::getline(std::cin, detalles);

                cuentas[cuenta_actual].insertarEgreso(_ctd, fecha, detalles, fuente);
                break;
            }

            //Mismo proceso que el anterior, pero ahora solicita información para insertar un ingreso
            case '6':{
                float _ctd;
                std::string fecha;
                std::string fuente;
                std::string detalles;

                std::cout << "Ingrese la cantidad que se ha ganado: "<< std::endl;
                std::cin >> _ctd;
                std::cout << "Ingrese la fuente del ingreso: "<< std::endl;
                std::cin.ignore(1, '\n');
                std::getline(std::cin, fuente);
                std::cout << "Ingrese la fecha que se ha generado el ingreso: "<< std::endl;
                std::cin >> fecha;
                std::cout << "Ingrese detalles de la transaccion: "<< std::endl;
                std::cin.ignore(1, '\n');
                std::getline(std::cin, detalles);

                cuentas[cuenta_actual].insertarIngreso(_ctd, fecha, detalles, fuente);
                break;
            }

            // Solicita información para crear una cuenta nueva
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

            //Muestra los datos de la cuenta actual (nombre, titular y numero de telefono)
            case '8':{
                cuentas[cuenta_actual].mostrarDatosUsuario();
                 break;
            }

            /*
            * Solicita información  (nombre, titular y numero de telefono) 
            * para cambiar los datos de la cuenta actual 
            */
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
    //Mensaje de agradecimiento
    std::cout << "Gracias por usar el programa!";

    return 0;
}