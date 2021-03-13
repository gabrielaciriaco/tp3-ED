#include <iostream>
#include "Comando.h"
#include "Gerenciador.h"

using namespace std; 

int contaQuantidadeDeComandos(char *nomeArquivo) {
  FILE *arquivo = fopen(nomeArquivo, "r");
  if (arquivo == NULL) {
    printf("Arquivo no encontrado, verifique se o arquivo esta na pasta");
    exit(1);
  }
  int quantidadeDeComandos = 0;
  char ch;
  char chAnterior;
  while ((ch = fgetc(arquivo)) != EOF) {
    if (ch == '\n') {
      quantidadeDeComandos++;
    }
    chAnterior = ch;
  }
  if (chAnterior != '\n') {
    quantidadeDeComandos++;
  }
  fclose(arquivo);
  return quantidadeDeComandos;
}

Comando *lerArquivo(char *nomeArquivo, int quantidadeDeLinhas) {
  Comando *comandos = new Comando[quantidadeDeLinhas];
  FILE *arquivo = fopen(nomeArquivo, "r");
  if (arquivo == NULL) {
    printf("Arquivo no encontrado, verifique se o arquivo esta na pasta");
    exit(1);
  }
  char aux;
  for (int i = 0; i < quantidadeDeLinhas; i++) {
      char tipo;
      string texto = "";
      fscanf(arquivo, "%c", &tipo);    
      fscanf(arquivo, "%c ",&aux);
      aux = fgetc(arquivo);
      while(aux != '\n'  && aux != EOF ){
          texto += aux;
          aux = fgetc(arquivo);
      }
      comandos[i].setTipo(tipo);
      comandos[i].setTexto(texto);
  }
  return comandos;
}

int main(int argc, char *argv[]) {
  char *nomeArquivo = argv[1];
  int quantidadeDeComandos = contaQuantidadeDeComandos(nomeArquivo);
  Comando *comandos = lerArquivo(nomeArquivo, quantidadeDeComandos);
  Gerenciador gerenciador;
  gerenciador.gerenciaComandos(comandos,quantidadeDeComandos);
  return 0;
}