#pragma once
#include <iostream>
#include "articulo.h"
using namespace std;

// DefiniciÃ³n de la clase Planta
class Planta : public Articulo {
private:
    string tipo;
public:
    Planta(const string& n, float p, int c, string l) : Articulo(n, p, c) {
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
        std::cout << ", Tipo: " << tipo << endl;
    }

    Planta() = default;
};