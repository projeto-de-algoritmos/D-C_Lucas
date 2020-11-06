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

}

#endif
