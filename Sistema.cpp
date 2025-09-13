#include "Sistema.h"
#include <iostream>
#include <string>
#include <iomanip>

void Sistema::crearAlumno(){
    int id;
    std::string nombre, carrera, gmail;
    std::cout << "\n--- Crear Alumno ---\n";
    std::cout << "ID del alumno: ";
    std::cin >> id;

    if(buscarAlumnoPorId(id)){
        std::cout << "Error: ya existe un alumno con ese id " << id << std::endl;
        return;

    }

    std::cin.ignore();
    std::cout << "nombre: ";
    std::getline(std::cin, nombre);
    std::cout << "Carrera: ";
    std::getline(std::cin, carrera);
    std::cout << "Gmail: ";
    std::getline(std::cin, gmail);

    Alumno* nuevo = new Alumno(id, nombre, carrera, gmail);
    listaAlumnos.agregar(nuevo);
    std::cout << "Alumno creado\n";

}

void Sistema::buscarAlumno(){
    int opcion;
    std::cout << "\n--- Buscar Alumno ---\n";
    std::cout << "1. Buscar por ID\n";
    std::cout << "2. Buscar por Nombre\n";
    std::cout << "Seleccione una opcion: ";
    std::cin >> opcion;

    if (opcion == 1){
        int id;
        std::cout << "Ingrese el ID del alumno: ";
        std::cin >> id;

        Alumno* alumno = buscarAlumnoPorId(id);
        if (alumno){
            std::cout << "Alumno encontrado:\n";
            alumno->mostrar();
        } else {
            std::cout << "No se encontro un alumno con ID " << id << std::endl;
        }
    } else if (opcion == 2){
        std::string nombre;
        std::cin.ignore();
        std::cout << "Ingrese nombre del alumno:  ";
        std::getline(std::cin, nombre);

        Alumno* resultados[MAX_RESULTADOS];
        int cantidad;
        listaAlumnos.buscarPorNombre(nombre, resultados, cantidad, MAX_RESULTADOS);

        if (cantidad == 0){
            std::cout << "no se encontraron alumnos el nombre " << nombre << std::endl;

        } else {
            std::cout << "Alumnos encontrados: \n";
            for(int i = 0; i < cantidad; i++){
                resultados[i]->mostrar();

            } 
        }
    }
}

void Sistema::eliminarAlumno(){
    int id;
    std::cout << "\n--- Eliminar Alumno ---\n";
    std::cout << "Ingrese el ID del alumno a eliminar: ";
    std::cin >> id;


    if(listaAlumnos.eliminarPorId(id)){
        eliminarInscripcionesAlumno(id);
        std::cout << "Alumno eliminado\n";

    } else {
        std::cout << "No se encontro un alumno con ID " << id << std::endl;

    }
}

void Sistema::mostrarAlumnos() const {
    std::cout << "\n--- Lista de Alumnos ---\n";
    if (listaAlumnos.estaVacia()){
        std::cout << "No hay alumnos registrados.\n";
    } else {
        listaAlumnos.mostrar();

    }
}

void Sistema::crearCursos(){
    int codigo, creditos;
    std::string nombre, profesor;

    std::cout << "\n--- Crear Curso ---\n";
    std::cout << "Codigo del curso: ";
    std::cin >> codigo;

    if(buscarCursoPorCodigo(codigo)){
        std::cout << "error: ya existe un curso con ese codigo " << codigo << std::endl;
        return;
    }

    std::cin.ignore();
    std::cout << "nombre del curso: ";
    std::getline(std::cin, nombre);
    std:: cout <<"Creditos: ";
    std::cin >> creditos;
    std::cin.ignore();
    std::cout << "profesor: ";
    std::getline(std::cin, profesor);

    Curso* nuevo = new Curso(codigo, nombre, creditos, profesor);
    listaCursos.agregar(nuevo);
    std::cout << "Curso creado\n";
    
}

void Sistema::buscarCurso(){
    int opcion;
    std::cout << "\n--- Buscar Curso ---\n";
    std::cout << "1. Buscar por Codigo\n";
    std::cout << "2. Buscar por Nombre\n";
    std::cout << "Seleccione una opcion: ";
    std::cin >> opcion;

    if (opcion == 1){
        int codigo;
        std::cout << "Ingrese el codigo del curso: ";
        std::cin >> codigo;

        Curso* curso = buscarCursoPorCodigo(codigo);
        if(curso){
            std::cout << "Curso encontrado: ";
            curso->mostrar();

        } else{
            std::cout << "No se encontro un curso con codigo " << codigo << std::endl;

        }
    } else if (opcion == 2){
        std::string nombre;
        std::cin.ignore();
        std::cout << "ingrese el nombre del curso: ";
        std::getline(std::cin, nombre);

        Curso* resultados[MAX_RESULTADOS];
        int cantidad;
        listaCursos.buscarPorNombre(nombre, resultados, cantidad, MAX_RESULTADOS);

        if(cantidad == 0){
            std::cout << "No se encontraron cursos con el nombre " << nombre << std::endl;

        } else {
            std::cout << "Cursos encontrados: ";
            for (int i = 0; i< cantidad; i++){
                resultados[i]->mostrar();

            }
        }

    }

}

void Sistema::eliminarCurso(){
    int codigo;
    std::cout << "\n--- Eliminar Curso ---\n";
    std::cout << "Ingrese el codigo del curso a eliminar: ";
    std::cin >> codigo;

    if (listaCursos.eliminarPorId(codigo)){
        eliminarInscripcionesCurso(codigo);
        std::cout << "Curso eliminado\n";

    } else {
        std::cout << "No se encontro un curso con codigo " << codigo << std::endl;

}

}

void Sistema::mostrarCursos() const {
    std::cout << "\n--- Lista de Cursos ---\n";
    if (listaCursos.estaVacia()){
        std::cout << "No hay cursos registrados.\n";

    } else {
        listaCursos.mostrar();

    }
}

void Sistema::inscribirAlumno(){
    int idAlumno, codigoCurso;

    std::cout << "\n--- Inscribir Alumno en Curso ---\n";
    std::cout << "ID del alumno: ";
    std::cin >> idAlumno;
    std::cout << "Codigo del curso: ";
    std::cin >> codigoCurso;

    if (!buscarAlumnoPorId(idAlumno)){
        std::cout << "Error: no existe un alumno con ID " << idAlumno << std::endl;
        return;

    }

    if(!buscarCursoPorCodigo(codigoCurso)){
        std::cout << "Error: no existe un curso con codigo " << codigoCurso << std::endl;
        return;

    }

    if (buscarInscripcion(idAlumno, codigoCurso)){
        std::cout << "Error: el alumno ya esta inscrito en ese curso" << std::endl;
        return;

    }

    Inscripcion* nueva = new Inscripcion(idAlumno, codigoCurso);
    listaInscripciones.agregar(nueva);
    std::cout << " Alumno inscrito existosamente\n";


}

void Sistema::desinscribirAlumno() {
    int idAlumno, codigoCurso;
    
    std::cout << "\n--- Desinscribir Alumno ---\n";
    std::cout << "ID del alumno: ";
    std::cin >> idAlumno;
    std::cout << "Código del curso: ";
    std::cin >> codigoCurso;
    
    if (!buscarInscripcion(idAlumno, codigoCurso)) {
        std::cout << "Error: No se encontró la inscripción especificada" << std::endl;
        return;
    }
    
    bool eliminado = false;
    listaInscripciones.eliminarSi([idAlumno, codigoCurso, &eliminado](const Inscripcion& insc) {
        bool matches = insc.getIdAlumno() == idAlumno && insc.getCodigoCurso() == codigoCurso;
        if (matches) eliminado = true;
        return matches;
    });
    
    if (eliminado) {
        std::cout << "Alumno desinscrito exitosamente!\n";
    } else {
        std::cout << "Error: No se pudo eliminar la inscripción" << std::endl;
    }
}

void Sistema::registrarNota() {
    int idAlumno, codigoCurso;
    double nota;
    
    std::cout << "\n--- Registrar Nota ---\n";
    std::cout << "ID del alumno: ";
    std::cin >> idAlumno;
    std::cout << "Código del curso: ";
    std::cin >> codigoCurso;
    
    Inscripcion* inscripcion = buscarInscripcion(idAlumno, codigoCurso);
    if (!inscripcion) {
        std::cout << "Error: El alumno no está inscrito en este curso" << std::endl;
        return;
    }
    
    std::cout << "Nota (1.0 - 7.0): ";
    std::cin >> nota;
    
    inscripcion->agregarNota(nota);
    std::cout << "Nota registrada exitosamente!\n";
}

void Sistema::alumnosPorCarrera() {
    std::string carrera;
    std::cout << "\n--- Alumnos por Carrera ---\n";
    std::cin.ignore();
    std::cout << "Ingrese carrera: ";
    std::getline(std::cin, carrera);
    

    Alumno* alumnos[MAX_ELEMENTOS];
    int totalAlumnos;
    listaAlumnos.obtenerTodos(alumnos, totalAlumnos, MAX_ELEMENTOS);
    

    Alumno* resultado[MAX_RESULTADOS];
    int cantidadResultados = 0;
    
    for (int i = 0; i < totalAlumnos && cantidadResultados < MAX_RESULTADOS; i++) {
        if (alumnos[i]->getCarrera() == carrera) {
            resultado[cantidadResultados] = alumnos[i];
            cantidadResultados++;
        }
    }
    
    if (cantidadResultados == 0) {
        std::cout << "No hay alumnos en la carrera '" << carrera << "'\n";
    } else {
        std::cout << "\nAlumnos en " << carrera << ":\n";
        for (int i = 0; i < cantidadResultados; i++) {
            resultado[i]->mostrar();
        }
    }
}

void Sistema::cursosDeAlumno() {
    int idAlumno;
    std::cout << "\n--- Cursos de Alumno ---\n";
    std::cout << "ID del alumno: ";
    std::cin >> idAlumno;
    
    Alumno* alumno = buscarAlumnoPorId(idAlumno);
    if (!alumno) {
        std::cout << "Error: No existe alumno con ID " << idAlumno << std::endl;
        return;
    }
    
  
    Inscripcion* inscripciones[MAX_ELEMENTOS];
    int totalInscripciones;
    listaInscripciones.obtenerTodos(inscripciones, totalInscripciones, MAX_ELEMENTOS);
    
    std::cout << "\nCursos del alumno " << alumno->getNombre() << ":\n";
    
    bool tieneCursos = false;
    for (int i = 0; i < totalInscripciones; i++) {
        if (inscripciones[i]->getIdAlumno() == idAlumno) {
            Curso* curso = buscarCursoPorCodigo(inscripciones[i]->getCodigoCurso());
            if (curso) {
                curso->mostrar();
                inscripciones[i]->mostrarNotas();
                std::cout << "---\n";
                tieneCursos = true;
            }
        }
    }
    
    if (!tieneCursos) {
        std::cout << "El alumno no está inscrito en ningún curso.\n";
    }
}

void Sistema::promedioAlumnoEnCurso() {
    int idAlumno, codigoCurso;
    std::cout << "\n--- Promedio Alumno en Curso ---\n";
    std::cout << "ID del alumno: ";
    std::cin >> idAlumno;
    std::cout << "Código del curso: ";
    std::cin >> codigoCurso;
    
    Inscripcion* inscripcion = buscarInscripcion(idAlumno, codigoCurso);
    if (!inscripcion) {
        std::cout << "Error: El alumno no está inscrito en este curso" << std::endl;
        return;
    }
    
    double promedio = inscripcion->calcularPromedio();
    if (promedio > 0) {
        std::cout << "Promedio: " << std::fixed << std::setprecision(1) << promedio << std::endl;
    } else {
        std::cout << "El alumno no tiene notas registradas en este curso." << std::endl;
    }
}

void Sistema::promedioGeneralAlumno() {
    int idAlumno;
    std::cout << "\n--- Promedio General de Alumno ---\n";
    std::cout << "ID del alumno: ";
    std::cin >> idAlumno;
    
    Alumno* alumno = buscarAlumnoPorId(idAlumno);
    if (!alumno) {
        std::cout << "Error: No existe alumno con ID " << idAlumno << std::endl;
        return;
    }
    
   
    Inscripcion* inscripciones[MAX_ELEMENTOS];
    int totalInscripciones;
    listaInscripciones.obtenerTodos(inscripciones, totalInscripciones, MAX_ELEMENTOS);
    
    double sumaPromedios = 0.0;
    int cursosConNotas = 0;
    
    for (int i = 0; i < totalInscripciones; i++) {
        if (inscripciones[i]->getIdAlumno() == idAlumno) {
            double promedioCurso = inscripciones[i]->calcularPromedio();
            if (promedioCurso > 0) {
                sumaPromedios += promedioCurso;
                cursosConNotas++;
            }
        }
    }
    
    if (cursosConNotas > 0) {
        double promedioGeneral = sumaPromedios / cursosConNotas;
        std::cout << "Promedio general de " << alumno->getNombre() 
                  << ": " << std::fixed << std::setprecision(1) << promedioGeneral << std::endl;
    } else {
        std::cout << "El alumno no tiene notas registradas." << std::endl;
    }
}

void Sistema::mostrarMenu() {
    std::cout << "\n=============== SISTEMA DE GESTIÓN ACADÉMICA ===============\n";
    std::cout << "1.  Crear Alumno\n";
    std::cout << "2.  Buscar Alumno\n";
    std::cout << "3.  Eliminar Alumno\n";
    std::cout << "4.  Mostrar Todos los Alumnos\n";
    std::cout << "5.  Crear Curso\n";
    std::cout << "6.  Buscar Curso\n";
    std::cout << "7.  Eliminar Curso\n";
    std::cout << "8.  Mostrar Todos los Cursos\n";
    std::cout << "9.  Inscribir Alumno en Curso\n";
    std::cout << "10. Desinscribir Alumno de Curso\n";
    std::cout << "11. Registrar Nota\n";
    std::cout << "12. Alumnos por Carrera\n";
    std::cout << "13. Cursos de un Alumno\n";
    std::cout << "14. Promedio de Alumno en Curso\n";
    std::cout << "15. Promedio General de Alumno\n";
    std::cout << "0.  Salir\n";
    std::cout << "============================================================\n";
    std::cout << "Seleccione una opción: ";
}



Alumno* Sistema::buscarAlumnoPorId(int id) const {
    return listaAlumnos.buscarPorId(id);
}

Curso* Sistema::buscarCursoPorCodigo(int codigo) const{
    return listaCursos.buscarPorId(codigo);
}

Inscripcion* Sistema::buscarInscripcion(int idAlumno, int codigoCurso) const {
    
    Inscripcion* inscripciones[MAX_ELEMENTOS];
    int totalInscripciones;
    listaInscripciones.obtenerTodos(inscripciones, totalInscripciones, MAX_ELEMENTOS);
    
    for (int i = 0; i < totalInscripciones; i++) {
        if (inscripciones[i]->getIdAlumno() == idAlumno && 
            inscripciones[i]->getCodigoCurso() == codigoCurso) {
            return inscripciones[i];
        }
    }
    return nullptr;
}

void Sistema::eliminarInscripcionesAlumno(int idAlumno) {
    listaInscripciones.eliminarSi([idAlumno](const Inscripcion& insc) {
        return insc.getIdAlumno() == idAlumno;
    });
}

void Sistema::eliminarInscripcionesCurso(int codigoCurso) {
    listaInscripciones.eliminarSi([codigoCurso](const Inscripcion& insc) {
        return insc.getCodigoCurso() == codigoCurso;
    });
}

void Sistema::iniciar() {
    int opcion;
    
    do {
        mostrarMenu();
        std::cin >> opcion;
        
        switch (opcion) {
            case 1: crearAlumno(); break;
            case 2: buscarAlumno(); break;
            case 3: eliminarAlumno(); break;
            case 4: mostrarAlumnos(); break;
            case 5: crearCursos(); break;
            case 6: buscarCurso(); break;
            case 7: eliminarCurso(); break;
            case 8: mostrarCursos(); break;
            case 9: inscribirAlumno(); break;
            case 10: desinscribirAlumno(); break;
            case 11: registrarNota(); break;
            case 12: alumnosPorCarrera(); break;
            case 13: cursosDeAlumno(); break;
            case 14: promedioAlumnoEnCurso(); break;
            case 15: promedioGeneralAlumno(); break;
            case 0: std::cout << "Chau!\n"; break;
            default: std::cout << "Opcion invalida. Intente nuevamente.\n";
        }
        
        if (opcion != 0) {
            std::cout << "Presione Enter para continuar...";
            std::cin.ignore();
            std::cin.get();
        }
        
    } while (opcion != 0);
}
