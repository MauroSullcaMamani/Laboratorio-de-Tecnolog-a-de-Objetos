#pragma once

#include <filesystem>
#include <string>
#include <vector>

struct RegistroCsvAntiguo {
    std::string codigo;
    std::string nombre;
    std::string fecha_limite;
    std::string clase;
    std::string detalle;
};

class FuenteCsvAntigua {
public:
    explicit FuenteCsvAntigua(std::filesystem::path archivo);
    std::vector<RegistroCsvAntiguo> leer() const;

private:
    std::filesystem::path archivo_;
};
