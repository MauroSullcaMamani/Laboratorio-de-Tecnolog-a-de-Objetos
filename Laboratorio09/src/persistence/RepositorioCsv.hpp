#pragma once

#include "persistence/IRepositorioActividades.hpp"

#include <filesystem>
#include <vector>

class RepositorioCsv final : public IRepositorioActividades {
public:
    explicit RepositorioCsv(std::filesystem::path archivo);
    void guardar(const RegistroActividad& actividad) override;
    std::vector<RegistroActividad> listar() const override;

private:
    std::filesystem::path archivo_;
};
