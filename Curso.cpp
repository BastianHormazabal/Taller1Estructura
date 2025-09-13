#include "Curso.h"
#include <iostream>

Curso::Curso(int i, const std::string&n, int cr, const std::string& p){
    id = i;
    nombre = n;
    creditos = cr;
    profesor = p;
}

int Curso::getId() const{
    return id;
}

int Curso::getCodigo() const{
    return id;
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

void Curso::setId(int i){
    id = i;
}

void Curso::setCodigo(int i){
    id = i;
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
    std::cout << "Codigo: " << id << ", Nombre: " << nombre << ", Creditos: " << creditos << ", Profesor: " << profesor << std::endl;
}
bool Curso::operator==(const Curso& other) const {
    return id == other.id;
}
