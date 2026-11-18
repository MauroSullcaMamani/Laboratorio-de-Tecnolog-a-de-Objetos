#include "persistence/FuenteCsvAntigua.hpp"

#include <fstream>
#include <sstream>
#include <stdexcept>
#include <utility>

FuenteCsvAntigua::FuenteCsvAntigua(std::filesystem::path archivo) : archivo_(std::move(archivo)) {}

std::vector<RegistroCsvAntiguo> FuenteCsvAntigua::leer() const {
    std::ifstream entrada(archivo_);
    if (!entrada) {
        throw std::runtime_error("No se pudo abrir el CSV heredado: " + archivo_.string());
    }
    std::vector<RegistroCsvAntiguo> registros;
    std::string linea;
    std::getline(entrada, linea);
    while (std::getline(entrada, linea)) {
        std::istringstream campos(linea);
        RegistroCsvAntiguo registro;
        if (std::getline(campos, registro.codigo, ';') &&
            std::getline(campos, registro.nombre, ';') &&
            std::getline(campos, registro.fecha_limite, ';') &&
            std::getline(campos, registro.clase, ';') &&
            std::getline(campos, registro.detalle)) {
            registros.push_back(std::move(registro));
        }
    }
    return registros;
}
