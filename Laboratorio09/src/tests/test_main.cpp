#include "controller/ActividadController.hpp"
#include "patterns/ActividadFactory.hpp"
#include "patterns/AdaptadorCsvAntiguo.hpp"
#include "persistence/FuenteCsvAntigua.hpp"
#include "persistence/RepositorioCsv.hpp"

#include <filesystem>
#include <fstream>
#include <functional>
#include <iostream>
#include <memory>
#include <stdexcept>
#include <string>
#include <vector>

namespace {

void verificar(bool condicion, const std::string& mensaje) {
    if (!condicion) {
        throw std::runtime_error(mensaje);
    }
}

ActividadFactory crearFabrica() {
    ActividadFactory fabrica;
    fabrica.registrar("Tarea", std::make_unique<TareaCreator>());
    fabrica.registrar("Examen", std::make_unique<ExamenCreator>());
    fabrica.registrar("Proyecto", std::make_unique<ProyectoCreator>());
    return fabrica;
}

void probarFactoryMethod() {
    auto fabrica = crearFabrica();
    const auto tarea = fabrica.crear("Tarea", "T-1", "Informe", "2026-11-22", "Capítulo 1");
    const auto examen = fabrica.crear("Examen", "E-1", "Parcial", "2026-11-23", "Unidad 3");
    const auto proyecto = fabrica.crear("Proyecto", "P-1", "Prototipo", "2026-11-24", "Entrega final");
    verificar(tarea->tipo() == "Tarea", "El creador debe devolver una tarea.");
    verificar(examen->tipo() == "Examen", "El creador debe devolver un examen.");
    verificar(proyecto->tipo() == "Proyecto", "El creador debe devolver un proyecto.");
}

void probarValidacion() {
    auto fabrica = crearFabrica();
    bool rechazado = false;
    try {
        fabrica.crear("Tarea", "T-2", "", "2026-11-22", "Detalle");
    } catch (const std::invalid_argument&) {
        rechazado = true;
    }
    verificar(rechazado, "El modelo debe rechazar títulos vacíos.");
}

void probarControlador() {
    const auto base = std::filesystem::temp_directory_path() / "lab09-controller-test";
    std::filesystem::remove_all(base);
    std::filesystem::create_directories(base);
    auto fabrica = crearFabrica();
    RepositorioCsv repositorio(base / "actividades.csv");
    FuenteCsvAntigua fuente(base / "antiguo.csv");
    AdaptadorCsvAntiguo adaptador(fuente, repositorio, fabrica);
    ActividadController controlador(fabrica, repositorio, adaptador);
    const auto mensaje = controlador.crear("Tarea", "T-3", "Lectura", "2026-11-22", "Tema MVC");
    const auto actividades = controlador.listar();
    verificar(mensaje.find("Lectura") != std::string::npos, "El controlador debe confirmar la creación.");
    verificar(actividades.size() == 1, "El controlador debe listar la actividad guardada.");
    verificar(actividades.front().tipo == "Tarea", "El registro debe conservar el tipo de actividad.");
    std::filesystem::remove_all(base);
}

void probarAdapterCsvAntiguo() {
    const auto base = std::filesystem::temp_directory_path() / "lab09-adapter-test";
    std::filesystem::remove_all(base);
    std::filesystem::create_directories(base);
    const auto archivoAntiguo = base / "antiguo.csv";
    {
        std::ofstream salida(archivoAntiguo);
        salida << "codigo;nombre;fecha_limite;clase;detalle\n";
        salida << "L-1;Tarea importada;2026-11-22;TAREA;CSV heredado\n";
    }
    auto fabrica = crearFabrica();
    RepositorioCsv repositorio(base / "actual.csv");
    FuenteCsvAntigua fuente(archivoAntiguo);
    AdaptadorCsvAntiguo adaptador(fuente, repositorio, fabrica);
    const auto cantidad = adaptador.importar();
    const auto actividades = repositorio.listar();
    const auto actividadesAdaptadas = adaptador.listar();
    verificar(cantidad == 1, "El Adapter debe importar un registro.");
    verificar(actividades.size() == 1, "El repositorio debe recibir el registro adaptado.");
    verificar(actividadesAdaptadas.size() == 1, "El Adapter debe cumplir la interfaz del repositorio.");
    verificar(actividadesAdaptadas.front().tipo == "Tarea", "El Adapter debe normalizar el tipo heredado.");
    std::filesystem::remove_all(base);
}

}

int main() {
    const std::vector<std::pair<std::string, std::function<void()>>> pruebas = {
        {"Factory Method", probarFactoryMethod},
        {"Validación del modelo", probarValidacion},
        {"Controlador sin GUI", probarControlador},
        {"Adapter CSV heredado", probarAdapterCsvAntiguo},
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
