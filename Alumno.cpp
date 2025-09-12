#include "Alumno.h"
#include <iostream>


Alumno::Alumno(int i, const std::string& n){
    id = i;
    nombre = n;
}

int Alumno::getId() const {
    return id;

}
std::string Alumno::getNombre() const {
    return nombre;
}

void Alumno::setId(int i){
    id = i;

}

void Alumno::setNombre(const std::string& n){
    nombre = n;

}

void Alumno::mostrar() const{
    std::cout << "ID: " << id << ", Nombre: " << nombre << std::endl;

}