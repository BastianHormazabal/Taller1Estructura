#ifndef INSCRIPCION_H
#define INSCRIPCION_H
#include "ListaNotas.h"

class Inscripcion{
    private:
        int idAlumno;
        int codigoCurso;
        ListaNotas notas;   
    public:
        Inscripcion(int idA, int codC);

        int getIdAlumno() const;
        int getCodigoCurso() const;

        void agregarNota(double nota);
        double calcularPromedio() const;
        void mostrarNotas() const;
        bool tieneNotas() const;

        bool operator==(const Inscripcion& other) const;

};
#endif 