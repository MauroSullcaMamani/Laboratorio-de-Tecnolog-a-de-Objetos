from curso import Curso


class Universidad:
    def __init__(self, nombre: str):
        self.nombre = nombre
        self.cursos = []

    @property
    def nombre(self):
        return self._nombre

    @nombre.setter
    def nombre(self, valor):
        self._nombre = valor

    @property
    def cursos(self):
        return self._cursos

    @cursos.setter
    def cursos(self, valor):
        self._cursos = valor

    def agregar_curso(self, curso: Curso):
        self.cursos.append(curso)

    def __str__(self):
        return f"Universidad: {self.nombre} , cursos: {self.cursos}"
