
#ifndef TRANSACCION_H_
#define TRANSACCION_H_
#include<string>
#include<iostream>

class Transaccion{

    protected:
        float monto;
        std::string fecha;
        std::string descripcion;
    public:
        Transaccion();
        Transaccion(float m, std::string s, std::string d): monto(m), fecha(s),descripcion(d){};
        void setMonto(float);
        void setFecha(std::string);
        void setDescripcion(std::string);
        float getMonto();
        std::string getFecha();
        std::string getDescripcion();

        virtual std::string reporte() = 0;

};
    Transaccion::Transaccion(){
        monto = 0.0;
        fecha = "";
        descripcion = "";
    }
    void Transaccion::setMonto(float f){
        monto = f;
    }
    void Transaccion::setFecha(std::string s){
        fecha = s;
    }
    void Transaccion::setDescripcion(std::string s){
        descripcion = s;
    }
    float Transaccion::getMonto(){
        return monto;
    }
    std::string Transaccion::getFecha(){
        return fecha;
    }
    std::string Transaccion::getDescripcion(){
        return descripcion;
    }

    
#endif