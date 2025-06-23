#include "Sistema.h"

#include <iomanip>
#include <iostream>
#include <map>
#include <vector>

#include "Item.h"

int Sistema::quantidadeMesas() { return this->mesas.size(); }

void Sistema::listarItensCardapio() {
  for (Item item : this->itensCardapio) {
    std::cout << item.nome << ", " << item.valor << std::endl;
  }
}

bool Sistema::existeMesaAberta() {
  for (Mesa mesa : this->mesas) {
    if (mesa.estaAberta) return true;
  }
  return false;
}

void Sistema::exibirMesasAbertas() {
  for (Mesa mesa : this->mesas) {
    if (mesa.estaAberta) {
      mesa.imprimirDetalhes();
      std::cout << std::endl;
    }
  }
}

void Sistema::exibirItensCardapio() {
  std::cout << "Cardapio:\n";
  for (Item item : this->itensCardapio) {

    std::cout << "- (ID " << item.id << ") " << item.nome << " — R$" << std::fixed
              << std::setprecision(2) << item.valor << std::endl;
  }
}

std::vector<int> Sistema::obterIdsMesasAbertas() {
  std::vector<int> idsMesasAbertas;
  for (Mesa mesa : this->mesas) {
    if (mesa.estaAberta) idsMesasAbertas.push_back(mesa.id);
  }
  return idsMesasAbertas;
}

std::vector<int> Sistema::obterIdsItensCardapio() {
  std::vector<int> idsItensCardapio;
  for (Item item : this->itensCardapio) {
    idsItensCardapio.push_back(item.id);
  }
  return idsItensCardapio;
}

void Sistema::encerrarContaMesa(int idMesa) {
  for (Mesa& mesa : this->mesas) {
    if (mesa.id == idMesa) {
      mesa.estaAberta = false;
      return;
    }
  }
}

void Sistema::exibirRelatorioMesas() {
  for (Mesa mesa : this->mesas) {
    mesa.imprimirDetalhes();
    std::cout << std::endl;
  }
}

float Sistema::obterTotalVendido() {
  float totalVendido = 0.0f;
  for (Mesa mesa : this->mesas) {
    totalVendido += mesa.obterTotalConta();
  }
  return totalVendido;
}

void Sistema::imprimirTotalVendido() {
  std::cout << "Total vendido: R$ " << std::fixed << std::setprecision(2)
            << this->obterTotalVendido() << std::endl;
}

void Sistema::imprimirRelatorioItensPedidos() {
  std::vector<Item> itensPedidosTodasMesas;
  for (const Mesa& mesa : this->mesas) {
    itensPedidosTodasMesas.insert(itensPedidosTodasMesas.end(),
                                  mesa.itensPedidos.begin(),
                                  mesa.itensPedidos.end());
  }

  std::map<Item, int> quantidadeVendasPorItem;
  for (const Item& item : itensPedidosTodasMesas) {
    if (quantidadeVendasPorItem.count(item)) {
      quantidadeVendasPorItem[item] += 1;
    } else {
      quantidadeVendasPorItem[item] = 1;
    }
  }

  std::cout << "Quantidade de vendas por item:\n";
  for (auto par : quantidadeVendasPorItem) {
    const std::string& nomeItem = par.first.nome;
    const int& quantidadeVendas = par.second;
    std::cout << "- " << quantidadeVendas << " " << nomeItem << std::endl;
  }
}

void Sistema::lancarPedido(int idMesa, int idItem) {
  for (Item item : this->itensCardapio) {
    if (item.id == idItem) {
      for (Mesa& mesa : mesas) {
        if (mesa.id == idMesa) mesa.adicionarPedido(item);
      }
    }
  }
}
