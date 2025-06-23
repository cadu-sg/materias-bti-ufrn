#include <iostream>
#include <map>

#include "Item.h"

// struct Item {
//   int id;
//   std::string name;
//   // Define operator< for ordering
//   bool operator<(const Item& other) const { return id < other.id; }
// };

using namespace std;

int main() {
  std::map<Item, int> mymap;

  Item i1(1, "caduzao", 1000000.00f);
  i1.id = 1;
  i1.nome = "Caduzao";

  mymap.insert({i1, 1});

  for (auto x : mymap) {
    cout << x.first.id << " " << x.first.nome << " " << x.second << endl;
  }

  // pointMap[{1, 2}] = "A";
  // pointMap[{2, 3}] = "B";

  // for (const auto& [key, value] : pointMap) {
  //     std::cout << "(" << key.x << ", " << key.y << ") -> " << value << '\n';
  // }

  // return 0;
}
