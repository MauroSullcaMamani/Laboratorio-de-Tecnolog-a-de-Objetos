#pragma once

#include "model/Actividad.hpp"

#include <vector>

class IRepositorioActividades {
public:
    virtual ~IRepositorioActividades() = default;
    virtual void guardar(const RegistroActividad& actividad) = 0;
    virtual std::vector<RegistroActividad> listar() const = 0;
};
