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
void BubbleSort(vector<T>& array, int n) {
  for (int i = 0; i < n - 1; i++) {
    for (int j = i + 1; j < n; j++) {
      if (array[i] > array[j]) {
        swap(array[i], array[j]);
      }
    }
  }
}

template<typename T>
int MedianOfThree(vector<T>& array, int l, int r) {
  int mid = l + (r - l) / 2;
  if (array[r] < array[l]) {
    swap(array[r], array[l]);
  } if (array[mid] < array[l]) {
    swap(array[mid], array[l]);
  } if (array[r] < array[mid]) {
    swap(array[r], array[mid]);
  }
  return mid;
}

template<typename T>
int Partition(vector<T>& array, int l, int r) {
  auto M = MedianOfThree(array, l, r);
  T pivot = array[M];
  int j = l - 1;
  for (int i = l; i < r; i++) {
    if (array[i] <= pivot) {
      j++;
      swap(array[i], array[j]);
    }
  }
  swap(array[j + 1], array[r]);
  return j + 1;
}

template<typename T>
void QuickSort(vector<T>& array, int l, int r) {
  if (l < r) {
    T temp = Partition(array, l, r);
    QuickSort(array, l, temp - 1);
    QuickSort(array, temp + 1, r);
  }
}

template<typename T>
double ExecutionTimeOfMergeSort(vector<T>& array, int l, int r) {
  clock_t start = clock();
  sorting::MergeSort(array, l, r);
  clock_t end = clock();
  return ((double) (end - start)) / CLOCKS_PER_SEC;
}

template<typename T>
double ExecutionTimeOfQuickSort(vector<T>& array, int l, int r) {
  clock_t start = clock();
  sorting::QuickSort(array, l, r);
  clock_t end = clock();
  return ((double) (end - start)) / CLOCKS_PER_SEC;
}


}  // namespace sorting

#endif
