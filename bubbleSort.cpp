#ifndef BUBBLE_SORT_H
#define BUBBLE_SORT_H

#include <algorithm> // for std::is_sorted
#include <cstddef>
#include <iostream>
#include <random> // for random test data
#include <utility>
#include <vector>

template <class T> void bubble_sort(std::vector<T> &a) {
  if (a.size() <= 1)
    return;
  for (size_t i = 0; i < a.size(); i++) {
    bool swapped = false;
    for (size_t j = 0; j < a.size() - i - 1; j++) {
      if (a[j] > a[j + 1]) {
        std::swap(a[j], a[j + 1]);
        swapped = true;
      }
    }
    if (!swapped) {
      break;
    }
  }
}

// version with comparator
template <typename T,
          typename Compare = std::less<T>> // std::less does less than operation
void bubble_sort_comp(std::vector<T> &a, Compare com = Compare{}) {
  if (a.size() <= 1)
    return;
  for (size_t i = 0; i < a.size(); i++) {
    bool swapped = false;
    for (size_t j = 0; j < a.size() - i - 1; j++) {
      if (com(a[j+1], a[j])) {
        std::swap(a[j], a[j + 1]);
        swapped = true;
      }
    }
    if (!swapped) {
      break;
    }
  }
}

// quick helper print vector
template <typename T>
void print_vector(const std::vector<T> &v, const char *name = "vector") {
  std::cout << name << ": [ ";
  for (size_t i = 0; i < v.size(); i++) {
    std::cout << v[i];
    if (i < v.size() - 1)
      std::cout << ", ";
  }
  std::cout << " ] \n";
}

int main() {
  // test 1 integers
  std::vector<int> numbers = {64, 34, 25, 12, 22, 11, 90, 5};

  std::cout << "Before sorting:\n";
  print_vector(numbers, "numbers");

  bubble_sort(numbers);

  std::cout << "After bubble sort:\n";
  print_vector(numbers, "numbers");

  // descending + comparator
  std::vector<int> desc = {1, 5, 2, 8, 3, 7, 4, 6};

  std::cout << "\nBefore descending sort:\n";
  print_vector(desc, "desc");

  // Using greater<> for descending order
  bubble_sort_comp(desc, std::greater<int>{});

  std::cout << "After descending sort:\n";
  print_vector(desc, "desc");

  // random things
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_real_distribution<> dis(0.0, 100.0);

  std::vector<double> floats(12);
  for (auto &x : floats)
    x = dis(gen);

  print_vector(floats, "floats");

  bubble_sort(floats);

  std::cout << "After sorting:\n";
  print_vector(floats, "floats");

  std::cout << "\nIs sorted? " << std::boolalpha
            << std::is_sorted(floats.begin(), floats.end()) << "\n";

  return 0;
}

#endif // !BUBBLE_SORT_H
