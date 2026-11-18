#pragma once

#include "controller/ActividadController.hpp"

class VistaConsola {
public:
    explicit VistaConsola(ActividadController& controlador);
    int ejecutar();

private:
    ActividadController& controlador_;
    void mostrarMenu() const;
    void crearActividad();
    void listarActividades() const;
    void importarCsv() const;
};
