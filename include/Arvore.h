#ifndef I_Arvore_H
#define I_Arvore_H
#include <string>
#include "No.h"

using namespace std;
class Arvore{
  private:
    No *raiz;
    void insereRecursivo(No* &referencia, char valor);
  public:
    Arvore();
    Arvore(No *raiz);
    void insere(char valor);
    No* getRaiz();
};

#endif