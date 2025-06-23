#include <iostream>
#include <string>

struct Pessoa {
  std::string nome;
  int idade;

  void apresentar() { std::cout << "Ola, meu nome é " << nome << std::endl; }

  // Pessoa(std::string n, int i) {
  //   nome = n;
  //   idade = i;
  // }

  Pessoa(std::string n, int i) : nome(n), idade(i) {
    std::cout << "Construtor executado" << std::endl;
  }
  
  // o `this->` serve para identificar atributos do nosso struct

  Pessoa() {}

  ~Pessoa() {
    std::cout << "Destrutor chamado!" << std::endl;
  }
};

using namespace std;

int main(int argc, char const *argv[]) {
  Pessoa p;
  p.nome = "Joao";
  p.idade = 25;
  p.apresentar();

  Pessoa foo("Cadu", 18);
  cout << "Nome: " << foo.nome << endl;
  cout << "Idade " << foo.idade << endl;

  Pessoa* p3 = new Pessoa("Lucas", 30);

  delete p3;

  return 0;
}
