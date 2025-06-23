#include <string>
#include <list>
#include <algorithm>
#include <iostream>

using namespace std;

struct Pessoa {
  string nome;
  int idade;

  bool operator==(const Pessoa& outra) const {
    return nome == outra.nome && idade == outra.idade;
  }
};

int main() {
  list<Pessoa> pessoas;

  Pessoa ana;
  ana.nome = "Ana";
  ana.idade = 98;

  Pessoa carlos;
  carlos.nome = "Carlos";
  carlos.idade = 93;

  Pessoa stefanie;
  stefanie.nome = "Stefanie";
  stefanie.idade = 100;

  pessoas.push_back(ana);
  pessoas.push_back(carlos);
  pessoas.push_back(stefanie);

  auto it = find(pessoas.begin(), pessoas.end(), carlos);
  
  if (it != pessoas.end()) {
    cout << "Pessoa encontrada: " << it->nome << ", " << it->idade << " anos" << endl;
  } else {
    cout << "Pessoa não encontrada" << endl;
  }

  pessoas.remove(carlos);

  return 0;
}
