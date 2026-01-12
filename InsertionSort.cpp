#ifndef INSERTION_SORT_H
#define INSERTION_SORT_H

#include <algorithm>
#include <cstddef>
#include <functional>
#include <random>
#include <iostream>
#include <vector>

template <typename T> void insertion_sort(std::vector<T> &a) {
  if (a.size() <= 1)
    return;

  for (size_t i = 1; i < a.size(); i++) {
    T key = a[i];
    size_t j = i;
    while(j && a[j-1] > key){
        a[j] = a[j-1];
        --j;
    }
    a[j] = key;
  }
}

template <typename T, typename Compare = std::less<T>>
void insertion_sort_comp(std::vector<T> &a, Compare comp = Compare{}) {
  if (a.size() <= 1)
    return;

  for (size_t i = 1; i < a.size() - 1; ++i) {
      T key = a[i];
    size_t extremum_idx = i;
    while(extremum_idx && comp(key, a[extremum_idx - 1])){
        a[extremum_idx] = a[extremum_idx - 1];
        --extremum_idx;
    }
    a[extremum_idx] = key;
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
  std::cout << "INSERTION SORT DEMO\n";

  // Test 1 - Ascending (default)
  std::vector<int> numbers = {64, 34, 25, 12, 22, 11, 90, 5};
  std::cout << "Before:\n";
  print_vector(numbers, "numbers");

  insertion_sort(numbers);
  std::cout << "After insertion sort (ascending):\n";
  print_vector(numbers, "numbers");

  std::cout << "\n";

  // Test 2 - Descending using comparator
  std::vector<int> desc = {1, 5, 2, 8, 3, 7, 4, 6};
  std::cout << "Before:\n";
  print_vector(desc, "desc");

  insertion_sort_comp(desc, std::greater<int>{});
  std::cout << "After insertion sort (descending):\n";
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

  insertion_sort_comp(floats, std::greater<float>{}); //for descending
  std::cout << "After insertion sort with comparator:\n";
  print_vector(floats, "floats");

  insertion_sort(floats); // for ascending
  std::cout << "After insertion sort:\n";
  print_vector(floats, "floats");

  std::cout << "Is sorted? " << std::boolalpha
            << std::is_sorted(floats.begin(), floats.end()) << "\n";

  return 0;
}

#endif //! INSERTION_SORT_H
