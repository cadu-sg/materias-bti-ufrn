#include "Item.h"

#include <string>

Item::Item(int id, std::string nome, float valor)
    : id(id), nome(nome), valor(valor) {}

bool Item::operator==(const Item& outro) const { return id == outro.id; }

// bool Item::operator<(const Item& outro) const { return id < outro.id; }
