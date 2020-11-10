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
int Partition(vector<T>& array, int l, int r) {
  T pivot = array[r];
  int j = l;
  for (int i = l; i < r; i++) {
    if (array[i] <= pivot) {
      swap(array[i], array[j]);
      j++;
    }
  }
  swap(array[j], array[r]);
  return j;
}

template<typename T>
void QuickSort(vector<T>& array, int l, int r) {
  if (r <= l) {
    return;
  }
  // Median Of Three
  int mid = l + (r - l) / 2;
  if (array[r] < array[mid]) {
    T temp = array[r];
    array[r] = array[mid];
    array[mid] = temp;
  } if (array[mid] < array[l]) {
    T temp = array[mid];
    array[mid] = array[l];
    array[l] = temp;
  } if (array[mid] < array[r]) {
    T temp = array[mid];
    array[mid] = array[r];
    array[r] = temp;
  }
  T temp = Partition(array, l, r);
  QuickSort(array, l, temp - 1);
  QuickSort(array, temp + 1, r);
}

template<typename T>
double ExecutionTimeOfMergeSort(vector<T>& array, int l, int r) {
  clock_t start = clock();
  MergeSort(array, l, r);
  clock_t end = clock();
  return ((double) (end - start)) / CLOCKS_PER_SEC;
}

template<typename T>
double ExecutionTimeOfQuickSort(vector<T>& array, int l, int r) {
  clock_t start = clock();
  QuickSort(array, l, r);
  clock_t end = clock();
  return ((double) (end - start)) / CLOCKS_PER_SEC;
}

template<typename T>
void UnorderedArrayFile(vector<T>& array, const int N) {
  ofstream unordered_array("unordered_array.txt");
  for (int i = 0; i < N; i++) {
    unordered_array << array[i] << '\n';
  }
  unordered_array.close();
}

vector<long long> ReadUnorderedArrayFile(const char* path) {
  vector<long long> array;
  ifstream ua(path);
  if (!ua) {
    cout << "unable to open a file!\n";
  }
  long long value;
  while (ua >> value) {
    array.emplace_back(value);
  }
  return array;
}

template<typename T>
void GenerateTimesToMergeSort(vector<T> array) {
  vector<T> size = {10, 100, 1000, 10000, 100000, 1000000, 10000000};
  for (int i = 0; i < (int) size.size(); i++) {
    ofstream fp("times_mergesort/time_mergesort_" + to_string(size[i]) + "_elements.txt");
    ofstream ifpf("times_mergesort/unordered_array_before_mergesort_" + to_string(size[i]) + "_elements");
    GenerateArrayWithRandomNumbers(array, size[i]);
    UnorderedArrayFile(array, size[i]);
    array = ReadUnorderedArrayFile("unordered_array.txt");
    for (const auto& each : array) {
      ifpf << each << '\n';
    }
    clock_t start = clock();
    MergeSort(array, 0, (int) array.size() - 1);
    clock_t end = clock();
    for (int j = 0; j < (int) array.size(); j++) {
      fp << array[j] << '\n';
    }
    fp << "time: " << ((double) (end - start)) / CLOCKS_PER_SEC << " seconds" << '\n';
  }
}

template<typename T>
void GenerateTimesToQuickSort(vector<T> array) {
  vector<T> size = {10, 100, 1000, 10000, 100000, 1000000, 10000000};
  for (int i = 0; i < (int) size.size(); i++) {
    ofstream fp("times_quicksort/time_quicksort_" + to_string(size[i]) + "_elements.txt");
    ofstream ifpf("times_quicksort/unordered_array_before_quicksort_" + to_string(size[i]) + "_elements");
    GenerateArrayWithRandomNumbers(array, size[i]);
    UnorderedArrayFile(array, size[i]);
    array = ReadUnorderedArrayFile("unordered_array.txt");
    for (const auto& each : array) {
      ifpf << each << '\n';
    }
    clock_t start = clock();
    QuickSort(array, 0, (int) array.size() - 1);
    clock_t end = clock();
    for (int j = 0; j < (int) array.size(); j++) {
      fp << array[j] << '\n';
    }
    fp << "time: " << ((double) (end - start)) / CLOCKS_PER_SEC << " seconds" << '\n';
  }
}

}  // namespace sorting

#endif
