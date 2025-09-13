#ifndef CURSO_H //se utiliza para verificar que no este definida, en caso de no estarlo la define
#define CURSO_H
#include <string>
#include <iostream>

class Curso {
    private:
        int id;
        std::string nombre;
        int creditos;
        std::string profesor;

    public:
        Curso(int i, const std::string& n, int cr,  const std::string& p);

        int getId() const;
        int getCodigo() const;

        std::string getNombre() const;
        int getCreditos() const;
        std::string getProfesor() const;
        
        void setId(int i);
        void setCodigo(int i);

        void setNombre(const std::string& n);
        void setCreditos(int cr);
        void setProfesor(const std::string& p);

        void mostrar() const;

        bool operator==(const Curso& other) const; //operador para combinaciones

};
#endif //se usa para cerrar la directiva si ya fue definida
