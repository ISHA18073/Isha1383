#include <bits/stdc++.h>
using namespace std;
int cnt = 0;
int Partition(int arr[], int low, int high)
{
int pivot = arr[high];
int i = (low - 1);
for (int j = low; j <= high - 1; j++)
{
if (arr[j] <= pivot)
{
i++;
swap(arr[i], arr[j]);
cnt++;
}
}
swap(arr[i + 1], arr[high]);
cnt++;
return (i + 1);
}
int partitionRandom(int arr[], int low, int high)
{
srand(time(NULL));
int random = low + rand() % (high - low);
swap(arr[random], arr[high]);
cnt++;
return Partition(arr, low, high);
}
void quickSort(int arr[], int low, int high)
{
if (low < high)
{
int pi = partitionRandom(arr, low, high);
quickSort(arr, low, pi - 1);
quickSort(arr, pi + 1, high);
}
}
int main()
{
    int size;
int Array[] = {9, 14, 4, 6, 5, 8, 7,2,1};
size = sizeof(Array) / sizeof(int);
    quickSort(Array, 0, size - 1);
for(int i=0;i<size;i++){
    cout<<Array[i]<<" ";
    }
    cout<<endl;
cout << size << "," << cnt << endl;
return 0;
}
