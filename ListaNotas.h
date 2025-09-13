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
        int tamano;
    public:
        ListaNotas();
        ~ListaNotas();

        void agregar(double n);
        double calcularPromedio() const;
        void mostrar() const;
        bool estaVacia() const;
        int getTamano() const;
};

#endif
