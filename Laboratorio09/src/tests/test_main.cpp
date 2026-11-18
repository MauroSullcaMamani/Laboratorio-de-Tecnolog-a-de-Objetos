#include "controller/ActividadController.hpp"
#include "patterns/AdaptadorImportacionCsv.hpp"
#include "persistence/LectorCsvImportacion.hpp"
#include "persistence/RepositorioCsv.hpp"

#include <filesystem>
#include <fstream>
#include <functional>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

namespace {

void verificar(bool condicion, const std::string& mensaje) {
    if (!condicion) {
        throw std::runtime_error(mensaje);
    }
}

void probarFactoryMethod() {
    const auto tarea = creadorPara("Tarea").crear("T-1", "Informe", "2026-11-22", "Capítulo 1");
    const auto examen = creadorPara("Examen").crear("E-1", "Parcial", "2026-11-23", "Unidad 3");
    const auto proyecto = creadorPara("Proyecto").crear("P-1", "Prototipo", "2026-11-24", "Entrega final");
    verificar(tarea->tipo() == "Tarea", "El creador concreto debe producir una tarea.");
    verificar(examen->tipo() == "Examen", "El creador concreto debe producir un examen.");
    verificar(proyecto->tipo() == "Proyecto", "El creador concreto debe producir un proyecto.");
}

void probarControlador() {
    const auto base = std::filesystem::temp_directory_path() / "lab09-controller-test";
    std::filesystem::remove_all(base);
    std::filesystem::create_directories(base);
    RepositorioCsv repositorio(base / "actividades.csv");
    LectorCsvImportacion lector(base / "actividades_importar.csv");
    AdaptadorImportacionCsv adaptador(lector, repositorio);
    ActividadController controlador(repositorio, adaptador);
    const auto mensaje = controlador.crear("Tarea", "T-3", "Lectura", "2026-11-22", "Tema MVC");
    const auto actividades = controlador.listar();
    verificar(mensaje.find("Lectura") != std::string::npos, "El controlador debe confirmar la creación.");
    verificar(actividades.size() == 1, "El controlador debe listar la actividad guardada.");
    verificar(actividades.front().tipo == "Tarea", "El registro debe conservar el tipo.");
    std::filesystem::remove_all(base);
}

void probarAdaptadorCsv() {
    const auto base = std::filesystem::temp_directory_path() / "lab09-adapter-test";
    std::filesystem::remove_all(base);
    std::filesystem::create_directories(base);
    const auto archivo = base / "origen.csv";
    {
        std::ofstream salida(archivo);
        salida << "codigo;nombre;fecha_limite;clase;detalle\n";
        salida << "L-1;Tarea importada;2026-11-22;TAREA;Formato de origen\n";
    }
    RepositorioCsv repositorio(base / "actividades.csv");
    LectorCsvImportacion lector(archivo);
    AdaptadorImportacionCsv adaptador(lector, repositorio);
    const auto cantidad = adaptador.importar();
    const auto actividades = repositorio.listar();
    verificar(cantidad == 1, "El Adapter debe importar una fila.");
    verificar(actividades.size() == 1, "El Adapter debe guardar la fila convertida.");
    verificar(actividades.front().tipo == "Tarea", "El Adapter debe convertir el tipo de origen.");
    std::filesystem::remove_all(base);
}

}

int main() {
    const std::vector<std::pair<std::string, std::function<void()>>> pruebas = {
        {"Factory Method", probarFactoryMethod},
        {"MVC", probarControlador},
        {"Adapter CSV", probarAdaptadorCsv},
    };
    std::size_t aprobadas = 0;
    for (const auto& [nombre, prueba] : pruebas) {
        try {
            prueba();
            std::cout << "[OK] " << nombre << '\n';
            ++aprobadas;
        } catch (const std::exception& error) {
            std::cerr << "[FALLO] " << nombre << ": " << error.what() << '\n';
            return 1;
        }
    }
    std::cout << aprobadas << " pruebas aprobadas.\n";
    return 0;
}
