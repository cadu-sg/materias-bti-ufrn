#include <iostream>

using namespace std;

class Animal {
 public:
  void emitirSom() {}
};

class Gato : public Animal {
 public:
  int idade;
  void miar() { cout << "Miaaau" << endl; }
};

class Cachorro : public Animal {
 public:
  void latir() { cout << "Au au" << endl; }
};

void vacinar(Animal animal) { cout << "Vacinar " << animal.nome << endl; }

int main(int argc, char const* argv[]) {
  Gato g1("Frajola", 10);
  Cachorro c1("Zeus");

  g1.miar();
  c1.latir();

  Animal* a1 = new Gato("Mingau", 3);
  Animal* a2 = new Cachorro("Toto");

  (dynamic_cast<Gato*>(a1)).miar();

  return 0;
}
