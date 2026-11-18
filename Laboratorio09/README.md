# Laboratorio 09: seguimiento académico

Aplicación C++ de consola para registrar y consultar tareas, exámenes y proyectos. Separa Vista, Controlador y Modelo, aplica Factory Method para crear actividades y Adapter para importar filas CSV. No utiliza Qt.

## Compilar y ejecutar

Requiere CMake 3.20 o superior y un compilador con soporte para C++17 o posterior.

```bash
cmake -S . -B build
cmake --build build
ctest --test-dir build --output-on-failure
./build/seguimiento data/actividades.csv
```

El menú permite crear y listar actividades e importar `data/actividades_importar.csv`. Al crear una actividad se solicita tipo, código, título, fecha (`AAAA-MM-DD`) y detalle. El archivo pasado como argumento guarda los registros actuales.

## Archivos

- `src/model/`: productos y entidades del Modelo.
- `src/patterns/CreadorActividad.*`: Creator y Concrete Creators de Factory Method.
- `src/patterns/AdaptadorImportacionCsv.*`: Adapter para importar filas al repositorio actual.
- `src/controller/` y `src/view/`: coordinación MVC e interfaz de consola.
- `diagrams/` e `images/`: fuentes de diagramas y sus imágenes renderizadas.
- `evidencias/` e `images/`: demostración y capturas de ejecución.
- `submission/`: informe y paquete de código entregados.
