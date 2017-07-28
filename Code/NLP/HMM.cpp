#include <iostream>
#include <vector>
using namespace std;

class model {
public:
    float **A;
    float **B;
    float *n;
    int state_size;
    int behave_size;
    model(int x, int y) : state_size(x), behave_size(y) {
        A = new float* [state_size];
        B = new float* [state_size];
        n = new float[state_size];
        for (int i = 0; i < state_size; i ++) {
            A[i] = new float[state_size];
            B[i] = new float[behave_size];
        }
    }
    void printA() {
        for (int i = 0; i < state_size; i ++) {
            for (int j = 0; j < state_size; j ++) {
                cout << A[i][j] << " ";
            }
            cout << endl;
        }
    }
    void printB() {
        for (int i = 0; i < state_size; i ++) {
            for (int j = 0; j < behave_size; j ++) {
                cout << B[i][j] << " ";
            }
            cout << endl;
        }
    }
    ~model() {
        for (int i = 0; i < state_size; i ++) {
            delete [] A[i];
            delete [] B[i];
        }
        delete [] A;
        delete [] B;
        delete [] n;
    }
};

void forward(int *p, int length, model &u) {
    int size = u.state_size;
    float DP[length][size];
    for (int i = 0; i < size; i ++) {
        DP[0][i] = u.n[i] * u.B[i][p[0]];
    }
    for (int i = 1; i < length; i ++) {
        for (int j = 0; j < size; j ++) {
            DP[i][j] = 0;
            for (int k = 0; k < size; k ++) {
                DP[i][j] += DP[i - 1][k] * u.A[k][j] * u.B[j][p[i]];
            }
        }
    }
    float prob = 0;
    for (int i = 0; i < size; i ++) {
        prob += DP[length - 1][i];
    }
    cout << prob << endl;
}

void back(int *p, int length, model &u) {
    int size = u.state_size;
    float DP[length][size];
    for (int i = 0; i <size; i ++) {
        DP[length - 1][i] = 1;
    }
    cout << DP[length - 1][0] << endl;
    for (int i = length - 2; i >= 0; i --) {
        for (int j = 0; j < size; j ++) {
            DP[i][j] = 0;
            for (int k = 0; k < 3; k ++) {
                DP[i][j] += DP[i + 1][k] * u.A[j][k] * u.B[k][p[i + 1]];
            }
        }
    }
    float prob = 0;
    for (int i = 0; i < size; i ++) {
        prob += DP[0][i] * u.n[i] * u.B[i][p[0]];
    }
    cout << prob << endl;
}

void viterbi(int *p, int length, model &u) {
    int size = u.state_size;
    float DP[length][size];
    for (int i = 0; i < size; i ++) {
        DP[0][i] = n[i] * u.B[i][p[0]];
    }
    for (int i = 1; i < lenght; i ++) {
        for (int j = 0; j < size; j ++) {
            int temp = 0;
            for (int k = 0; k < size; k ++) {
                if (DP[i - 1][k] * u.A[k][j] * u.B[j][p[i]] > temp) {
                    temp = DP[i - 1][k] * u.A[k][j] * u.B[j][p[i]];
                }
            }
            DP[i][j] = temp;
        }
    }
}

void baumWelch(int *p, int length, model &u) {

}

int main() {
    float a[3][3] = {0.5, 0.2, 0.3, 0.3, 0.5, 0.2, 0.2, 0.3, 0.5};
    float b[3][2] = {0.5, 0.5, 0.4, 0.6, 0.7, 0.3};
    float n[3] = {0.2, 0.4, 0.4};
    model model_u(3, 2);
    for (int i = 0; i < 3; i ++) {
        for (int j = 0; j < 3; j ++) {
            model_u.A[i][j] = a[i][j];
        }
    }
    for (int i = 0; i < 3; i ++) {
        for (int j = 0; j < 2; j ++) {
            model_u.B[i][j] = b[i][j];
        }
    }
    model_u.n = n;
    int target[4] = {0, 1, 0, 1};
    back(target, 4, model_u);
    return 0;
}