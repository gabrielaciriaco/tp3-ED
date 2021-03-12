#ifndef I_Comando_H
#define I_Comando_H
#include <string>

using namespace std;
class Comando{
  private:
    char tipo;
    string texto;
  public:
    Comando();
    Comando(char tipo, string texto);
    char getTipo();
    void setTipo(char tipo);
    string getTexto();
    void setTexto(string texto);
};

#endif