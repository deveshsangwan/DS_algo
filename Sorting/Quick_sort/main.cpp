#include <iostream>

using namespace std;

void swap(int* a, int* b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

int Partition(int a[], int low, int high)
{
    int pivot, index, i;
    index = low;
    pivot = high;

    for(i = low; i < high; i++) {
        if(a[i] < a[pivot]) {
            swap(&a[i], &a[index]);
            index++;
        }
    }

    swap(&a[pivot], &a[index]);

    return index;
}
int QuickSort(int a[], int low, int high)
{
    int pindex = high;
    if(low < high) {
        int pindex = Partition(a, low, high);
        
        QuickSort(a, low, pindex - 1);
        QuickSort(a, pindex + 1, high);
    }
    return 0;
}
int main()
{
    int n, i;
    cin >> n;

    int arr[n];
    for(i = 0; i < n; i++) {
        cin >> arr[i];
    }

    QuickSort(arr, 0, n - 1);
    cout << "After Sorting: ";
    for(i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
    return 0;
}
