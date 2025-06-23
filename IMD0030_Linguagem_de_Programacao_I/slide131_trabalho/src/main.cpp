#include <algorithm>
#include <iostream>
#include <limits>
#include <sstream>
#include <vector>

#include "Item.h"
#include "Sistema.h"

using namespace std;

string vectorParaString(const vector<int>& v) {
  ostringstream oss;
  auto it = v.begin();
  if (it == v.end()) return "";
  oss << *it;
  for (it = ++it; it != v.end(); ++it) {
    oss << ", " << *it;
  }
  return oss.str();
}

int selecionarNumero(const vector<int>& opcoesValidas) {
  int escolha;

  while (true) {
    cin >> escolha;
    if (cin.fail()) {
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
    } else if (find(opcoesValidas.begin(), opcoesValidas.end(), escolha) !=
               opcoesValidas.end()) {
      return escolha;
    }
    cout << "Opcao invalida. Escolha entre: " << vectorParaString(opcoesValidas)
         << endl;
  }
}

int main(int argc, char const* argv[]) {
  // Inicializar sistema
  Sistema sistema;

  // Inicializar itens
  // id, nome, valor
  Item i1(1, "croissant", 15.00);
  Item i2(2, "coxinha de frango", 10.00);
  Item i3(3, "brigadeiro", 3.00);
  sistema.itensCardapio = {i1, i2, i3};

  // Inicializar mesas
  // id, estaAberta
  Mesa m1(1, true);
  Mesa m2(2, true);
  Mesa m3(3, true);
  sistema.mesas = {m1, m2, m3};

  while (true) {
    cout << "----------------------\n"
         << "SISTEMA DO RESTAURANTE\n"
         << "----------------------\n"
         << "Digite uma opção e pressione Enter:\n"
         << "1) Lançar novo pedido\n"
         << "2) Encerrar conta da mesa\n"
         << "3) Exibir relatório de mesas (aberta/fechada e itens pedidos por "
            "mesa) e "
            "total vendido até agora\n"
         << "4) Exibir relatório de vendas final e sair (necessário encerrar "
            "todas as "
            "mesas)"
         << endl;
    int escolha = selecionarNumero(vector<int>{1, 2, 3, 4});

    if (escolha == 1) {
      if (!sistema.existeMesaAberta()) {
        cout << "Não é possível lançar um novo pedido, pois não há mesas "
                "abertas.\n"
             << endl;
        continue;
      }

      cout << "\nSELECIONAR MESA\n"<< endl;
      sistema.exibirMesasAbertas();
      cout << "Selecione o ID da mesa a pedir o item: " << flush;
      int idMesa = selecionarNumero(sistema.obterIdsMesasAbertas());

      cout << "\nSELECIONAR ITEM\n"<< endl;
      sistema.exibirItensCardapio();
      cout << "\nSelecione o ID do item a pedir: " << flush;
      int idItem = selecionarNumero(sistema.obterIdsItensCardapio());

      sistema.lancarPedido(idMesa, idItem);
      cout << endl;
    } else if (escolha == 2) {
      if (!sistema.existeMesaAberta()) {
        cout << "Não é possível encerrar nenhuma conta de mesa, pois não há "
                "mesas abertas.\n"
             << endl;
        continue;
      }
      cout << "\nSELECIONAR MESA\n"<< endl;
      sistema.exibirMesasAbertas();
      cout << "Selecione o ID da mesa a encerrar: " << flush;
      int idMesa = selecionarNumero(sistema.obterIdsMesasAbertas());
      sistema.encerrarContaMesa(idMesa);
    } else if (escolha == 3) {
      sistema.exibirRelatorioMesas();
      sistema.imprimirTotalVendido();
      cout << endl;
    } else if (escolha == 4) {
      if (sistema.existeMesaAberta()) {
        cout << "Não é possível exibir o relatório final das vendas, pois "
                "ainda há mesas abertas.\n"
             << "  IDs das mesas abertas: "
             << vectorParaString(sistema.obterIdsMesasAbertas()) << '\n'
             << endl;
        // sistema.exibirMesasAbertas();
        continue;
      }
      sistema.imprimirRelatorioItensPedidos();
      cout << '\n';
      sistema.imprimirTotalVendido();
      break;
    }
  }

  return 0;
}
