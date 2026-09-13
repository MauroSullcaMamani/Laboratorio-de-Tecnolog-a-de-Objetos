from persona import Persona


class Profesor(Persona):
    def __init__(self, nombre: str, edad: int):
        super().__init__(nombre, edad)

    def __str__(self):
        return f"Profesor: {self.nombre} ; edad: {self.edad}"
