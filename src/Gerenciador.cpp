#include "../include/Gerenciador.h"

Gerenciador::Gerenciador(){
  this->arvore = Arvore();
}
Gerenciador::Gerenciador(Arvore arvore){
  this->arvore = arvore;
}

Arvore Gerenciador::getArvore(){
  return this->arvore;
}

void Gerenciador::setArvore(Arvore arvore){
  this->arvore = arvore;
}

void Gerenciador::gerenciaComandos (Comando *comandos, int quantidadeDeComandos){
    for(int i=0; i < quantidadeDeComandos; i++){
      interpretaComando(comandos[i]);
    }
}

void Gerenciador::interpretaComando(Comando comando){
    char tipo = comando.getTipo();
    if(tipo == 'A'){
      montaArvore(comando.getTexto());
    }else if(tipo == 'D'){
      //ToDo decodificar
    }else if(tipo == 'C'){
      //ToDo codificar
    }
}

void Gerenciador::montaArvore(string comando){
  for(int i=0; i< comando.length(); i++){
    char aux = comando.at(i);
    this->arvore.insere(comando.at(i));
  }
}