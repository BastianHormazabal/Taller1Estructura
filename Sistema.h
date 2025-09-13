#ifndef SISTEMA_H
#define SISTEMA_H
#include "Alumno.h"
#include "Curso.h"
#include "Inscripcion.h"
#include "LinkedList.h"

const int MAX_RESULTADOS = 100;
const int MAX_ELEMENTOS = 1000;

class Sistema{
    private: 
        LinkedList<Alumno> listaAlumnos;
        LinkedList<Curso> listaCursos;
        LinkedList<Inscripcion> listaInscripciones;
    
    public: 
        //alumno
        void crearAlumno();
        void buscarAlumno();
        void eliminarAlumno();
        void mostrarAlumnos() const;

        //cursos
        void crearCursos();
        void buscarCurso();
        void eliminarCurso();
        void mostrarCursos() const;

        //inscripciones
        void inscribirAlumno();
        void desinscribirAlumno();

        //notas
        void registrarNota();

        //consultas y reportes
        void alumnosPorCarrera();
        void cursosDeAlumno();
        void promedioAlumnoEnCurso();
        void promedioGeneralAlumno();

        //menú
        void mostrarMenu();
    
        void iniciar();

    private:
        Alumno* buscarAlumnoPorId(int id) const;
        Curso* buscarCursoPorCodigo(int codigo) const;
        Inscripcion* buscarInscripcion(int idAlumno, int codigoCurso) const;
        void eliminarInscripcionesAlumno(int idAlumno);
        void eliminarInscripcionesCurso(int codigoCurso);

};
#endif