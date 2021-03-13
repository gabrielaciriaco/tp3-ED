#ifndef I_No_H
#define I_No_H
#include <string>

using namespace std;
class No{
  private:
    char simbolo;
    No *esquerdo;
    No *direito;
  public:
    No();
    No(char simbolo, No *esquerdo, No *direito);
    No(char simbolo);
    char getSimbolo();
    void setSimbolo(char simbolo);
    No* getEsquerdo();
    void setEsquerdo(No *esquerdo);
    No* getDireito();
    void setDireito(No *direito);
    
    friend class Arvore;
};

#endif