#pragma once
#include <iostream>
#include <string>

class Articulo {
protected:
    std::string nombre;
    float precio;
    int cantidad;

public:
    Articulo() = default;
    Articulo(const std::string& nombre_, float precio_, int cantidad_)
    {
        nombre = nombre_;
        precio = precio_;
        cantidad = cantidad_;
    }

    void setPrecio(float pre_) {
        precio = pre_;
    }
    std::string getNombre() {
        return nombre;
    }
    float getPrecio() {
        return precio;
    }
    int getCantidad() {
        return cantidad;
    }
    void setCantidad(int c) {
        cantidad = c;
    }
    virtual bool insuficientecantidad(int c)
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
    virtual void mostrarInformacion() const
    {
        std::cout << "Nombre: " << nombre << ", Precio: " << precio << ", Cantidad: " << cantidad;
    }
};