#include "patterns/AdaptadorImportacionCsv.hpp"

#include <algorithm>
#include <cctype>

AdaptadorImportacionCsv::AdaptadorImportacionCsv(
    const LectorCsvImportacion& lector,
    IRepositorioActividades& repositorio
) : lector_(lector), repositorio_(repositorio) {}

std::size_t AdaptadorImportacionCsv::importar() const {
    const auto registros = lector_.leer();
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
        const auto actividad = creadorPara(tipo).crear(
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

