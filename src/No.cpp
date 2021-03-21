#include "../include/No.h"

No::No(){
  this->esquerdo = NULL;
  this->direito = NULL;
}

No::No(char simbolo, No *esquerdo, No *direito){
  this->simbolo = simbolo;
  this->esquerdo = esquerdo;
  this->direito = direito;
}
No::No(char simbolo){
  this->simbolo = simbolo;
}
char No::getSimbolo(){
  return this->simbolo;
}
void No::setSimbolo(char simbolo){
  this->simbolo =  simbolo;
}
No* No::getEsquerdo(){
  return this->esquerdo;
}
void No::setEsquerdo(No *esquerdo){
  this->esquerdo = esquerdo;
}

No* No::getDireito(){
  return this->direito;
}

void No::setDireito(No *direito){
  this->direito = direito;
}

string No::getCodigoCaminho(char letra) {
  string codigoCaminho = "";
  No* aux;
  if (letra < getSimbolo()) {
    codigoCaminho += (((rand() % 5) * 2) + 1) + '0';
     aux = getEsquerdo();
     return codigoCaminho + aux->getCodigoCaminho(letra);
  } else if(letra > getSimbolo()) {
    codigoCaminho += (((rand() % 5) * 2)) + '0';
    aux = getDireito();
    return codigoCaminho + aux->getCodigoCaminho(letra);
  }else{
    return codigoCaminho;
  }
}