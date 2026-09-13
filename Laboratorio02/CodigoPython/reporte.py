class Reporte:
    def generar_reporte(self, estudiante):
        print("REPORTE DEL ESTUDIANTE")
        print(f"Nombre: {estudiante.nombre}")
        print(f"Edad: {estudiante.edad}")
        print()

    def __str__(self):
        return "Reporte{}"
