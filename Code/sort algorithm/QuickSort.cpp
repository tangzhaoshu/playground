#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
using namespace std;

void swap (int Array[], int a, int b) {
    int temp;
    temp = Array[a];
    Array[a] = Array[b];
    Array[b] = temp;
}

int Partition (int Array[], int left, int right) {
    int l = left;
    int r = right;
    int temp = Array[r];
    while (l != r) {
        while (Array[l] <= temp && r > l) {
            l ++;
        }
        if (l < r) {
            Array[r] = Array [l];
            r --;
        }
        while (Array[r] >= temp && r > l) {
            r--;
        }
        if (l < r) {
            Array[l] = Array[r];
            l ++;
        }
    }
    Array[l] = temp;
    return l;
}

void QuickSort (int Array[], int left, int right) {
    if (right <= left) {
        return;
    }
    int pivot = (left + right) / 2;
    swap(Array, pivot, right);
    pivot = Partition (Array, left, right);
    QuickSort(Array, left, pivot - 1);
    QuickSort(Array, pivot + 1, right);
}

int main () {
    int Array[] = {2,3,1,4,6,5};
    for (int i = 0; i < 5; i ++) {
        cout << Array[i] << " ";
    }
    cout <<endl;
    QuickSort(Array, 0, 5);
    for (int i = 0; i < 5; i ++) {
        cout << Array[i] << " " ;
    }
    cout << endl;
    return 0;
}
