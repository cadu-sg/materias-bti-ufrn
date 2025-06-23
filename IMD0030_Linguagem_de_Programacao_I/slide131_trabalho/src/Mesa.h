#pragma once

#include <vector>

#include "Item.h"

struct Mesa {
  int id;
  bool estaAberta;
  std::vector<Item> itensPedidos;
  void imprimirDetalhes();
  float obterTotalConta();
  void adicionarPedido(Item itemPedido);
  Mesa(int id, bool estaAberta);
  bool operator==(const Mesa& outro) const;
  bool operator<(const Mesa& outro) const;
};

