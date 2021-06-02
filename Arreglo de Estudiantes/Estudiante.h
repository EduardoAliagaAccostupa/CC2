#ifndef __ESTUDIANTE_H__
#define __ESTUDIANTE_H__

#include <string>
#include <iostream>

using namespace std;

class Estudiante {

    string nombre;
    int cui;
    int edad;
    char sexo;
    string semestre;
public:
    Estudiante();
    Estudiante(string, int, int, char, string);
    void setCui(int);
    int getCui();
    void setEdad(int);
    int getEdad();
    void setNombre(string);
    string getNombre();
    char getSexo();
    void setSexo(char);
    void setSemestre(string);
    string getSemestre();
    friend ostream& operator << (ostream &o, const Estudiante &p);
};


Estudiante::Estudiante(){
    this->nombre = "";
    this->cui = 0;
    this->edad = 0;
    this->sexo = NULL;
    this->semestre = "";
}

Estudiante::Estudiante(string nombre, int cui, int edad, char sexo, string semestre){
    this->nombre = nombre;
    this->cui = cui;
    this->edad = edad;
    this->sexo = sexo;
    this->semestre = semestre;
}
//edad
int Estudiante::getEdad(){
    return edad;
}
void Estudiante::setEdad(int edad){
    this->edad=edad;
}
//cui
void Estudiante::setCui(int cui){
    this->cui=cui;
}
int Estudiante::getCui(){
    return cui;
}
//nombre
void Estudiante::setNombre(string nombre){
    this->nombre = nombre;
}
string Estudiante::getNombre(){
    return nombre;
}
//sexo
void Estudiante::setSexo(char sexo){
    this-> sexo= sexo;
}
char Estudiante::getSexo(){
    return sexo;
}
//Semestre
void Estudiante::setSemestre(string semestre){
    this->semestre=semestre;
}
string Estudiante::getSemestre(){
    return semestre;
}

ostream& operator << (ostream &o, const Estudiante &p){
    o << "(" << p.nombre << ", " << p.cui << ", " << p.edad << ", " << p.sexo << ", " << p.semestre << ")";
    return o;
}
#endif
