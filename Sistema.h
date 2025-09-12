#ifndef SISTEMA_H
#define SISTEMA_H
#include "Alumno.h"
#include "Curso.h"
#include "LinkedList.h"
class Sistema{
    private: 
        LinkedList<Alumno> listaAlumnos;
        LinkedList<Curso> listaCursos;
    
    public: 
        void agregarAlumno(int id, const std::string& nombre);
        void agregarCurso(int id, const std::string& nombre);
        void mostrarAlumnos() const;
        void mostrarCursos() const;

};
#endif