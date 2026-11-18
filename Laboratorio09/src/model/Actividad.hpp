#pragma once

#include <string>

struct RegistroActividad {
    std::string id;
    std::string tipo;
    std::string titulo;
    std::string fecha;
    std::string detalle;
};

class Actividad {
public:
    Actividad(std::string id, std::string titulo, std::string fecha, std::string detalle);
    virtual ~Actividad() = default;

    const std::string& id() const;
    const std::string& titulo() const;
    const std::string& fecha() const;
    const std::string& detalle() const;
    virtual std::string tipo() const = 0;
    RegistroActividad registro() const;

private:
    std::string id_;
    std::string titulo_;
    std::string fecha_;
    std::string detalle_;
};
