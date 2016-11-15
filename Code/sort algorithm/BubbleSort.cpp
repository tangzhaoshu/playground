#include<iostream>
#include<vector>

using namespace std;

void BubbleSort(vector<int> &Array, int n) {
    int flag;
    for (int i = 0; i < n; i ++) {
        flag = 1;
        for (int j = 0; j < n - i - 1; j ++) {
            if (Array[j] > Array[j + 1]) {
                int temp = Array[j];
                Array[j] = Array[j + 1];
                Array[j + 1] = temp;
                flag = 0;
            }
        }
        if (flag) {
            break;
        }
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> Array(n);
    for (int i = 0; i < n; i ++) {
        cin >> Array[i];
    }
    BubbleSort(Array, Array.size());
    for (int i = 0; i < Array.size(); i ++) {
        cout << Array[i] << " ";
    }
    cout << endl;
    return 0;
}
