#include "model/TiposActividad.hpp"

std::string Tarea::tipo() const {
    return "Tarea";
}

std::string Examen::tipo() const {
    return "Examen";
}

std::string Proyecto::tipo() const {
    return "Proyecto";
}
