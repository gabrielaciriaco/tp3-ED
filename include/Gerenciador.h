#ifndef I_Gerenciador_H
#define I_Gerenciador_H
#include <string>
#include "Arvore.h"
#include "Comando.h"

using namespace std;
class Gerenciador{
  private:
    Arvore arvore;

  public:
    Gerenciador();
    Gerenciador(Arvore arvore);
    Arvore getArvore();
    void setArvore(Arvore arvore);
    void gerenciaComandos (Comando *comandos, int quantidadeDeComandos);
    void interpretaComando(Comando comando);
    void montaArvore(string comando);
};

#endif