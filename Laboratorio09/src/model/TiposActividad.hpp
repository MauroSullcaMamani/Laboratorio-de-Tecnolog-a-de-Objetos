#pragma once

#include "model/Actividad.hpp"

class Tarea final : public Actividad {
public:
    using Actividad::Actividad;
    std::string tipo() const override;
};

class Examen final : public Actividad {
public:
    using Actividad::Actividad;
    std::string tipo() const override;
};

class Proyecto final : public Actividad {
public:
    using Actividad::Actividad;
    std::string tipo() const override;
};
