#include <iostream>
#include <vector>
#include <algorithm>

void countingSort(std::vector<int>& arr, int exp)
{
    std::vector<int> output(arr.size());
    std::vector<int> count(10, 0);

    for (int i = 0; i < arr.size(); i++) {
        count[(arr[i] / exp) % 10]++;
    }

    for (int i = 1; i < count.size(); i++) {
        count[i] += count[i - 1];
    }

    for (int i = arr.size() - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    for (int i = 0; i < arr.size(); i++) {
        arr[i] = output[i];
    }
}

void radixSort(std::vector<int>& arr)
{
    int max_element = *std::max_element(arr.begin(), arr.end());

    for (int exp = 1; max_element / exp > 0; exp *= 10) {
        countingSort(arr, exp);
    }
}

int main()
{
    std::vector<int> arr = { 170, 45, 75, 90, 802, 24, 2, 66 };

    radixSort(arr);

    for (auto& elem : arr) {
        std::cout << elem << " ";
    }

    return 0;
}
