#include <iostream>
#include <vector>
#include <string> 
using namespace std;

void viterbi() {
    float A[3][3] = {0.5, 0.2, 0.3, 0.3, 0.5, 0.2, 0.2, 0.3, 0.5};
    float B[3][2] = {0.5, 0.5, 0.4, 0.6, 0.7, 0.3};
    float n[3] = {0.2, 0.4, 0.4};
    float F[4][3];
    int path[3][3];
    float max, temp;
    int res[4];
    int pos;
    int target[4] = {0, 1, 0, 1};
    for (int i = 0; i < 3; i ++) {
        F[0][i] = n[i] * B[i][target[0]];
    }
    for (int i = 1; i < 4; i ++) {
        for (int j = 0; j < 3; j ++) {
            max = 0;
            for (int k = 0; k < 3; k ++) {
                temp = F[i - 1][k] * A[k][j] * B[j][target[i]];
                if (temp > max) {
                    max = temp;
                    pos = k;
                }
            }
            path[i - 1][j] = pos;
            F[i][j] = max;
        }
    }
    for (int i = 0; i < 4; i ++) {
        for (int j = 0; j < 3; j ++) {
            cout << F[i][j] << "  ";
        }
        cout << endl;
    }
    pos = 0;
    for (int i = 1; i < 3; i ++) {
        if (F[3][i] > F[3][pos]) {
            pos = i;
        }
    }

    cout << F[3][pos] << endl;
    res[3] = pos + 1;
    res[2] = path[2][pos] + 1;
    res[1] = path[1][path[2][pos]] + 1;
    res[0] = path[0][path[1][path[2][pos]]] + 1;
    for (int i = 0; i < 4; i ++) {
        cout << res[i] << "  ";
    }
    cout << endl;
}

enum weather {Rainy, Sunny, Cloudy};
enum behave {Shopping, Walking, Clearing};
float action[3][3] = {};
float wea[3][3] = {};
void weatherExample () {

}


int main() {
    viterbi();
    return 0;
}