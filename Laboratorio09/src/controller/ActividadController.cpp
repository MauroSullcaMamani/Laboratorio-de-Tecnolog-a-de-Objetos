#include "controller/ActividadController.hpp"

#include <utility>

ActividadController::ActividadController(
    ActividadFactory& fabrica,
    IRepositorioActividades& repositorio,
    IImportadorActividades& importador
) : fabrica_(fabrica), repositorio_(repositorio), importador_(importador) {}

std::string ActividadController::crear(
    const std::string& tipo,
    const std::string& id,
    const std::string& titulo,
    const std::string& fecha,
    const std::string& detalle
) {
    const auto actividad = fabrica_.crear(tipo, id, titulo, fecha, detalle);
    repositorio_.guardar(actividad->registro());
    return "Actividad creada: " + actividad->titulo();
}

std::vector<RegistroActividad> ActividadController::listar() const {
    return repositorio_.listar();
}

std::size_t ActividadController::importarCsvAntiguo() const {
    return importador_.importar();
}
