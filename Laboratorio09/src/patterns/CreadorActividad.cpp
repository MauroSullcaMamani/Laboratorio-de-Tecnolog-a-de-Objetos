#include "patterns/CreadorActividad.hpp"

#include "model/TiposActividad.hpp"

#include <stdexcept>

std::unique_ptr<Actividad> CreadorActividad::crear(
    const std::string& id,
    const std::string& titulo,
    const std::string& fecha,
    const std::string& detalle
) const {
    return factoryMethod(id, titulo, fecha, detalle);
}

std::unique_ptr<Actividad> CreadorTarea::factoryMethod(
    const std::string& id,
    const std::string& titulo,
    const std::string& fecha,
    const std::string& detalle
) const {
    return std::make_unique<Tarea>(id, titulo, fecha, detalle);
}

std::unique_ptr<Actividad> CreadorExamen::factoryMethod(
    const std::string& id,
    const std::string& titulo,
    const std::string& fecha,
    const std::string& detalle
) const {
    return std::make_unique<Examen>(id, titulo, fecha, detalle);
}

std::unique_ptr<Actividad> CreadorProyecto::factoryMethod(
    const std::string& id,
    const std::string& titulo,
    const std::string& fecha,
    const std::string& detalle
) const {
    return std::make_unique<Proyecto>(id, titulo, fecha, detalle);
}

const CreadorActividad& creadorPara(const std::string& tipo) {
    static const CreadorTarea tarea;
    static const CreadorExamen examen;
    static const CreadorProyecto proyecto;

    if (tipo == "Tarea") {
        return tarea;
    }
    if (tipo == "Examen") {
        return examen;
    }
    if (tipo == "Proyecto") {
        return proyecto;
    }
    throw std::invalid_argument("Tipo de actividad desconocido: " + tipo);
}
