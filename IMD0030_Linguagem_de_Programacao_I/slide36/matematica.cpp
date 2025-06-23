#include <iostream>
#include "matematica.h"

int somar(int a, int b) { return a + b; }

int subtracao(int a, int b) { return a - b; }

using namespace std;

int main(int argc, char const *argv[]) {
  cout << somar(2, 3) << endl;
  cout << subtracao(2, 3) << endl;
  return 0;
}
