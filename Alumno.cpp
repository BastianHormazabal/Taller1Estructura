#include "Alumno.h"
#include <iostream>


Alumno::Alumno(int i, const std::string& n, const std::string& c, const std::string& g){
    id = i;
    nombre = n;
    carrera = c;
    gmail = g;
}

int Alumno::getId() const {
    return id;

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

void Alumno::setId(int i){
    id = i;

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
    std::cout << "ID: " << id << ", Nombre: " << nombre << ", Carrera: " << carrera << ", Gmail:" <<  std::endl;

}

bool Alumno::operator==(const Alumno& other) const {
    return id == other.id;
}