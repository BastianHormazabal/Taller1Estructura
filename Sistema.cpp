#include "Sistema.h"
#include <iostream>

void Sistema::agregarAlumno(int id, const std::string& nombre){
    Alumno* a = new Alumno(id, nombre);
    listaAlumnos.agregar(a);

}
void Sistema::agregarCurso(int id, const std::string& nombre){
    Curso* c = new Curso(id, nombre);
    listaCursos.agregar(c);

}
void Sistema::mostrarAlumnos() const{
    std::cout << "Lista de alumnos: " << std::endl;
    listaAlumnos.mostrar();

}
void Sistema::mostrarCursos() const{
    std::cout << "Lista de cursos: " << std::endl;
    listaCursos.mostrar();
    
}