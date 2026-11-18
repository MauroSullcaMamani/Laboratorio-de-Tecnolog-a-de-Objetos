#include "patterns/AdaptadorCsvAntiguo.hpp"

#include <algorithm>
#include <cctype>

AdaptadorCsvAntiguo::AdaptadorCsvAntiguo(
    const FuenteCsvAntigua& fuente,
    IRepositorioActividades& repositorio,
    const ActividadFactory& fabrica
) : fuente_(fuente), repositorio_(repositorio), fabrica_(fabrica) {}

std::size_t AdaptadorCsvAntiguo::importar() const {
    const auto registros = fuente_.leer();
    std::size_t importados = 0;
    for (const auto& registro : registros) {
        std::string tipo = registro.clase;
        std::transform(tipo.begin(), tipo.end(), tipo.begin(), [](unsigned char letra) {
            return static_cast<char>(std::toupper(letra));
        });
        if (tipo == "TAREA") {
            tipo = "Tarea";
        } else if (tipo == "EXAMEN") {
            tipo = "Examen";
        } else if (tipo == "PROYECTO") {
            tipo = "Proyecto";
        }
        const auto actividad = fabrica_.crear(
            tipo,
            registro.codigo,
            registro.nombre,
            registro.fecha_limite,
            registro.detalle
        );
        repositorio_.guardar(actividad->registro());
        ++importados;
    }
    return importados;
}

void AdaptadorCsvAntiguo::guardar(const RegistroActividad& actividad) {
    repositorio_.guardar(actividad);
}

std::vector<RegistroActividad> AdaptadorCsvAntiguo::listar() const {
    return repositorio_.listar();
}
