#include "Mesa.h"

#include <iostream>

Mesa::Mesa(int id, bool estaAberta) : id(id), estaAberta(estaAberta) {}

void Mesa::imprimirDetalhes() {
  std::string a = this->estaAberta ? "aberta" : "fechada";

  std::cout << "Mesa (ID " << this->id << ", "
            << (this->estaAberta ? "aberta" : "fechada") << ")\n"
            << "  Pedidos:" << std::endl;
  for (Item item : this->itensPedidos) {
    std::cout << "  - " << item.nome << std::endl;
  }
}

void Mesa::adicionarPedido(Item itemPedido) {
  this->itensPedidos.push_back(itemPedido);
}

float Mesa::obterTotalConta() {
  float totalConta = 0.0f;
  for (Item pedido : this->itensPedidos) {
    totalConta += pedido.valor;
  }
  return totalConta;
}

bool Mesa::operator==(const Mesa& outro) const { return id == outro.id; }

bool Mesa::operator<(const Mesa& outro) const { return id < outro.id; }

// bool operator==(const Mesa& esquerdo, const Mesa& direito) {
//   return esquerdo.id == direito.id;
// }
