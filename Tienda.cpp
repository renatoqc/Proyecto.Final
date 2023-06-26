#include <iostream>
#include <fstream>
#include <string>
#include "planta.h"
#include "vendedor.h"
#include "semilla.h"
#include "maceta.h"
#include "plagas.h"
#include "fertilizante.h"
#include "bienvenida.h"
#include "herbaceas.h"
#include "arbol.h"
#include "arbustos.h"
#include "matas.h"

using namespace std;

int main() {

    imprimirBienvenida();

    std::cout << "Ingrese su nombre: ";
    string nom_;
    std::cin >> nom_;

    std::cout << "Ingrese su apellido: ";
    string ape_;
    std::cin >> ape_;

    std::cout << "Hora de entrada: ";
    int entra_;
    std::cin >> entra_;

    Vendedor vendedor(entra_, 0, nom_, ape_);

    Planta plantas[15] = {
        Herbaceas("Perejil", 2.5, 10, "Herbacea", true),
        Herbaceas("Girasol", 5.0, 10, "Herbacea", true),
        Herbaceas("Lavanda de mar", 15.5, 10, "Herbacea", true),
        Herbaceas("Delfinio", 30.5, 10, "Herbacea", true),

        Matas("Desértico micrófilo", 20.0, 5, "Matas", 4),
        Matas("Desértico rosetófilo", 25.0, 5, "Matas", 4),
        Matas("Vegetación halófila", 15.0, 5, "Matas", 4),

        Arbustos("Buganvilla", 15.0, 3, "Arbustos", 1.2F),
        Arbustos("Rosa de China", 15.0, 3, "Arbustos", 1.2F),
        Arbustos("Camelia", 15.0, 3, "Arbustos", 1.2F),
        Arbustos("Lechera del Cabo", 24.0, 3, "Arbustos", 1.2F),

        Arboles("Pino", 50.0, 1, "Arboles", "Pinus sylvestris"),
        Arboles("Fresno", 55.0, 1, "Arboles", "Fraxinus"),
        Arboles("Ciruelo", 40.0, 1, "Arboles", "Prunus domestica"),
        Arboles("Gingko", 40.0, 1, "Arboles", "Ginkgo biloba"),
    };

    Semilla semillas[5] = {
        Semilla("Semillas de Margarita", 2.0f, 5, "Semilla"),
        Semilla("Semillas de Orquídea", 5.0f, 14, "Semilla"),
        Semilla("Semillas de Rosa", 2.0f, 11, "Semilla"),
        Semilla("Semillas de Girasol", 1.8f, 6, "Semilla"),
        Semilla("Semillas de Crisantemo", 2.2f, 10, "Semilla")
    };

    Maceta macetas[4] = {
       Maceta("Maceta grande", 10.0, 6, "Maceta"),
       Maceta("Maceta mediana", 15.0, 8, "Maceta"),
       Maceta("Maceta pequeña", 20.0, 11, "Maceta"),
       Maceta("-",3.1f,5,"-")
    };

    Plaga plagas[3] = {
       Plaga("Insecticida", 10.0, 6, "Control de plagas"),
       Plaga("Fungicidas", 15.0, 8, "Control de plagas"),
       Plaga("Acaricidas", 20.0, 11, "Control de plagas"),
    };

    Fertilizante fertilizantes[3] = {
       Fertilizante("Abono granulado", 10.0, 6, "Fertilizante"),
       Fertilizante("Abono químico", 15.0, 8, "Fertilizante"),
       Fertilizante("Abono orgánico", 20.0, 11, "Fertilizante"),
    };

    int numero = 0;
    // Mostrar la lista de plantas y sus precios
    std::cout << "Listado de plantas en el vivero:" << endl;
    for (int i = 0; i < sizeof(plantas) / sizeof(Planta); i++) {
        plantas[i].mostrarInformacion();
        numero++;
    }

    std::cout << endl << "Listado de semillas en el vivero:" << endl;
    for (int i = 0; i < sizeof(semillas) / sizeof(Semilla); i++) {
        semillas[i].mostrarInformacion();
        numero++;
    }

    std::cout << endl << "Listado de macetas en el vivero:" << endl;
    for (int i = 0; i < sizeof(macetas) / sizeof(Maceta); i++) {
        macetas[i].mostrarInformacion();
        numero++;
    }

    std::cout << endl << "Listado de fertilizantes en el vivero:" << endl;
    for (int i = 0; i < sizeof(fertilizantes) / sizeof(Fertilizante); i++) {
        fertilizantes[i].mostrarInformacion();
        numero++;
    }

    std::cout << endl << "Listado de artículos de control de plagas en el vivero:" << endl;
    for (int i = 0; i < sizeof(plagas) / sizeof(Plaga); i++) {
        plagas[i].mostrarInformacion();
        numero++;
    }

    int cantidad=0;
    float total = 0;
    bool seguirComprando = true;
    int opcion;

    while (seguirComprando) {

        std::cout << "Ingrese el número del elemento que desea comprar: ";
        std::cin >> opcion;


        if (opcion == 0) {
            seguirComprando = false;
            break;
        }
        opcion--;

        std::cout << "Ingrese la cantidad que desea comprar: ";
        std::cin >> cantidad;

        // Verificar si la opción ingresada es válida
        if (opcion >= 0 && opcion < sizeof(plantas) / sizeof(Planta) + sizeof(semillas) / sizeof(Semilla) + sizeof(macetas) / sizeof(Maceta) + sizeof(fertilizantes) / sizeof(Fertilizante) + sizeof(plagas) / sizeof(Plaga)) {
            if (opcion < sizeof(plantas) / sizeof(Planta)) {
                // Obtener la planta seleccionada en estos entra a planta crea una plantaSeleccionada y le pone todo lo de la planta seleccionada
                Planta& plantaSeleccionada = plantas[opcion];
                std::cout << "Ha seleccionado la planta: " << plantaSeleccionada.getNombre() << " S/." << plantaSeleccionada.getPrecio() << std::endl;
                std::cout << "Hay " << plantaSeleccionada.getCantidad() << std::endl;
                bool siguecantidad = true;
                do
                {
                    if (!plantaSeleccionada.insuficientecantidad(cantidad))
                    {
                        plantaSeleccionada.setCantidad(plantaSeleccionada.getCantidad() - cantidad/2);
                        total += cantidad * plantaSeleccionada.getPrecio();
                        siguecantidad = false;
                    }
                } while (siguecantidad);
            }
            else if (opcion < sizeof(plantas) / sizeof(Planta) + sizeof(semillas) / sizeof(Semilla)) {
                // Obtener la semilla seleccionada aca las semillas
                Semilla& semillaSeleccionada = semillas[opcion - sizeof(plantas) / sizeof(Planta)];
                std::cout << "Ha seleccionado la semilla: " << semillaSeleccionada.getNombre() << " S/." << semillaSeleccionada.getPrecio() << std::endl;
                std::cout << "Hay " << semillaSeleccionada.getCantidad() << std::endl;
                bool siguecantidad = true;
                do
                {
                    if (!semillaSeleccionada.insuficientecantidad(cantidad))
                    {
                        semillaSeleccionada.setCantidad(semillaSeleccionada.getCantidad() - cantidad/2);
                        total += cantidad * semillaSeleccionada.getPrecio();
                        siguecantidad = false;
                    }
                } while (siguecantidad);
            }
            else if (opcion < sizeof(plantas) / sizeof(Planta) + sizeof(semillas) / sizeof(Semilla) + sizeof(macetas) / sizeof(Maceta)) {
                // Obtener la maceta seleccionada aca macetas
                Maceta& macetaSeleccionada = macetas[opcion - sizeof(plantas) / sizeof(Planta) - sizeof(semillas) / sizeof(Semilla)];
                std::cout << "Ha seleccionado la maceta: " << macetaSeleccionada.getNombre() << " S/." << macetaSeleccionada.getPrecio() << std::endl;
                std::cout << "Hay " << macetaSeleccionada.getCantidad() << std::endl;
                bool siguecantidad = true;
                do
                {
                    if (!macetaSeleccionada.insuficientecantidad(cantidad))
                    {
                        macetaSeleccionada.setCantidad(macetaSeleccionada.getCantidad() - cantidad/2);
                        total += cantidad * macetaSeleccionada.getPrecio();
                        siguecantidad = false;
                    }
                } while (siguecantidad);
            }
            else if (opcion < sizeof(plantas) / sizeof(Planta) + sizeof(semillas) / sizeof(Semilla) + sizeof(macetas) / sizeof(Maceta) + sizeof(fertilizantes) / sizeof(Fertilizante)) {
                // Obtener el fertilizante seleccionado fertilizantes
                Fertilizante& fertilizanteSeleccionado = fertilizantes[opcion - sizeof(plantas) / sizeof(Planta) - sizeof(semillas) / sizeof(Semilla) - sizeof(macetas) / sizeof(Maceta)];
                std::cout << "Ha seleccionado el fertilizante: " << fertilizanteSeleccionado.getNombre() << " S/." << fertilizanteSeleccionado.getPrecio() << std::endl;
                std::cout << "Hay " << fertilizanteSeleccionado.getCantidad() << std::endl;
                bool siguecantidad = true;
                do
                {
                    if (!fertilizanteSeleccionado.insuficientecantidad(cantidad))
                    {
                        fertilizanteSeleccionado.setCantidad(fertilizanteSeleccionado.getCantidad() - cantidad/2);
                        total += cantidad * fertilizanteSeleccionado.getPrecio();
                        siguecantidad = false;
                    }
                } while (siguecantidad);
            }
            else {
                // Obtener el artículo de control de plagas seleccionado
                Plaga plagaSeleccionada = plagas[opcion - sizeof(plantas) / sizeof(Planta) - sizeof(semillas) / sizeof(Semilla) - sizeof(macetas) / sizeof(Maceta) - sizeof(fertilizantes) / sizeof(Fertilizante)];
                std::cout << "Ha seleccionado el artículo de control de plagas: " << plagaSeleccionada.getNombre() << " S/." << plagaSeleccionada.getPrecio() << std::endl;
                std::cout << "Hay " << plagaSeleccionada.getCantidad() << std::endl;
                bool siguecantidad = true;
                do
                {
                    if (!plagaSeleccionada.insuficientecantidad(cantidad))
                    {
                        plagaSeleccionada.setCantidad(plagaSeleccionada.getCantidad() - cantidad/2);
                        total += cantidad * plagaSeleccionada.getPrecio();
                        siguecantidad = false;
                    }
                } while (siguecantidad);
            }
        }
        else {
            std::cout << "Opción inválida. Por favor, seleccione un número válido." << std::endl;
        }
    }
    std::cout << "Compra realizada con éxito. Total a pagar: $" << total << endl;

    std::cout << "Hora de salida: ";
    int sali_;
    std::cin >> sali_;

    return 0;
}