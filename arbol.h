#pragma once
#include <iostream>
#include "planta.h"
using namespace std;

class Arboles : public Planta {
private:
	string especie;
public:
	Arboles(const string& n, float p, int c, string l, string e) : Planta(n, p, c, l) {
		especie = e;
	}
	void setAltura(int e) {
		especie = e;
	}
	string getAltura() {
		return especie;
	}
	void mostrarInformacion() const override {
		Planta::mostrarInformacion();
		std::cout << "Especias: " << especie << "/n" << std::endl;
	}
};