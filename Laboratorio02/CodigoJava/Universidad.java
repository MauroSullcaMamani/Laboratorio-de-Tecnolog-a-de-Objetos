import java.util.ArrayList;
import java.util.List;

public class Universidad {

    private String nombre;
    private List<Curso> cursos;

    public Universidad(String nombre) {
        this.nombre = nombre;
        this.cursos = new ArrayList<>();
    }

    public String getNombre() {
        return nombre;
    }

    public void setNombre(String nombre) {
        this.nombre = nombre;
    }

    public List<Curso> getCursos() {
        return cursos;
    }

    public void setCursos(List<Curso> cursos) {
        this.cursos = cursos;
    }

    public void agregarCurso(Curso curso) {
        cursos.add(curso);
    }

    @Override
    public String toString() {
        return "Universidad: " + nombre + " , cursos: " + cursos;
    }
}