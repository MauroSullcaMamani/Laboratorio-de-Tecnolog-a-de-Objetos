#pragma once

#include "patterns/ActividadFactory.hpp"
#include "persistence/FuenteCsvAntigua.hpp"
#include "persistence/IImportadorActividades.hpp"
#include "persistence/IRepositorioActividades.hpp"

#include <cstddef>

class AdaptadorCsvAntiguo final : public IRepositorioActividades, public IImportadorActividades {
public:
    AdaptadorCsvAntiguo(
        const FuenteCsvAntigua& fuente,
        IRepositorioActividades& repositorio,
        const ActividadFactory& fabrica
    );
    std::size_t importar() const override;
    void guardar(const RegistroActividad& actividad) override;
    std::vector<RegistroActividad> listar() const override;

private:
    const FuenteCsvAntigua& fuente_;
    IRepositorioActividades& repositorio_;
    const ActividadFactory& fabrica_;
};
