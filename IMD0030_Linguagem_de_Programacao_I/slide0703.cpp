#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Veiculo {
 private:
  string marca;
  string modelo;

 public:
  Veiculo(string marca, string modelo) : marca(marca), modelo(modelo) {}

  void exibirInformacoes() {
    cout << "Marca: " << this->marca << ", Modelo: " << this->modelo << endl;
  }
};

class Carro : public Veiculo {
  int numeroPortas;

  public:
  Carro(string marca, string modelo, int numeroPortas) : Veiculo(marca, modelo), numeroPortas(numeroPortas) {}

  void exibirInformacoesCarro() {
    exibirInformacoes();
    cout << "Numero de portas: " << numeroPortas << endl;
  }
};

class Moto : public Veiculo {
  int cilindrada;

  public:
  Moto(string marca, string modelo, int cilindrada) : Veiculo(marca, modelo), cilindrada(cilindrada) {}

  void exibirInformacoesMoto() {
    exibirInformacoes();
    cout << "Cinlindrada: " << cilindrada << endl;
  }
};

class SistemaVeiculos {
  vector<Veiculo> veiculos;

  void create(const Veiculo& element) {
    veiculos.push_back(element);
  }
}

int main(int argc, char const *argv[]) {
  /* code */
  Veiculo v1("Fiat", "Uno");
  v1.exibirInformacoes();

  Carro c1("Chevrolet", "Celta", 3);

  c1.exibirInformacoesCarro();



  return 0;
}
