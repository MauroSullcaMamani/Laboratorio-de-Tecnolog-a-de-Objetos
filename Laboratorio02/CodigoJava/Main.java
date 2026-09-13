public class Main {

    public static void main(String[] args) {

        Profesor profesor1 = new Profesor("Marco Aedo", 45);
        Profesor profesor2 = new Profesor("Roni Apaza", 38);

        Estudiante estudiante1 = new Estudiante("Mauro Sullca", 20);
        Estudiante estudiante2 = new Estudiante("Pepe Cruz", 21);
        Estudiante estudiante3 = new Estudiante("Kenji Gonzalez", 19);

        Curso curso1 = new Curso("Programacion Orientada a Objetos","Lunes","08:00 - 10:00");
        Curso curso2 = new Curso("Sistemas Operativos","Miercoles","10:00 - 12:00");

        Universidad universidad = new Universidad("Universidad Nacional de San Agustin");

        universidad.agregarCurso(curso1);
        universidad.agregarCurso(curso2);

        System.out.println("PROFESORES");
        System.out.println(profesor1);
        System.out.println(profesor2);

        System.out.println("\nESTUDIANTES");
        System.out.println(estudiante1);
        System.out.println(estudiante2);
        System.out.println(estudiante3);

        System.out.println("\nCURSOS");
        System.out.println(curso1);
        System.out.println(curso2);

        System.out.println("\nUNIVERSIDAD");
        System.out.println(universidad);

        System.out.println();
        Reporte reporte = new Reporte();
        reporte.generarReporte(estudiante1);
    }
}