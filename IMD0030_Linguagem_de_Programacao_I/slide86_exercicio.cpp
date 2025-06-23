#include <iostream>
#include <vector>

using namespace std;

int main() {
  cout << "Digite 5 números inteiros" << endl;

  vector<int> numeros;
  int entrada;

  for (int i = 0; i < 5; ++i) {
    cin >> entrada;
    numeros.push_back(entrada);
  }

  cout << "Digite um indice: " << endl;
  cin >> entrada;

  try {
    /* code */
    cout << "Número: " << numeros.at(entrada) << endl;;
  } catch (const out_of_range& e) {
    cerr << e.what() << '\n';
  }
}
