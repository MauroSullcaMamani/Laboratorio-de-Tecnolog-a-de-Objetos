#include "persistence/RepositorioCsv.hpp"

#include <fstream>
#include <sstream>
#include <stdexcept>
#include <utility>

RepositorioCsv::RepositorioCsv(std::filesystem::path archivo) : archivo_(std::move(archivo)) {}

void RepositorioCsv::guardar(const RegistroActividad& actividad) {
    auto actividades = listar();
    bool reemplazado = false;
    for (auto& registro : actividades) {
        if (registro.id == actividad.id) {
            registro = actividad;
            reemplazado = true;
            break;
        }
    }
    if (!reemplazado) {
        actividades.push_back(actividad);
    }

    std::filesystem::create_directories(archivo_.parent_path());
    std::ofstream salida(archivo_, std::ios::trunc);
    if (!salida) {
        throw std::runtime_error("No se pudo abrir el archivo del repositorio.");
    }
    for (const auto& registro : actividades) {
        salida << registro.id << '|' << registro.tipo << '|' << registro.titulo << '|'
               << registro.fecha << '|' << registro.detalle << '\n';
    }
    if (!salida) {
        throw std::runtime_error("No se pudo escribir el archivo del repositorio.");
    }
}

std::vector<RegistroActividad> RepositorioCsv::listar() const {
    std::vector<RegistroActividad> actividades;
    if (!std::filesystem::exists(archivo_)) {
        return actividades;
    }
    std::ifstream entrada(archivo_);
    if (!entrada) {
        throw std::runtime_error("No se pudo leer el archivo del repositorio.");
    }
    std::string linea;
    while (std::getline(entrada, linea)) {
        std::istringstream campos(linea);
        RegistroActividad registro;
        if (std::getline(campos, registro.id, '|') &&
            std::getline(campos, registro.tipo, '|') &&
            std::getline(campos, registro.titulo, '|') &&
            std::getline(campos, registro.fecha, '|') &&
            std::getline(campos, registro.detalle)) {
            actividades.push_back(std::move(registro));
        }
    }
    return actividades;
}
