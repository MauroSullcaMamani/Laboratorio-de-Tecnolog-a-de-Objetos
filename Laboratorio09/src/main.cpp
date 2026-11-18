#include "controller/ActividadController.hpp"
#include "patterns/AdaptadorImportacionCsv.hpp"
#include "persistence/LectorCsvImportacion.hpp"
#include "persistence/RepositorioCsv.hpp"
#include "view/VistaConsola.hpp"

#include <filesystem>
#include <memory>
#include <string>

int main(int argc, char** argv) {
    const std::filesystem::path archivo = argc > 1 ? argv[1] : "data/actividades.csv";
    RepositorioCsv repositorio(archivo);
    LectorCsvImportacion lector("data/actividades_importar.csv");
    AdaptadorImportacionCsv adaptador(lector, repositorio);
    ActividadController controlador(repositorio, adaptador);
    VistaConsola vista(controlador);
    return vista.ejecutar();
}
