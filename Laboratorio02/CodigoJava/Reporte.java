public class Reporte {

    public void generarReporte(Estudiante estudiante) {
        System.out.println("REPORTE DEL ESTUDIANTE");
        System.out.println("Nombre: " + estudiante.getNombre());
        System.out.println("Edad: " + estudiante.getEdad());
        System.out.println();
    }

    @Override
    public String toString() {
        return "Reporte{}";
    }
}