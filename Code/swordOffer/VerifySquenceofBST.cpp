#include <iostream>
using namespace std;

bool VerifySquenceofBST(int sequence[], int length) {
    if (sequence == NULL || length <= 0) {
        return false;
    }
    int root = sequence[length - 1];
    int i = 0;
    for (; i < length; i ++) {
        if (sequence[i] > root) {
            break;
        }
    }
    for (int j = i; j < length; j ++) {
        if (sequence[j] < root) {
            return false;
        }
    }
    bool left = true;
    if (i > 0) {
        left = VerifySquenceofBST(sequence, i);
    }
    bool right = true;
    if (i < length - 1) {
        right = VerifySquenceofBST(sequence + i, length - i - 1);
    }
    return (left && right);
}
