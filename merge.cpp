#include <iostream>
using namespace std;


void combine(int data[], int start, int middle, int end) {
    int size1 = middle - start + 1;
    int size2 = end - middle;

    int leftArr[size1], rightArr[size2];


    for (int x = 0; x < size1; x++)
        leftArr[x] = data[start + x];

    for (int y = 0; y < size2; y++)
        rightArr[y] = data[middle + 1 + y];

    int i = 0, j = 0, index = start;

    while (i < size1 && j < size2) {
        if (leftArr[i] <= rightArr[j]) {
            data[index] = leftArr[i];
            i++;
        } else {
            data[index] = rightArr[j];
            j++;
        }
        index++;
    }

   
    while (i < size1) {
        data[index] = leftArr[i];
        i++;
        index++;
    }

    while (j < size2) {
        data[index] = rightArr[j];
        j++;
        index++;
    }
}


void divideSort(int data[], int low, int high) {
    if (low < high) {
        int midPoint = low + (high - low) / 2;

        divideSort(data, low, midPoint);
        divideSort(data, midPoint + 1, high);

        combine(data, low, midPoint, high);
    }
}

int main() {
    int count;
    cout << "Enter number of elements: ";
    cin >> count;

    int data[count];
    cout << "Enter elements:\n";
    for (int k = 0; k < count; k++)
        cin >> data[k];

    divideSort(data, 0, count - 1);

    cout << "Sorted array:\n";
    for (int k = 0; k < count; k++)
        cout << data[k] << " ";

    return 0;
}
