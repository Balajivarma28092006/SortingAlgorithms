#ifndef SELECTION_SORT_H
#define SELECTION_SORT_H

#include <algorithm>
#include <cstddef>
#include <functional>
#include <random>
#include <iostream>
#include <utility>
#include <vector>

template <typename T> void selection_sort(std::vector<T> &a) {
  if (a.size() <= 1)
    return;

  for (size_t i = 0; i < a.size(); i++) {
    size_t minIndex = i;
    for (size_t j = i + 1; j < a.size(); j++) {
      if (a[minIndex] > a[j]) {
        minIndex = j;
      }
    }
    if (minIndex != i) {
      std::swap(a[i], a[minIndex]);
    }
  }
}

template <typename T, typename Compare = std::less<T>>
void selection_sort_comp(std::vector<T> &a, Compare comp = Compare{}) {
  if (a.size() <= 1)
    return;

  for (size_t i = 0; i < a.size() - 1; ++i) {
    size_t extremum_idx = i;

    for (size_t j = i + 1; j < a.size(); ++j) {
      if (comp(a[j], a[extremum_idx])) {
        extremum_idx = j;
      }
    }

    if (extremum_idx != i) {
      std::swap(a[i], a[extremum_idx]);
    }
  }
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
  std::cout << "SELECTION SORT DEMO\n";

  // Test 1 - Ascending (default)
  std::vector<int> numbers = {64, 34, 25, 12, 22, 11, 90, 5};
  std::cout << "Before:\n";
  print_vector(numbers, "numbers");

  selection_sort(numbers);
  std::cout << "After selection sort (ascending):\n";
  print_vector(numbers, "numbers");

  std::cout << "\n";

  // Test 2 - Descending using comparator
  std::vector<int> desc = {1, 5, 2, 8, 3, 7, 4, 6};
  std::cout << "Before:\n";
  print_vector(desc, "desc");

  selection_sort_comp(desc, std::greater<int>{});
  std::cout << "After selection sort (descending):\n";
  print_vector(desc, "desc");

  std::cout << "\n";

  // Test 3 - Random floating point numbers
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_real_distribution<> dis(0.0, 100.0);

  std::vector<double> floats(10);
  for (auto &x : floats)
    x = dis(gen);

  std::cout << "Random floats before:\n";
  print_vector(floats, "floats");

  selection_sort_comp(floats, std::greater<float>{}); //for descending
  std::cout << "After selection sort with comparator:\n";
  print_vector(floats, "floats");

  selection_sort(floats); // for ascending
  std::cout << "After selection sort:\n";
  print_vector(floats, "floats");

  std::cout << "Is sorted? " << std::boolalpha
            << std::is_sorted(floats.begin(), floats.end()) << "\n";

  return 0;
}

#endif //! SELECTION_SORT_H
