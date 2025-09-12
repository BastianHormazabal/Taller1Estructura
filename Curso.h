#ifndef CURSO_H //se utiliza para verificar que no este definida, en caso de no estarlo la define
#define CURSO_H
#include <string>

class Curso {
    private:
        int id;
        std::string nombre;
    public:
        Curso(int i, const std::string& n);

        int getId() const;
        std::string getNombre() const;
        void setId(int i);
        void setNombre(const std::string& n);
        
        void mostrar() const;

};
#endif //se usa para cerrar la directiva si ya fue definida
