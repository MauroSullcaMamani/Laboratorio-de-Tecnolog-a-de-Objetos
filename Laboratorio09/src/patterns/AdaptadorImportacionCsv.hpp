#pragma once

#include "patterns/CreadorActividad.hpp"
#include "persistence/LectorCsvImportacion.hpp"
#include "persistence/IImportadorCsv.hpp"
#include "persistence/IRepositorioActividades.hpp"

#include <cstddef>

class AdaptadorImportacionCsv final : public IImportadorCsv {
public:
    AdaptadorImportacionCsv(
        const LectorCsvImportacion& lector,
        IRepositorioActividades& repositorio
    );
    std::size_t importar() const override;

private:
    const LectorCsvImportacion& lector_;
    IRepositorioActividades& repositorio_;
};
