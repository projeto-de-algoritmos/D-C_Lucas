#ifndef MENU_HPP
#define MENU_HPP

using namespace std;

namespace menu {

void MenuRandomNumbers() {
    cout << "1 - Gerar array com 10 números aleatórios" << '\n';
    cout << "2 - Gerar array com 100 números aleatórios" << '\n';
    cout << "3 - Gerar array com 1000 números aleatórios" << '\n';
    cout << "4 - Gerar array com 10000 números aleatórios" << '\n';
    cout << "5 - Gerar array com 100000 números aleatórios" << '\n';
    cout << "6 - Gerar array com 1000000 números aleatórios" << '\n';
    cout << "7 - Gerar array com 10000000 números aleatórios" << '\n';
    cout << "8 - Gerar array com 100000000 números aleatórios" << '\n';
    cout << "0 - Voltar ao menu principal" << '\n';
    cout << "Digite a sua opção: ";
}

void MainMenu() {
    cout << "1 - Gerar array com números aleatórios" << '\n';
    cout << "2 - Ordenar o array usando Merge Sort" << '\n';
    cout << "0 - Encerrar" << '\n';
    cout << "Digite sua opção: ";
} 


} //  namespace menu

#endif
