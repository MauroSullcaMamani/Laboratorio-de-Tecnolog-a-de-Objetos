#include "patterns/ActividadFactory.hpp"

#include "model/TiposActividad.hpp"

#include <stdexcept>
#include <utility>

std::unique_ptr<Actividad> TareaCreator::crear(
    const std::string& id,
    const std::string& titulo,
    const std::string& fecha,
    const std::string& detalle
) const {
    return std::make_unique<Tarea>(id, titulo, fecha, detalle);
}

std::unique_ptr<Actividad> ExamenCreator::crear(
    const std::string& id,
    const std::string& titulo,
    const std::string& fecha,
    const std::string& detalle
) const {
    return std::make_unique<Examen>(id, titulo, fecha, detalle);
}

std::unique_ptr<Actividad> ProyectoCreator::crear(
    const std::string& id,
    const std::string& titulo,
    const std::string& fecha,
    const std::string& detalle
) const {
    return std::make_unique<Proyecto>(id, titulo, fecha, detalle);
}

void ActividadFactory::registrar(const std::string& tipo, std::unique_ptr<ActividadCreator> creator) {
    if (tipo.empty() || !creator) {
        throw std::invalid_argument("El tipo y su creador son obligatorios.");
    }
    creators_[tipo] = std::move(creator);
}

std::unique_ptr<Actividad> ActividadFactory::crear(
    const std::string& tipo,
    const std::string& id,
    const std::string& titulo,
    const std::string& fecha,
    const std::string& detalle
) const {
    const auto found = creators_.find(tipo);
    if (found == creators_.end()) {
        throw std::invalid_argument("Tipo de actividad desconocido: " + tipo);
    }
    return found->second->crear(id, titulo, fecha, detalle);
}
