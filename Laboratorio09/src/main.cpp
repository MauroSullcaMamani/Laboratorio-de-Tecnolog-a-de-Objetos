#include "controller/ActividadController.hpp"
#include "patterns/ActividadFactory.hpp"
#include "patterns/AdaptadorCsvAntiguo.hpp"
#include "persistence/FuenteCsvAntigua.hpp"
#include "persistence/RepositorioCsv.hpp"
#include "view/VistaConsola.hpp"

#include <filesystem>
#include <memory>
#include <string>

int main(int argc, char** argv) {
    ActividadFactory fabrica;
    fabrica.registrar("Tarea", std::make_unique<TareaCreator>());
    fabrica.registrar("Examen", std::make_unique<ExamenCreator>());
    fabrica.registrar("Proyecto", std::make_unique<ProyectoCreator>());

    const std::filesystem::path archivo = argc > 1 ? argv[1] : "data/actividades.csv";
    RepositorioCsv repositorio(archivo);
    FuenteCsvAntigua fuente("data/actividades_legacy.csv");
    AdaptadorCsvAntiguo adaptador(fuente, repositorio, fabrica);
    ActividadController controlador(fabrica, adaptador, adaptador);
    VistaConsola vista(controlador);
    return vista.ejecutar();
}
