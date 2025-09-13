#include "ListaNotas.h"
#include <iostream>
#include <iomanip>

ListaNotas::ListaNotas() {
    cabeza = nullptr;
    tamaño = 0;
}

ListaNotas::~ListaNotas(){
    while (cabeza) {
        NodoNota* temp = cabeza;
        cabeza = cabeza->siguiente;
        delete temp;

    }
}

void ListaNotas::agregar(double nota){
    if (nota >= 1.0 && nota <= 7.0){
        NodoNota* nuevo = new NodoNota(nota);
        nuevo->siguiente = cabeza;
        cabeza = nuevo;
        tamaño++;

    } else {
        std::cout << "Nota invalida. Debe estar entre 1.0 y 7.0" << std::endl;
    }
}
double ListaNotas::calcularPromedio() const{
    if (tamaño == 0) return 0.0;

    double suma = 0.0;
    NodoNota* actual = cabeza;
    while(actual)
    {
    suma += actual->nota;
    actual = actual->siguiente;

    }
    return suma / tamaño;
}

void ListaNotas::mostrar() const{
    std::cout << "Notas: ";
    NodoNota* actual = cabeza;
    while (actual){
        std::cout << std::fixed << std::setprecision(1) << actual->nota << " ";
        actual = actual->siguiente;
    }
    if (tamaño > 0){
        std::cout << "Promedio: " << std::fixed << std::setprecision(2) << calcularPromedio();
    }
    std::cout << std::endl;

}

bool ListaNotas::estaVacia() const{
    return tamaño == 0;
}
int ListaNotas::getTamaño() const{
    return tamaño;
}