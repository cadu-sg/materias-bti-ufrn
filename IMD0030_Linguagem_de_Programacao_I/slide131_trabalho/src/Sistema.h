#pragma once

#include <vector>

#include "Item.h"
#include "Mesa.h"

struct Sistema {
  std::vector<Mesa> mesas;
  std::vector<Item> itensCardapio;

  int quantidadeMesas();
  void listarItensCardapio();
  void listarMesasDetalhado();
  void lancarPedido(int idMesa, int idItem);
  bool existeMesaAberta();
  void exibirMesasAbertas();
  void exibirItensCardapio();
  void encerrarContaMesa(int idMesa);
  std::vector<int> obterIdsMesasAbertas();
  std::vector<int> obterIdsItensCardapio();
  void exibirRelatorioMesas();
  float obterTotalVendido();
  void imprimirTotalVendido();
  void imprimirRelatorioItensPedidos();
};
