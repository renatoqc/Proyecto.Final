#include <iostream>
#include "articulo.h"
using namespace std;

// Definicion de la clase Fertilizante
class Fertilizante : public Articulo{
private:
    string tipo;
public:
    Fertilizante();
    Fertilizante(string n, float p, int c, string l) : Articulo (n, p, c) {
        tipo = l;
    }
    bool insuficientecantidad(int c) override
    {
        if (getCantidad() < c)
        {
            return true;
        }
        else
        {
            setCantidad(getCantidad() - c);
            return false;
        }
    }
    string getTipo() {
        return tipo;
    }
    void mostrarInformacion() const override {
        Articulo::mostrarInformacion();
        std::cout << ", Tipo: " << tipo << std::endl;
    }
};