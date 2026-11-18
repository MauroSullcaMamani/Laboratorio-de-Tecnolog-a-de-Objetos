#include "model/Actividad.hpp"

#include <stdexcept>
#include <utility>

Actividad::Actividad(std::string id, std::string titulo, std::string fecha, std::string detalle)
    : id_(std::move(id)), titulo_(std::move(titulo)), fecha_(std::move(fecha)), detalle_(std::move(detalle)) {
    if (id_.empty() || titulo_.empty() || fecha_.empty() || detalle_.empty()) {
        throw std::invalid_argument("Los campos de la actividad son obligatorios.");
    }
}

const std::string& Actividad::id() const {
    return id_;
}

const std::string& Actividad::titulo() const {
    return titulo_;
}

const std::string& Actividad::fecha() const {
    return fecha_;
}

const std::string& Actividad::detalle() const {
    return detalle_;
}

RegistroActividad Actividad::registro() const {
    return {id_, tipo(), titulo_, fecha_, detalle_};
}
