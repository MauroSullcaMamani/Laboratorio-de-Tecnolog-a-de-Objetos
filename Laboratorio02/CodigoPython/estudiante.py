from persona import Persona


class Estudiante(Persona):
    def __init__(self, nombre: str, edad: int):
        super().__init__(nombre, edad)

    def __str__(self):
        return f"Estudiante: {self.nombre} ; edad: {self.edad}"
