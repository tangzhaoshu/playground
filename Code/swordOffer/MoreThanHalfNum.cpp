#include <iostream>
#include <vector>
using namespace std;

int Partition (int* number, int length, int start, int end) {
    int temp = number[end];
    while (start < end) {
        while (start < end && number[start] < temp) {
            start ++;
        }
        if (start < end) {
            number[end] = number[start];
            end --;
        }
        while (start < end && number[end] > temp) {
            end --;
        }
        if (start < end) {
            number[start] = number[end];
            start ++;
        }
    }
    number[start] = temp;
    return start;
}


bool Checkout(int* number, int length, int temp) {
    int count = 0;
    for (int i = 0; i < length; i ++) {
        if (number[i] == temp) {
            count ++;
        }
    }
    if (count * 2 > length) {
        return true;
    }
    return false;
}

int MoreThanHalfNum(int* number, int length) {
    if (number == NULL || length <= 0) {
        return 0;
    }
    int middle = length >> 1;
    int start = 0;
    int end = length - 1;
    int index = Partition(number, length, start, end);
    while (index != middle) {
        if(index > middle) {
            end = index - 1;
            index = Partition(number, length, start, end);
        } else {
            start = index + 1;
            index = Partition(number, length, start, end);
        }
    }
    int result = number[index];
    if (Checkout(number, length, result)) {
        return result;
    }
    return 0;
}

int MoreThanHalfNum2(int* numbers, int length) {
    if (numbers == NULL || length <= 0) {
        return 0;
    }
    int result = numbers[0];
    int count = 1;
    for (int i = 1; i < length; i ++) {
        if (count == 0) {
            result = numbers[i];
            count ++;
        } else {
            if (numbers[i] == result) {
                count ++;
            } else {
                count --;
            }
        }
    }
    if (Checkout(numbers, length, result)) {
        return result;
    }
    return 0;
}

int main() {
    int numbers[] = {1, 3, 3, 3, 3, 2, 2};
    cout << MoreThanHalfNum(numbers, 7);
    cout << endl;
    cout << MoreThanHalfNum2(numbers, 7) << endl;
    return 0;
}
