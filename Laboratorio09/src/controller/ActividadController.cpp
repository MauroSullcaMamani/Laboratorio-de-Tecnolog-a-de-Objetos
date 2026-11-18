#include "controller/ActividadController.hpp"

#include <utility>

ActividadController::ActividadController(
    IRepositorioActividades& repositorio,
    IImportadorCsv& importador
) : repositorio_(repositorio), importador_(importador) {}

std::string ActividadController::crear(
    const std::string& tipo,
    const std::string& id,
    const std::string& titulo,
    const std::string& fecha,
    const std::string& detalle
) {
    const auto actividad = creadorPara(tipo).crear(id, titulo, fecha, detalle);
    repositorio_.guardar(actividad->registro());
    return "Actividad creada: " + actividad->titulo();
}

std::vector<RegistroActividad> ActividadController::listar() const {
    return repositorio_.listar();
}

std::size_t ActividadController::importarCsv() const {
    return importador_.importar();
}
