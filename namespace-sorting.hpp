#ifndef SORTING_HPP
#define SORTING_HPP

using namespace std;

namespace sorting {
  
template<typename T>
void Merge(vector<T>& array, int l, int m, int r) {
  int n1 = m - l + 1;
  int n2 = r - m;

  vector<T> L(n1);
  vector<T> R(n2);

  for (int i = 0; i < n1; i++) {
    L[i] = array[l + i];
  }
  for (int j = 0; j < n2; j++) {
    R[j] = array[m + 1 + j];
  }

  int i = 0, j = 0, k = l;
  while (i < n1 || j < n2) {
    if (j >= n2 || (i < n1 && L[i] <= R[j])) {
      array[k] = L[i];
      i++;
    } else {
      array[k] = R[j];
      j++;
    }
    k++;
  }
}

template<typename T>
void MergeSort(vector<T>& array, int l, int r) {
  if (l < r) {
    int m = l + (r - l) / 2;
    MergeSort(array, l, m);
    MergeSort(array, m + 1, r);
    Merge(array, l, m, r);
  }
}

template<typename T>
void GenerateArrayWithRandomNumbers(vector<T>& array, const int N) {
  array.resize(N);
  for (int i = 0; i < N; i++) {
    array[i] = rand() % 123456789;
  }
}

template<typename T>
void ShowArray(vector<T>& array) {
//  cout << "Size = " << array.size() << '\n';
  for (int i = 0; i < (int) array.size(); i++) {
    if (i > 0) {
      cout << ' ';
    }
    cout << array[i];
  }
  cout << '\n';
}

template<typename T>
void BubbleSort(vector<T>& array, int n) {
  for (int i = 0; i < n - 1; i++) {
    for (int j = i + 1; j < n; j++) {
      if (array[i] > array[j]) {
        swap(array[i], array[j]);
      }
    }
  }
}

}  // namespace sorting

#endif
