from horario import Horario


class Curso:
    def __init__(self, nombre: str, dia: str, hora: str):
        self.nombre = nombre
        self.horario = Horario(dia, hora)

    @property
    def nombre(self):
        return self._nombre

    @nombre.setter
    def nombre(self, valor):
        self._nombre = valor

    @property
    def horario(self):
        return self._horario

    @horario.setter
    def horario(self, valor):
        self._horario = valor

    def __str__(self):
        return f"Curso: {self.nombre} , horario: {self.horario}"

    __repr__ = __str__
