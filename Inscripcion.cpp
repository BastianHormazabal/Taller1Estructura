#include "Inscripcion.h"

Inscripcion::Inscripcion(int idA, int codC){
    idAlumno = idA;
    codigoCurso = codC;
    //inicializamos la lista de notas
}

int Inscripcion::getIdAlumno() const{
    return idAlumno;

}
int Inscripcion::getCodigoCurso() const{
    return codigoCurso;

}

void Inscripcion::agregarNota(double nota){
    notas.agregar(nota);

}

double Inscripcion::calcularPromedio() const{
    return notas.calcularPromedio();
}

void Inscripcion::mostrarNotas() const{
    notas.mostrar();
}
bool Inscripcion::tieneNotas() const{
    return !notas.estaVacia();

}
bool Inscripcion::operator==(const Inscripcion& other) const {
    return this->idAlumno == other.idAlumno && this->codigoCurso == other.codigoCurso;
    
}
