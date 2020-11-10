#include <bits/stdc++.h>
#include "sorting-namespace.hpp"
#include "menus-namespace.hpp"

void debug_out() { cerr << endl; }
 
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cerr << " " << to_string(H);
  debug_out(T...);
}

#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int option = -1;
  bool loop_condition = true;
  vector<long long> array;
  while (loop_condition) {
    menu::MainMenu();
    cin >> option;
    if (option == 1) {
      int opt;
      do {
        menu::MenuRandomNumbers();
        cin >> opt;
        switch (opt) {
          case 1:
            sorting::GenerateArrayWithRandomNumbers(array, 10);
            cout << "O array gerado foi o seguinte: " << '\n';
            sorting::ShowArray(array);
            break;
          case 2:
            sorting::GenerateArrayWithRandomNumbers(array, 100);
            cout << "O array gerado foi o seguinte: " << '\n';
            sorting::ShowArray(array);
            break;
          case 3:
            sorting::GenerateArrayWithRandomNumbers(array, 1000);
            cout << "O array gerado foi o seguinte: " << '\n';
            sorting::ShowArray(array);
            break;
          case 4:
            sorting::GenerateArrayWithRandomNumbers(array, 10000);
            cout << "O array gerado foi o seguinte: " << '\n';
            sorting::ShowArray(array);
            break;
          case 5:
            sorting::GenerateArrayWithRandomNumbers(array, 100000);
            cout << "O array gerado foi o seguinte: " << '\n';
            sorting::ShowArray(array);
            break;
          case 6:
            sorting::GenerateArrayWithRandomNumbers(array, 1000000);
            cout << "O array gerado foi o seguinte: " << '\n';
            sorting::ShowArray(array);
            break;
          case 7:
            sorting::GenerateArrayWithRandomNumbers(array, 10000000);
            cout << "O array gerado foi o seguinte: " << '\n';
            sorting::ShowArray(array);
            break;
          case 8:
            sorting::GenerateArrayWithRandomNumbers(array, 100000000);
            cout << "O array foi gerado." << '\n';
            break;
          case 0:
            cout << "Obrigado" << '\n';
            break;
          default:
            cout << "Digite uma opção válida!" << '\n';
            break;
        }
      } while (opt != 0);
    } else if (option == 2) {
      cout << "Ordenando o array com o Merge Sort" << '\n';
      const int N = (int) array.size();
      assert((int) array.size() == N);
      ofstream ordered_array("ordered_array.txt");
      if (N == 100000000 || N == 10000000) {
        double time = sorting::ExecutionTimeOfAlgorithm(array, 0, N - 1);
        for (int i = 0; i < N; i++) {
          ordered_array << array[i] << '\n';
        }
        ordered_array << "O tempo de execução do Merge Sort foi de: " << time << " segundos\n";
        cout << "Foi gerado um arquivo (ordered_array.txt)" << '\n';        
      } else {
        double time = sorting::ExecutionTimeOfAlgorithm(array, 0, N - 1);
        sorting::ShowArray(array);
        cout << "O tempo de execução do Merge Sort foi de: " << time << " segundos\n";
        debug(clock());
      }
    } else if (option == 0) {
      cout << "Obrigado" << '\n';
      loop_condition = false;
    }
    
  }
  return 0;
}

