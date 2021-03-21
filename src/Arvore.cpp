#include "../include/Arvore.h"

Arvore::Arvore() { this->raiz = NULL; }
Arvore::Arvore(No* raiz) { this->raiz = raiz; }

void Arvore::insere(char valor) { insereRecursivo(raiz, valor); }

void Arvore::insereRecursivo(No*& referencia, char valor) {
  if (referencia == NULL) {
    referencia = new No();
    referencia->setSimbolo(valor);
  } else {
    if (valor < referencia->getSimbolo()) {
      if (referencia->esquerdo == NULL) {
        referencia->esquerdo = new No();
        referencia->esquerdo->setSimbolo(valor);
      } else {
        insereRecursivo(referencia->esquerdo, valor);
      }
    } else {
      if (referencia->direito == NULL) {
        referencia->direito = new No();
        referencia->direito->setSimbolo(valor);
      } else {
        insereRecursivo(referencia->direito, valor);
      }
    }
  }
}

No* Arvore::getRaiz() { return this->raiz; }