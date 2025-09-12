#include "Sistema.h"
#include <iostream>

int main(){
    Sistema sistema;

    sistema.agregarAlumno(1, "cristobal");
    sistema.agregarAlumno(2, "Bastian");

    sistema.agregarCurso(101, "Calculo 3");
    sistema.agregarCurso(102, "Estructura de datos");

    sistema.mostrarAlumnos();
    sistema.mostrarCursos();
    return 0;

}