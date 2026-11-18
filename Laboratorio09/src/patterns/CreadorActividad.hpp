#pragma once

#include "model/Actividad.hpp"

#include <memory>
#include <string>

class CreadorActividad {
public:
    virtual ~CreadorActividad() = default;
    std::unique_ptr<Actividad> crear(
        const std::string& id,
        const std::string& titulo,
        const std::string& fecha,
        const std::string& detalle
    ) const;

protected:
    virtual std::unique_ptr<Actividad> factoryMethod(
        const std::string& id,
        const std::string& titulo,
        const std::string& fecha,
        const std::string& detalle
    ) const = 0;
};

class CreadorTarea final : public CreadorActividad {
protected:
    std::unique_ptr<Actividad> factoryMethod(
        const std::string& id,
        const std::string& titulo,
        const std::string& fecha,
        const std::string& detalle
    ) const override;
};

class CreadorExamen final : public CreadorActividad {
protected:
    std::unique_ptr<Actividad> factoryMethod(
        const std::string& id,
        const std::string& titulo,
        const std::string& fecha,
        const std::string& detalle
    ) const override;
};

class CreadorProyecto final : public CreadorActividad {
protected:
    std::unique_ptr<Actividad> factoryMethod(
        const std::string& id,
        const std::string& titulo,
        const std::string& fecha,
        const std::string& detalle
    ) const override;
};

const CreadorActividad& creadorPara(const std::string& tipo);
