# Laboratorio 09: seguimiento académico

Material de entrega: informe PDF, código fuente C++, pruebas, diagramas UML y evidencias de ejecución. La aplicación es de consola y organiza sus responsabilidades con MVC, Factory Method y Adapter.

## Compilar y probar

Requisitos: GCC 16.2.1 y CMake 4.5.0.

```bash
cmake -S . -B build
cmake --build build
ctest --test-dir build --output-on-failure
```

## Ejecutar

```bash
./build/seguimiento data/actividades-demo.csv
```

El menú permite crear y listar tareas, exámenes y proyectos, e importar `data/actividades_legacy.csv`.

## Contenido

- `submission/Informe_09.pdf`: informe completo.
- `submission/Código Fuente_09.zip`: paquete de código entregable.
- `src/`: implementación C++ y pruebas del Modelo, Controlador y Adapter.
- `diagrams/`: fuentes PlantUML; `images/`: diagramas renderizados y capturas.
- `evidencias/demo.mp4`: demostración breve de los flujos y pruebas.
- `data/actividades_legacy.csv`: datos de ejemplo para la importación.
