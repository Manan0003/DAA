#include <iostream>
using namespace std;

int split(int arr[], int first, int last) {
    int key = arr[last];   
    int p = first - 1;

    for (int j = first; j < last; j++) {
        if (arr[j] <= key) {
            p++;
            swap(arr[p], arr[j]);
        }
    }

    swap(arr[p + 1], arr[last]);
    return p + 1;
}


void quickSort(int arr[], int start, int finish) {
    if (start < finish) {
        int l = split(arr, start, finish);

        quickSort(arr, start, l - 1);
        quickSort(arr, l + 1, finish);
    }
}

int main() {
    int size;
    cout << "Enter number of elements: ";
    cin >> size;

    int arr[size];
    cout << "Enter elements:\n";
    for (int idx = 0; idx < size; idx++)
        cin >> arr[idx];

    quickSort(arr, 0, size - 1);

    cout << "Sorted array:\n";
    for (int idx = 0; idx < size; idx++)
        cout << arr[idx] << " ";

    return 0;
}
