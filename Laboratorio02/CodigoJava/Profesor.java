public class Profesor extends Persona {

    public Profesor(String nombre, int edad) {
        super(nombre, edad);
    }

    @Override
    public String toString() {
        return "Profesor: " + getNombre() + " ; edad: " + getEdad();
    }
}