#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

void makeNext (const char P[], int Next[]){
    int q, k;
    int m = strlen(P);
    Next[0] = 0;
    for (q = 1, k = 0; q < m; q ++) {
        while (k > 0 && P[q] != P[k]) {
            k = Next[k - 1];
        }
        if (P[q] == P[k]) {
            k ++;
        }
        Next[q] = k;
    }
}

void KMP(char P[], char T[], int Next[]) {
    int q, k;
    int m = strlen(T);
    int n = strlen(P);
    makeNext(P, Next);
    for (int i = 0, k = 0; i < m; i ++) {
        while (k > 0 && T[i] != P[k]) {
            k = Next[k - 1];
        }
        if (P[k] == T[i]) {
            k ++;
        }
        if (k == n){
            cout << "Pattern occurs" << endl;
        }
    }
}

int main () {
    char P[] = "abcabck";
    int Next[10];
    char T[] = "ddababcabckabcabck";
    KMP(P, T, Next);
    for (int i = 0; i < 7; i ++){
        cout << Next[i] << " ";
    }
    cout << endl;
}
