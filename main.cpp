#include <bits/stdc++.h>
#include "namespace-sorting.hpp"

using namespace std;

int main() {
  vector<int> arr {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
  int n = (int) arr.size();
  sorting::MergeSort(arr, 0, n - 1);
  for (int i = 0; i < n; i++) {
    if (i > 0) {
      cout << " ";
    }
    cout << arr[i];
  }
  cout << '\n';
  return 0;
}

