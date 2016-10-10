#include <iostream>
#include <vector>
using namespace std;

void Merge(int Array[], int TempArray[], int left, int right, int middle) {
    int i, j, index1, index2;
    for (j = left; j <= right; j ++) {
        TempArray[j] = Array[j];
    }
    index1 = left;
    index2 = middle + 1;
    i = left;
    while (index1 <= middle && index2 <= right) {
        if (TempArray[index1] <= TempArray[index2]) {
            Array[i ++] = TempArray[index1 ++];
        } else {
            Array[i ++] = TempArray[index2 ++];
        }
    }
    while (index1 <= middle) {
        Array[i ++] = TempArray[index1 ++];
    }
    while (index2 <= right) {
        Array[i ++] = TempArray[index2 ++];
    }
}

void MergeSort(int Array[], int TempArray[], int left, int right) {
    int middle;
    if (left < right) {
        middle = (left + right) / 2;
        MergeSort(Array, TempArray, left, middle);
        MergeSort(Array, TempArray, middle + 1, right);
        Merge(Array, TempArray, left, right, middle);
    }
}

void printArray(int Array[], int length) {
    for (int i = 0; i < length; i ++) {
        cout << Array[i] << " ";
    }
    cout << endl;
}

int main() {
    int Array[] = {3, 4, 2, 6, 8, 7};
    int TempArray[10];
    printArray(Array, 6);
    MergeSort(Array, TempArray, 0, 5);
    printArray(Array, 6);
    return 0;
}
