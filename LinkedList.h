#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <iostream>

using namespace std;

template <typename T>

class Nodo {
    public:
        T* dato; //puntero a un objeto
        Nodo* siguiente; //puntero al siguiente
        Nodo(T* d) : dato(d), siguiente(nullptr){}

};  

template <typename T>
class LinkedList {
    private:
        Nodo<T>* cabeza; //es un puntero al primer nodo

    public: 
        LinkedList() : cabeza(nullptr) {}
        ~LinkedList(){
            while (cabeza){
            Nodo<T>* temp = cabeza;
            cabeza = cabeza->siguiente;
            delete temp->dato;
            delete temp;
            }
        }

        void agregar(T* dato){
            Nodo<T>* nuevo = new Nodo<T>(dato);
            nuevo->siguiente = cabeza;
            cabeza = nuevo;
        }


        void mostrar() const{
            Nodo<T>* actual = cabeza;
            while (actual){
                actual->dato->mostrar(); //aqui llamo al mostra de alumno o curso
                actual = actual->siguiente;
            }
        }

};
#endif