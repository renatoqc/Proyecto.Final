#include <iostream>
#include <string>

using namespace std;


class Vendedor {
private:
    int  entrada, salida;
    string nombre, apellido;

public:
    Vendedor(int entra_, int sali_, string nom_, string ape_) {
        entrada = entra_;
        salida = sali_;
        nombre = nom_;
        apellido = ape_;
    }

    void setEntra(int entra_) {
        entrada = entra_;
    }

    void setSalid(int sali_) {
        salida = sali_;
    }

    void setNom(int nom_) {
        nombre = nom_;
    }

    void setApe(int ape_) {
        apellido = ape_;
    }

    int getEntra() {
        return entrada;
    }

    int getSali() {
        return salida;
    }

    string getNom() {
        return nombre;
    }

    string getApe() {
        return apellido;
    }

    void getDetalles() {
        std::cout << "--------------------------------------------------------------------------------------------------------------------------------" << endl;
        std::cout << "NOMBRE Y APELLIDO : " << getNom() << " " << getApe() << endl;
        std::cout << "ENTRADA : " << getEntra() << endl;
        //std::cout << "SALIDA  : " << getSali() << endl;
    }
};