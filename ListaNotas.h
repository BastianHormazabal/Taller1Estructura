#ifndef LISTANOTAS_H
#define LISTANOTAS_H

class NodoNota {
    public:
        double nota;
        NodoNota* siguiente;

        NodoNota(double n) : nota(n), siguiente(nullptr) {}
};
class ListaNotas {
    private:
        NodoNota* cabeza;
        int tamaño;
    public:
        ListaNotas();
        ~ListaNotas();

        void agregar(double n);
        double calcularPromedio() const;
        void mostrar() const;
        bool estaVacia() const;
        int getTamaño() const;

};
#endif
