#include <iostream>
using namespace std;

void PrintMatrixClockwisely(int** numbers, int cols, int rows) {
    if (numbers == NULL || cols <= 0 || rows <= 0) {
        return;
    }
    int start = 0;
    while (cols > start * 2 && rows > start * 2) {
        PrintMatrix(numbers, cols, rows, start);
        start ++;
    }

}

void PrintMatrix (int** numbers, int cols, int rows, int start) {
    int endX = cols - 1 - start;
    int endY = rows - 1 - start;
    for (int i = start; i < endX; i ++) {
        cout << numbers[start][i] << " ";
    }
    if (start < endY) {
        for (int i = start + 1; i < endY; i ++) {
            cout << numbers[i][endX] << " ";
        }
    }
    if (start < endY && start < endX) {
        for (int i = endX - 1; i >= start; i --) {
            cout << numbers[endY][i] << " ";
        }
    }
    if (start < endY - 1 && start < endX) {
        for (int i = endY - 1; i > start; i --) {
            cout << numbers[i][start] << " ";
        }
    }
}
