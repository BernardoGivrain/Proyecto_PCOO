#include "Transaccion.h"
#include<string>

class Egreso: public Transaccion{

    private:
        std::string  metodo_pago;
    
    public:
        Egreso();
        Egreso(float, std::string, std::string, std::string);
        void setMetodoPago(std::string);
        std::string getMetodoPago();
        std::string reporte() override;
        
};

Egreso::Egreso(){
    metodo_pago = "";
}
Egreso::Egreso(float m, std::string s, std::string d, std::string r) : Transaccion(m, s, d){
    metodo_pago = r;
}
void Egreso::setMetodoPago(std::string e){
    metodo_pago = e;
}
std::string Egreso::getMetodoPago(){
    return metodo_pago;
}
std::string Egreso::reporte(){
        return "Monto << "+std::to_string(monto) + "\nFecha << "+ fecha + "\nDescripcion << "+descripcion + "\nDetalles de la transaccion: << " + metodo_pago + "\n"; 
}


