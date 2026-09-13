from profesor import Profesor
from estudiante import Estudiante
from curso import Curso
from universidad import Universidad
from reporte import Reporte


if __name__ == "__main__":
    profesor1 = Profesor("Marco Aedo", 45)
    profesor2 = Profesor("Roni Apaza", 38)

    estudiante1 = Estudiante("Mauro Sullca", 20)
    estudiante2 = Estudiante("Pepe Cruz", 21)
    estudiante3 = Estudiante("Kenji Gonzalez", 19)

    curso1 = Curso("Programacion Orientada a Objetos", "Lunes", "08:00 - 10:00")
    curso2 = Curso("Sistemas Operativos", "Miercoles", "10:00 - 12:00")

    universidad = Universidad("Universidad Nacional de San Agustin")

    universidad.agregar_curso(curso1)
    universidad.agregar_curso(curso2)

    print("PROFESORES")
    print(profesor1)
    print(profesor2)

    print("\nESTUDIANTES")
    print(estudiante1)
    print(estudiante2)
    print(estudiante3)

    print("\nCURSOS")
    print(curso1)
    print(curso2)

    print("\nUNIVERSIDAD")
    print(universidad)

    print()
    reporte = Reporte()
    reporte.generar_reporte(estudiante1)
