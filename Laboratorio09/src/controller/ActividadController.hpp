#pragma once

#include "patterns/CreadorActividad.hpp"
#include "persistence/IImportadorCsv.hpp"
#include "persistence/IRepositorioActividades.hpp"

#include <string>
#include <vector>

class ActividadController {
public:
    ActividadController(
        IRepositorioActividades& repositorio,
        IImportadorCsv& importador
    );
    std::string crear(
        const std::string& tipo,
        const std::string& id,
        const std::string& titulo,
        const std::string& fecha,
        const std::string& detalle
    );
    std::vector<RegistroActividad> listar() const;
    std::size_t importarCsv() const;

private:
    IRepositorioActividades& repositorio_;
    IImportadorCsv& importador_;
};
