class Horario:
    def __init__(self, dia: str, hora: str):
        self.dia = dia
        self.hora = hora

    def __str__(self):
        return f"Horario:  dia: {self.dia} , hora: {self.hora}"
