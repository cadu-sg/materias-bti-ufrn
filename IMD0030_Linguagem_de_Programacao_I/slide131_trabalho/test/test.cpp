#include <algorithm>
#include <iostream>
#include <limits>
#include <sstream>
#include <unordered_map>
#include <vector>

#include "Mesa.h"
#include "Sistema.h"

using namespace std;

string vectorParaString(const vector<int>& v) {
  ostringstream oss;
  auto it = v.begin();
  if (it == v.end()) return "";
  oss << *it;
  for (it = ++it; it != v.end(); ++it) {
    oss << ", " << *it;
  }
  return oss.str();
}

int selecionarNumero(const vector<int>& opcoesValidas) {
  int escolha;
  bool escolhaEstaValida = false;

  while (true) {
    cin >> escolha;
    if (cin.fail()) {
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
    } else if (find(opcoesValidas.begin(), opcoesValidas.end(), escolha) !=
               opcoesValidas.end()) {
      return escolha;
    }
    cout << "Opcao invalida. Escolha entre: " << vectorParaString(opcoesValidas)
         << endl;
  }
}

int main() {
  // selecionarNumero(vector<int>{1, 2, 4, 5});
  Item i1(1, "croissant", 15.00);
  Item i2(2, "coxinha de frango", 10.00);
  Item i3(3, "brigadeiro", 3.00);

  Mesa m1(1, true);
  Mesa m2(2, true);
  Mesa m3(3, true);
  m1.itensPedidos = {i1, i2, i3};

  // mesa.imprimirDetalhes();
  // cout << mesa.obterTotalConta() << endl;

  // mesa.adicionarPedido(i3);

  // mesa.imprimirDetalhes();
  // cout << mesa.obterTotalConta() << endl;

  if (m1 == m2) {
    cout << "Verdadeiro" << endl;
  } else {
    cout << "Falso" << endl;
  }

  unordered_map<string, int> foo;

  return 0;
}
