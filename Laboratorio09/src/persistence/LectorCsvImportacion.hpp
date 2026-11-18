#pragma once

#include <filesystem>
#include <string>
#include <vector>

struct FilaCsvImportacion {
    std::string codigo;
    std::string nombre;
    std::string fecha_limite;
    std::string clase;
    std::string detalle;
};

class LectorCsvImportacion {
public:
    explicit LectorCsvImportacion(std::filesystem::path archivo);
    std::vector<FilaCsvImportacion> leer() const;

private:
    std::filesystem::path archivo_;
};
