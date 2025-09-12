#include "Curso.h"
#include <iostream>

Curso::Curso(int i, const std::string&n){
    id = i;
    nombre = n;

}

int Curso::getId() const{
    return id;

}

std::string Curso::getNombre() const{
    return nombre;

}

void Curso::setId(int i){
    id = i;

}

void Curso::setNombre(const std::string& n){
    nombre = n;

}

void Curso::mostrar() const{
    std::cout << "ID: " << id << ", Nombre: " << nombre << std::endl;
    
}


