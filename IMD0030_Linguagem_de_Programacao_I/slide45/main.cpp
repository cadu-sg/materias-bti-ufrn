#include <iostream>

#include "calculadora.h"

using namespace std;

int main(int argc, char const *argv[]) {
  cout << "Calculadora\n";

  while (true) {
    int selecao;
    cout << "Escolha uma das opções: 1 - Soma, 2 - Subtracao, 3 - Divisao, 4 - "
            "Multiplicacao, 0 - Sair"
         << endl;
    cin >> selecao;
    if (selecao == 0) {
      break;
    } else if (selecao < 0 || selecao > 4) {
      cout << "Opção inválida!" << endl;
      continue;
    }

    float a;
    float b;
    cout << "Digite o primeiro numero: ";
    cin >> a;
    cout << "Digite o segundo numero: ";
    cin >> b;
    float resultado;
    switch (selecao) {
      case 1:
        resultado = adicao(a, b);
        break;
      case 2:
        resultado = subtracao(a, b);
        break;
      case 3:
        resultado = divisao(a, b);
        break;
      case 4:
        resultado = multiplicacao(a, b);
        break;
    }
    cout << "Resultado: " << resultado << endl;
  }
  return 0;
}
