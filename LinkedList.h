#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <iostream>

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

        T* buscarPorId(int id) const{
            Nodo<T>* actual = cabeza;
            while (actual){
                try{
                    if (actual->dato->getId() == id){
                        return actual->dato;
                    }
                }
                catch(...){ //si falla intentamos con codigo
                    try{
                        if (actual->dato->getCodigo() == id){
                            return actual->dato;
                        }
                    }
                    catch(...){}
                }
                actual = actual->siguiente;
            }
            return nullptr;
        }

        void buscarPorNombre(const std::string& nombre, T** resultados, int& cantidad, int maxResultados) const{
            cantidad = 0;
            Nodo<T>* actual = cabeza;
            while (actual && cantidad < maxResultados){
                if (actual->dato->getNombre() == nombre){
                    resultados[cantidad] = actual->dato;
                    cantidad++;
                }
                actual = actual->siguiente;
            }
        }

        bool eliminarPorId(int id){
            if (!cabeza) return false;

            bool esElPrimero = false;
            try {
                if (cabeza->dato->getId() == id) esElPrimero = true;
            } catch (...){
                try {
                    if (cabeza->dato->getCodigo() == id) esElPrimero = true;

                } catch (...){}

            }

            if (esElPrimero){
                Nodo<T>* temp = cabeza;
                cabeza = cabeza->siguiente;
                delete temp->dato;
                delete temp;
                return true;

            }

            Nodo<T>* actual = cabeza;
            while(actual->siguiente){
                bool encontrado = false;
                try{
                    if(actual->siguiente->dato->getId() == id) encontrado = true;
                } catch (...){
                    try{
                        if(actual->siguiente->dato->getCodigo() == id) encontrado = true;
                    } catch (...){}
                 }
                 if (encontrado){
                    Nodo<T>* temp = actual->siguiente;
                    actual->siguiente = temp->siguiente;
                    delete temp->dato;
                    delete temp;
                    return true;
                 }
                 actual = actual->siguiente;

            }
            return false;
        }

        template <typename predicado>
        void eliminarSi(predicado pred) {
            //elimina del inicio
            while (cabeza && pred(*cabeza->dato)){
                Nodo<T>* temp = cabeza;
                cabeza = cabeza->siguiente;
                delete temp->dato;
                delete temp;
            }
            //elimina en el resto de la lista
            Nodo<T>* actual = cabeza;
            while (actual && actual->siguiente){
                if (pred(*actual->siguiente->dato)){
                    Nodo<T>* temp = actual->siguiente;
                    actual->siguiente = temp->siguiente;
                    delete temp->dato;
                    delete temp;
                } else {
                    actual = actual->siguiente;
                }
            }

        }

        void obtenerTodos(T** elementos, int& cantidad, int maxElementos) const{
            cantidad = 0;
            Nodo<T>* actual = cabeza;
            while (actual && cantidad < maxElementos){
                elementos[cantidad] = actual->dato;
                cantidad++;
                actual = actual->siguiente;
            }
        }

        bool estaVacia() const{
            return cabeza == nullptr;
        }

        int contar() const{
            int contador = 0;
            Nodo<T>* actual = cabeza;
            while (actual){
                contador++;
                actual = actual->siguiente;
            }
            return contador;
        }



};
#endif