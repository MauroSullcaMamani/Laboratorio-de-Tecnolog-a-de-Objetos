#pragma once

#include "patterns/ActividadFactory.hpp"
#include "persistence/IImportadorActividades.hpp"
#include "persistence/IRepositorioActividades.hpp"

#include <string>
#include <vector>

class ActividadController {
public:
    ActividadController(
        ActividadFactory& fabrica,
        IRepositorioActividades& repositorio,
        IImportadorActividades& importador
    );
    std::string crear(
        const std::string& tipo,
        const std::string& id,
        const std::string& titulo,
        const std::string& fecha,
        const std::string& detalle
    );
    std::vector<RegistroActividad> listar() const;
    std::size_t importarCsvAntiguo() const;

private:
    ActividadFactory& fabrica_;
    IRepositorioActividades& repositorio_;
    IImportadorActividades& importador_;
};
