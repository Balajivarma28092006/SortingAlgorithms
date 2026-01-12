#ifndef MERGE_SORT_H
#define MERGE_SORT_H

#include <algorithm>
#include <cstddef>
#include <functional>
#include <iostream>
#include <random>
#include <vector>

template <typename T>
void merge(std::vector<T> &a, size_t left, size_t mid, size_t right) {
  size_t n = mid - left + 1;
  size_t m = right - mid;

  std::vector<T> L(n), R(m);
  for (size_t i = 0; i < n; i++)
    L[i] = a[left + i];
  for (size_t j = 0; j < m; j++)
    R[j] = a[mid + 1 + j];

  int i = 0, j = 0, k = left;
  while (i < n && j < m) {
    if (L[i] <= R[j]) {
      a[k] = L[i];
      ++i;
    } else {
      a[k] = R[j];
      ++j;
    }
    ++k;
  }

  while (i < n) {
    a[k] = L[i];
    ++i;
    ++k;
  }

  while (j < m) {
    a[k] = R[j];
    ++j;
    ++k;
  }
}

template <typename T>
void mergeSort(std::vector<T> &arr, size_t left, size_t right) {

  if (left < right) {
    size_t mid = left + (right - left) / 2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    merge(arr, left, mid, right);
  }
}

// with comparator
template <typename T, typename Compare>
void merge_comp(std::vector<T> &arr, size_t left, size_t mid, size_t right,
                Compare comp) {
  size_t n = mid - left + 1;
  size_t m = right - mid;

  std::vector<T> L(n), R(m);
  for (size_t i = 0; i < n; i++)
    L[i] = arr[left + i];
  for (size_t j = 0; j < m; j++)
    R[j] = arr[mid + 1 + j];

  int i = 0, j = 0, k = left;
  while (i < n && j < m) {
    if (comp(L[i], R[j])) {
      arr[k] = L[i];
      ++i;
    } else {
      arr[k] = R[j];
      ++j;
    }
    ++k;
  }

  while (i < n) {
    arr[k] = L[i];
    ++i;
    ++k;
  }

  while (j < m) {
    arr[k] = R[j];
    ++j;
    ++k;
  }
}

template <typename T, typename Compare>
void mergeSortComp(std::vector<T> &arr, size_t left, size_t right,
                   Compare comp) {
  if (left >= right) {
    return;
  }

  size_t mid = left + (right - left) / 2;
  mergeSortComp(arr, left, mid, comp);
  mergeSortComp(arr, mid + 1, right, comp);
  merge_comp(arr, left, mid, right, comp);
}

// print function
template <typename T>
void print_vector(const std::vector<T> &a, const char *name = "vector") {
  std::cout << name << ": [ ";
  for (size_t i = 0; i < a.size(); i++) {
    std::cout << a[i];
    if (i < a.size() - 1)
      std::cout << ", ";
  }
  std::cout << " ]\n";
}

int main() {
  std::cout << "MERGE SORT DEMO\n";

  // Test 1 - Ascending (default)
  std::vector<int> numbers = {64, 34, 25, 12, 22, 11, 90, 5};
  std::cout << "Before:\n";
  print_vector(numbers, "numbers");

  mergeSort(numbers, 0, numbers.size() - 1);
  std::cout << "After insertion sort (ascending):\n";
  print_vector(numbers, "numbers");

  std::cout << "\n";

  // Test 2 - Descending
  std::vector<int> arr2 = {1, 5, 2, 8, 3, 7, 4, 6, 9, 10};
  std::cout << "Before:\n";
  print_vector(arr2, "arr2");

  mergeSortComp(arr2, 0, arr2.size() - 1, std::greater<int>{});
  std::cout << "After merge sort (descending):\n";
  print_vector(arr2, "arr2");

  std::cout << "\n";

  // Test 3 : custom comparator
  std::vector<int> arr3 = {-5, 12, -8, 3, -15, 7, 4, -2, 19, -10};
  std::cout << "Before:\n";
  print_vector(arr3, "arr3 (abs sort)");

  auto abs_comp = [](int a, int b) { return std::abs(a) < std::abs(b); };

  mergeSortComp(arr3, 0, arr3.size() - 1, abs_comp);
  std::cout << "After merge sort (by absolute value):\n";
  print_vector(arr3, "arr3");

  // Test 4: random values
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_real_distribution<> dis(0.0, 100.0);

  std::vector<double> floats(10);
  for (auto &x : floats) {
    x = dis(gen);
  }

  std::cout << "Random floats before:\n";
  print_vector(floats, "floats");

  mergeSortComp(floats, 0, floats.size() - 1,
                std::greater<float>{}); // for descending
  std::cout << "After merge sort (comparator std::greater) :\n";
  print_vector(floats, "floats");

  mergeSortComp(floats, 0, floats.size() - 1,
                std::less<float>{}); // for ascending
  std::cout << "After merge sort (comparator std::less) :\n";
  print_vector(floats, "floats");

  std::cout << "Is sorted? " << std::boolalpha
            << std::is_sorted(floats.begin(), floats.end()) << "\n";
}

#endif // !MERGE_SORT_H
