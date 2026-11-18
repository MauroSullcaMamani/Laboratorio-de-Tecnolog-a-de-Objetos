#include "view/VistaConsola.hpp"

#include <iostream>
#include <limits>
#include <string>

VistaConsola::VistaConsola(ActividadController& controlador) : controlador_(controlador) {}

int VistaConsola::ejecutar() {
    std::string opcion;
    do {
        mostrarMenu();
        std::getline(std::cin, opcion);
        try {
            if (opcion == "1") {
                crearActividad();
            } else if (opcion == "2") {
                listarActividades();
            } else if (opcion == "3") {
                importarCsv();
            } else if (opcion != "0") {
                std::cout << "Opción no válida.\n";
            }
        } catch (const std::exception& error) {
            std::cout << "Error: " << error.what() << '\n';
        }
    } while (opcion != "0");
    return 0;
}

void VistaConsola::mostrarMenu() const {
    std::cout << "\nSEGUIMIENTO ACADÉMICO\n"
              << "1. Crear actividad\n"
              << "2. Listar actividades\n"
              << "3. Importar CSV de origen\n"
              << "0. Salir\n"
              << "Opción: ";
}

void VistaConsola::crearActividad() {
    std::string tipo;
    std::string id;
    std::string titulo;
    std::string fecha;
    std::string detalle;
    std::cout << "Tipo (Tarea/Examen/Proyecto): ";
    std::getline(std::cin, tipo);
    std::cout << "Código: ";
    std::getline(std::cin, id);
    std::cout << "Título: ";
    std::getline(std::cin, titulo);
    std::cout << "Fecha (AAAA-MM-DD): ";
    std::getline(std::cin, fecha);
    std::cout << "Detalle: ";
    std::getline(std::cin, detalle);
    std::cout << controlador_.crear(tipo, id, titulo, fecha, detalle) << '\n';
}

void VistaConsola::listarActividades() const {
    const auto actividades = controlador_.listar();
    if (actividades.empty()) {
        std::cout << "No hay actividades registradas.\n";
        return;
    }
    for (const auto& actividad : actividades) {
        std::cout << actividad.id << " | " << actividad.tipo << " | " << actividad.titulo
                  << " | " << actividad.fecha << " | " << actividad.detalle << '\n';
    }
}

void VistaConsola::importarCsv() const {
    const auto total = controlador_.importarCsv();
    std::cout << "Registros importados: " << total << '\n';
}
