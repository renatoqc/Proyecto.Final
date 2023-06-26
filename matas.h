#pragma once
#include <iostream>
#include "planta.h"
using namespace std;

class Matas : public Planta {
private:
	int cantidadRamas;
public:
	Matas(const string& n, float p, int c, string l, int r) : Planta(n, p, c, l) {
		cantidadRamas = r;
	}
	void setRamas(int r) {
		cantidadRamas = r;
	}
	int getRamas() {
		return cantidadRamas;
	} 
	void mostrarInformacion() const override {
		Planta::mostrarInformacion();
		std::cout << "Cantidad de ramas: " << cantidadRamas << std::endl;
	}
};