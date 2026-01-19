#ifndef QUICK_SORT_H
#define QUICK_SORT_H

#include <iostream>
#include <utility>
#include <vector>

template<typename T> int partition(std::vector<T> &arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for(int j = low; j <= high - 1; j++){
        if(arr[j] < pivot){
            i++;
            std::swap(arr[i], arr[j]);
        }
    }
    std::swap(arr[i+1], arr[high]);
    return i + 1;
}

template<typename T> void quickSort(std::vector<T> &arr, int low, int high){
    if(low < high){
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1,  high);
    }
}

int main() {
    std::vector<int> arr = {10, 7, 8, 9, 1, 5};
        int n = arr.size();
        quickSort(arr, 0, n - 1);

        for (int i = 0; i < n; i++) {
            std::cout << arr[i] << " ";
        }
        return 0;
}
#endif // !QUICK_SORT_H
