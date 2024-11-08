
#include<string>

class Egreso{

    private:
        float gasto;
        std::string fuente;
        bool fijo;
    
    public:
        Egreso();
        Egreso(float, std::string, bool);
        void setFuente(std::string);
        void setGasto(float);
        void setFijo(bool);
        std::string getFuente();
        float getGasto();
        bool isFijo();
        

};

Egreso::Egreso(){
    gasto = 0.0;
    fuente = "";
    fijo = false;
}
Egreso::Egreso(float f, std::string s, bool b){
    gasto = f;
    fuente = s;
    fijo = b;
}
void Egreso::setFuente(std::string f){
    fuente = f;
}
void Egreso::setGasto(float g){
    gasto = g;
}
float Egreso::getGasto(){
    return gasto;
}
std::string Egreso::getFuente(){
    return fuente;
}
void Egreso::setFijo(bool b){
    fijo = b;
}
bool Egreso::isFijo(){
    return fijo;
}

