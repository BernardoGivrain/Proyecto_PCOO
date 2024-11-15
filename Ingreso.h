
#include "Transaccion.h"
#include<string>

class Ingreso: public Transaccion{

    private:
        std::string tipo_ingreso;
    
    public:
        Ingreso();
        Ingreso(float, std::string, std::string, std::string);
        std::string getTipoIngreso();
        void setTipoIngreso(std::string);
        std::string reporte() override;

};

Ingreso::Ingreso(float m, std::string s, std::string d, std::string r) : Transaccion(m, s, d){
    tipo_ingreso = r;
}
Ingreso::Ingreso(){
    tipo_ingreso = "";
}
std::string Ingreso::getTipoIngreso(){
    return tipo_ingreso;
}
void Ingreso::setTipoIngreso(std::string b){
    tipo_ingreso = b;
}
std::string Ingreso::reporte(){
        return "Monto << "+std::to_string(monto) + "\nFecha << "+ fecha + "\nDescripcion << "+descripcion + "\nTipo de ingreso: << " + tipo_ingreso + "\n"; 
}
