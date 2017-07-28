#include <iostream>
#include <vector>
#include <string>
using namespace std;

void baumWelch(float *behave, int row, int col, float *expression, float *init,
            int *target, int count) {
    float X[count][row][col];
    float R[count][row];
    float a[count][row];
    float b[count][row];
    for (int i = 0; i < row; i ++) {
        a[0][i] = init[i];
        b[count - 1][i] = 1;
    }
    for (int i = 1; i < count; i ++) {
        for (int j = 0; j < col; j ++) {
            a[i][j] = 0;
            for (int k = 0; k < row; k ++) {
                a[i][j] += a[i - 1][k] * behave[k][j] * expression[j][target[i]];
            }
        }
    }
    for (int i = count - 2; i >= 0; i --) {
        for (int j = 0; j < col; j ++) {
            b[i][j] = 0;
            for (int k = 0; k < row; k ++) {
                b[i][j] += b[i + 1][k] * behave[j][k] * expression[k][target[i + 1]];
            }
        }
    }
    float sum;
    for (int t = 0; t < count; t ++) {
        sum = 0;
        for (int i = 0; i < row; i ++) {
           for (int j = 0; j < row; j ++) {
                sum += a[t][i] * behave[i][j] * expression[j][target[t + 1]] * b[t + 1][j];
           }
        }
        for (int i = 0; i < row; i ++) {
            for (int j = 0; j < row; j ++) {
                X[t][i][j] = (a[t][i] * behave[i][j] * expression[j][target[t + 1]] * b[t + 1] j) / sum;
            }
        }
    }
    for (int t = 0; t < count; t ++) {
        for (int i = 0; i < row; i ++) {
            R[t][i] = 0;
            for (int j = 0; j < row; j ++) {
                R[t][i] += X[t][i][j];
            }
        }
    }
}