#ifndef ALUMNO_H
#define ALUMNO_H

#include <string>

class Alumno {
    private:
        int id; 
        std::string nombre;
        std::string carrera;
        std::string gmail;
    public:
        Alumno(int i, const  std::string& n, const  std::string& c,const  std::string& g);

        int getId() const;
        std::string getNombre() const;
        std::string getCarrera() const;
        std::string getGmail() const;

        void setId(int i);
        void setNombre(const std::string& n);
        void setCarrera(const std::string& c);
        void setGmail(const std::string& g);

        void mostrar() const;

        bool operator==(const Alumno& other) const;
};
#endif