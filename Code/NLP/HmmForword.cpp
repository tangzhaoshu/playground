#include <iostream>
#include <vector>
#include <string>
using namespace std;

void forward () {
    float a[3][3] = {0.5, 0.2, 0.3, 0.3, 0.5, 0.2, 0.2, 0.3, 0.5};
    float b[3][2] = {0.5, 0.5, 0.4, 0.6, 0.7, 0.3};
    float D[4][3];
    float n[3] = {0.2, 0.4, 0.4};
    vector<int> target = {0, 1, 0, 1};
    for (int i = 0; i < 3; i ++) {
        D[0][i] = n[i] * b[i][target[0]];
    }
    for (int i = 1; i < 4; i ++) {
        for (int j = 0; j < 3; j ++) {
            D[i][j] = 0;
            for (int k = 0; k < 3; k ++) {
                D[i][j] += D[i - 1][k] * a[k][j] * b[j][target[i]]; 
            }
        }
    }
    for (int i = 0; i < 4; i ++) {
        for (int j = 0; j < 3; j ++) {
            cout << D[i][j] << " ";
        }
        cout << endl;
    }
    cout << D[3][0] + D[3][1] + D[3][2] << endl;
    cout << D[5][0] << endl;
}




int main() {
    forward();
    return 0;
}