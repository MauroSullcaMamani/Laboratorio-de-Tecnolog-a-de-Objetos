#pragma once

#include "model/Actividad.hpp"

#include <map>
#include <memory>
#include <string>

class ActividadCreator {
public:
    virtual ~ActividadCreator() = default;
    virtual std::unique_ptr<Actividad> crear(
        const std::string& id,
        const std::string& titulo,
        const std::string& fecha,
        const std::string& detalle
    ) const = 0;
};

class TareaCreator final : public ActividadCreator {
public:
    std::unique_ptr<Actividad> crear(
        const std::string& id,
        const std::string& titulo,
        const std::string& fecha,
        const std::string& detalle
    ) const override;
};

class ExamenCreator final : public ActividadCreator {
public:
    std::unique_ptr<Actividad> crear(
        const std::string& id,
        const std::string& titulo,
        const std::string& fecha,
        const std::string& detalle
    ) const override;
};

class ProyectoCreator final : public ActividadCreator {
public:
    std::unique_ptr<Actividad> crear(
        const std::string& id,
        const std::string& titulo,
        const std::string& fecha,
        const std::string& detalle
    ) const override;
};

class ActividadFactory {
public:
    void registrar(const std::string& tipo, std::unique_ptr<ActividadCreator> creator);
    std::unique_ptr<Actividad> crear(
        const std::string& tipo,
        const std::string& id,
        const std::string& titulo,
        const std::string& fecha,
        const std::string& detalle
    ) const;

private:
    std::map<std::string, std::unique_ptr<ActividadCreator>> creators_;
};
