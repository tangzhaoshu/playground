#include <iostream>
using namespace std;

int InversePairsCore(int* data, int* copy, int start, int end) {
    if (start == end) {
        copy[start] = data[start];
        return 0;
    }
    int mid = (end - start) / 2;
    int left = InversePairsCore(copy, data, start, start + mid);
    int right = InversePairsCore(copy, data, start + mid + 1, end);
    int i = start + mid;
    int j = end;
    int indexcopy = end;
    int count = 0;
    while (i >= start && j >= start + mid + 1) {
        if (data[i] > data[j]) {
            copy[indexcopy --] = data[i --];
            count += j - start - mid;
        } else {
            copy[indexcopy --] = data[j --];
        }
    }
    for (; i >= start; i --) {
        copy[indexcopy --] = data[i];
    }
    for (; j >= start + mid + 1; j --) {
        copy[indexcopy --] = data[j];
    }
    return left + right + count;
}

int InversePairs(int* data, int length) {
    if (data == NULL || length <= 0) {
        return 0;
    }
    int* copy = new int[length];
    for (int i = 0; i < length; i ++) {
        copy[i] = data[i];
    }
    int count = InversePairsCore(data, copy, 0, length - 1);
    delete[] copy;
    return count;
}

int main() {
    int numbers[] = {7, 5, 6, 4};
    cout << InversePairs(numbers, 4) << endl;
    return 0;
}
