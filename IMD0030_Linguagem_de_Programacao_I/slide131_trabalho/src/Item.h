#pragma once

#include <string>

struct Item {
  int id;
  std::string nome;
  float valor;
  Item(int id, std::string nome, float valor);
  bool operator==(const Item& outro) const;
  bool operator<(const Item& other) const { return id < other.id; }
};
