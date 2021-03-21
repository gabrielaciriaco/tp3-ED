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
      decodificar(comando.getTexto());
    }else if(tipo == 'C'){
      codificar(comando.getTexto());
    }
}

void Gerenciador::montaArvore(string comando){
  for(unsigned int i=0; i< comando.length(); i++){
    this->arvore.insere(comando.at(i));
  }
}

void Gerenciador::decodificar(string comando){
  No* noLetra = arvore.getRaiz();
  string fraseDecodificada = "";
  for(unsigned int i = 1; i < comando.length(); i++){
    if(comando.at(i) == 'x'){
      char letra = noLetra->getSimbolo();
      fraseDecodificada += letra;
      noLetra = arvore.getRaiz();
    }else{
      int aux = comando.at(i) - '0';
      if(aux % 2 == 0){
        noLetra = noLetra->getDireito();
      }else{
        noLetra = noLetra->getEsquerdo();
      }
    }
  }
  char letra = noLetra->getSimbolo();
  fraseDecodificada += letra;
  cout<<fraseDecodificada<<endl;
}

void Gerenciador::codificar(string comando){
  No* noLetra = arvore.getRaiz();
  string fraseCodificada = "";
  for(unsigned int i = 0; i<comando.length();i++){
    fraseCodificada += "x";
    fraseCodificada += noLetra->getCodigoCaminho(comando.at(i));
  }
  cout<<fraseCodificada<<endl;
}