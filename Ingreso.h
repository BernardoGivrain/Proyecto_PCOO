
#include<string>

class Ingreso{

    private:
        float ganancia;
        std::string fuente;
    
    public:
        Ingreso();
        Ingreso(float, std::string);
        void setFuente(std::string);
        void setGanancia(float);
        std::string getFuente();
        float getGanancia();

};


Ingreso::Ingreso(){
    ganancia = 0.0;
    fuente = "";
}

Ingreso::Ingreso(float f, std::string s){
    ganancia = f;
    fuente = s;
}

void Ingreso::setFuente(std::string f){
    fuente = f;
}
void Ingreso::setGanancia(float g){
    ganancia = g;
}
float Ingreso::getGanancia(){
    return ganancia;
}
std::string Ingreso::getFuente(){
    return fuente;
}




