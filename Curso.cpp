#include "Curso.h"
#include <iostream>

Curso::Curso(int c, const std::string&n, int cr, const std::string& p){
    codigo = c;
    nombre = n;
    creditos = cr;
    profesor = p;

}

int Curso::getCodigo() const{
    return codigo;

}

std::string Curso::getNombre() const{
    return nombre;

}

int Curso::getCreditos() const{
    return creditos;

}

std::string Curso::getProfesor() const{
    return profesor;

}

void Curso::setCodigo(int c){
    codigo = c;

}

void Curso::setNombre(const std::string& n){
    nombre = n;

}

void Curso::setCreditos(int cr){
    creditos = cr;
}
void Curso::setProfesor(const std::string& p){
    profesor = p;
}

void Curso::mostrar() const{
    std::cout << "Codigo: " << codigo << ", Nombre: " << nombre << ", Creditos: " << creditos << ", Profesor: " << profesor << std::endl;
    
}
bool Curso::operator==(const Curso& other) const {
    return codigo == other.codigo;
}


