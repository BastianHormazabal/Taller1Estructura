#ifndef ALUMNO_H
#define ALUMNO_H

#include <string>

class Alumno {
    private:
        int id; 
        std::string nombre;
    public:
        Alumno(int i, const  std::string& n);

        int getId() const;
        std::string getNombre() const;

        void setId(int i);
        void setNombre(const std::string& n);

        void mostrar() const;
        

    
};
#endif