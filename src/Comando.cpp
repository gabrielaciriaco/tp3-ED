#include "../include/Comando.h"

Comando::Comando (){

}
Comando::Comando(char tipo, string texto){
    this->tipo = tipo;
    this->texto = texto;
}

char Comando::getTipo(){
  return this->tipo;
}

void Comando::setTipo(char tipo){
  this->tipo = tipo;
}

string Comando::getTexto(){
  return this->texto;
}

void Comando::setTexto(string texto){
  this->texto = texto;
}