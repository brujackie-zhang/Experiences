#include<iostream>
using namespace std;

void quickSort(int arr[], int left, int right)
{
    int i = left;
    int j = right;
    int k = arr[left];
    while (i < j) {
        while (i < j && arr[j] >= k) {
            j--;
        }
        arr[i] = arr[j];
        while (i < j && arr[i] <= k) {
            i++;
        }
        arr[j] = arr[i];
    }
    arr[i] = k;
    quickSort(arr, left, i - 1);
    quickSort(arr, i + 1, right);
}
int main()
{
    int arr[10] = {213,12,1,154,478,954,21,36,8,15};
    quickSort(arr, 0, 10);
    for (int i =0; i < 10; i ++) {
        cout<<arr[i]<<" ";
    }
    return 0;
}
