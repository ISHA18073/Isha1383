#include <iostream>
using namespace std;

void printArray(int * arr, int length) {
    for (int i = 0; i < length; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int merge(int * arr, int low, int mid, int high) {
    int i, j, k;
    int count=0;
    int lengthLeft = mid - low + 1;
    int lengthRight = high - mid;

    int arrLeft[lengthLeft], arrRight[lengthRight];

    for (int a = 0; a < lengthLeft; a++) {
        arrLeft[a] = arr[low + a];
    }
    for (int a = 0; a < lengthRight; a++) {
        arrRight[a] = arr[mid + 1 + a];
    }
    i = 0;
    j = 0;
    k = low;

    while (i < lengthLeft && j < lengthRight) {
            count=count+1;
        if (arrLeft[i] <= arrRight[j]) {
            arr[k] = arrLeft[i];
            i++;
        } else {
            arr[k] = arrRight[j];
            j++;
        }
        k++;
    }
    while (i < lengthLeft) {
        arr[k] = arrLeft[i];
        k++;
        i++;
    }
    while (j < lengthRight) {
        arr[k] = arrRight[j];
        k++;
        j++;
    }
    return count;
}

int mergeSort(int * arr, int low, int high) {
    int mid;
    int count=0;
    if (low < high) {
        mid = (low + high) / 2;

        count+=mergeSort(arr, low, mid);
        count+=mergeSort(arr, mid + 1, high);
        count+=merge(arr, low, mid, high);
    }
    return count;
}

int main() {
    int arr[] = {9, 14, 4, 6, 5, 8, 7};
    int length = sizeof(arr) / sizeof(int);
    cout << "Array, before calling the mergeSort() : ";
    printArray(arr, length);

    int p=mergeSort(arr, 0, length - 1);
    cout << "Array, after calling the mergeSort() : ";
    printArray(arr, length);
    cout<<"Total number of comparision"<<p;

    return 0;
}
