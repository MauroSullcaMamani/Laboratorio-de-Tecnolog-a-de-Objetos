# Actividad 2: QVector y QList

`QList` y `QVector` son contenedores secuenciales de Qt. En Qt 6, `QVector` es un alias de `QList`, por lo que comparten almacenamiento y rendimiento; normalmente se elige `QList` por ser el nombre recomendado.

En Qt 5, `QVector` almacenaba los elementos de forma contigua y era conveniente para acceso rápido por índice y compatibilidad con APIs que requieren memoria contigua. `QList` ofrecía una interfaz flexible, pero su almacenamiento podía tener más sobrecarga para ciertos tipos. La implementación y el rendimiento dependían del tipo de elemento y de la operación.

| Contenedor | Ventajas | Desventajas |
| --- | --- | --- |
| `QVector` | En Qt 5, almacenamiento contiguo y acceso eficiente por índice. | En Qt 6 no aporta una implementación distinta de `QList`; su nombre puede confundir en código nuevo. |
| `QList` | Interfaz ampliamente usada en Qt y nombre recomendado para Qt 6. | En Qt 5, el rendimiento y la contigüidad dependían de la implementación y del tipo de elemento. |
