#include "Alumno.h"
#include <iostream>

Alumno::Alumno(int i, const std::string& n, const std::string& c, const std::string& g){
    codigo = i;
    nombre = n;
    carrera = c;
    gmail = g;
}

int Alumno::getCodigo() const {
    return codigo;
}

int Alumno::getId() const {
    return codigo;
}

std::string Alumno::getNombre() const {
    return nombre;
}

std::string Alumno::getCarrera() const {
    return carrera;
}

std::string Alumno::getGmail() const {
    return gmail;
}

void Alumno::setCodigo(int i){
    codigo = i;
}

void Alumno::setId(int i){
    codigo = i;
}

void Alumno::setNombre(const std::string& n){
    nombre = n;
}

void Alumno::setCarrera(const std::string& c){
    carrera = c;
}

void Alumno::setGmail(const std::string& g){
    gmail = g;
}

void Alumno::mostrar() const{
    std::cout << "ID: " << codigo << ", Nombre: " << nombre << ", Carrera: " << carrera << ", Gmail:" <<  gmail << std::endl;
}

bool Alumno::operator==(const Alumno& other) const {
    return codigo == other.codigo;
}
