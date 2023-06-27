#pragma once
#include <iostream>
#include "planta.h"
using namespace std;

class Arbustos : public Planta {
private:
	float altura;
public:
	Arbustos(const string& n, float p, int c, string l, float a) : Planta(n, p, c, l) {
		altura = a;
	}
	void setAltura(float a) {
		altura = a;
	}
	int getAltura() {
		return altura;
	}
	void mostrarInformacion() const override {
		Planta::mostrarInformacion();
		std::cout << "Cantidad de ramas: " << altura << std::endl;
	}
};