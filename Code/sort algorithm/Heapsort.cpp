#include <iostream>
using namespace std;

class MinHeap {
private:
    int* heapArray;
    int currentSize;
    int MaxSize;
    void swap(int x, int y) {
        int temp = heapArray[x];
        heapArray[x] = heapArray[y];
        heapArray[y] = temp;
    }
public:
    MinHeap(const int n) {
        if (n <= 0) {
            return;
        }
        currentSize = 0;
        MaxSize = n;
        heapArray = new int[MaxSize];
    }
    int LeftChild(int pos) const {
        return 2 * pos + 1;
    }
    int RightChild(int pos) const {
        return 2 * pos + 2;
    }
    int Parent(int pos) const {
        return (pos - 1) / 2;
    }
    void SiftDown(int pos) {
        int start = pos;
        int left = LeftChild(start);
        while(left < currentSize) {
            if (left < currentSize - 1 && heapArray[left] > heapArray[left + 1]) {
                left ++;
            }
            if (heapArray[start] > heapArray[left]) {
                swap(start, left);
                start = left;
                left = LeftChild(start);
            } else {
                break;
            }
        }
    }
    void SiftUp(int pos) {
        int start = pos;
        while (start > 0 && heapArray[start] < heapArray[Parent(start)]) {
            swap(start, Parent(start));
            start = Parent(start);
        }
    }
    void insert (const &newElement) {
        if (currentSize == MaxSize) {
            return;
        }
        heapArray[currentSize] = newElement;
        SiftUp(currentSize);
        currentSize ++;
    }
    void delete(int pos) {
        if (pos < 0 || pos >= currentSize) {
            return;
        }
        heapArray[pos] = heapArray[currentSize --];
        if (heapArray[pos] < heapArray[Parent(pos)]){
            SiftUp(pos);
        } else {
            SiftDown(pos);
        }
    }
}
