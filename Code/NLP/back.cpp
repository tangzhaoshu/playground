#include <iostream>
#include <vector>
using namespace std;

void back() {
    float a[3][3] = {0.5, 0.2, 0.3, 0.3, 0.5, 0.2, 0.2, 0.3, 0.5};
    float b[3][2] = {0.5, 0.5, 0.4, 0.6, 0.7, 0.3};
    float Dp[4][3];
    float n[3] = {0.2, 0.4, 0.4};
    int target[4] = {0, 1, 0, 1};
    for (int i = 0; i < 3; i ++) {
        Dp[3][i] = 1;
    }
    for (int i = 2; i >= 0; i --) {
        for (int j = 0; j < 3; j ++) {
            Dp[i][j] = 0;
            for (int k = 0; k < 3; k ++) {
                Dp[i][j] += Dp[i + 1][k] * a[j][k] * b[k][target[i + 1]];
            }
        }
    }
    for (int i = 0; i < 4; i ++) {
        for (int j = 0; j < 3; j ++) {
            cout << Dp[i][j] << " ";
        }
        cout << endl;
    }
    float res = 0;
    for (int i = 0; i < 3; i ++) {
        res += Dp[0][i] * n[i] * b[i][target[0]];
    }
    cout << res << endl;
}

int main() {
    back();
    return 0;
}