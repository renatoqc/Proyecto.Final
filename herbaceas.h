#pragma once
#include <iostream>
#include "planta.h"
using namespace std;

class Herbaceas : public Planta {
private:
	bool tieneRamificaciones;
public:
	Herbaceas(const string& n, float p, int c, string l, bool r) : Planta(n, p, c, l) {
		tieneRamificaciones = r;
	}
	void setRamificacion(bool r) {
		tieneRamificaciones = r;
	}
	string getRamificacion() {
		if (tieneRamificaciones) {
			string ramificaciones = "SI";
			return ramificaciones;
		}
		else
		{
			string ramificaciones = "NO";
			return ramificaciones;
		}
	}
	void mostrarInformacion() const override {
		Planta::mostrarInformacion();
		std::cout << "Ramificaciones: " << (tieneRamificaciones ? "SI" : "NO") << std::endl;
	}
};