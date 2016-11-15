#include <iostream>
#include <vector>
#include <math.h>
#include <cstring>
#include <limits.h>
using namespace std;

int process1 (const vector<int> &array, int index, int aim) {
    int result = 0;
    if (array.size() == index) {
        result = aim == 0 ? 1 : 0;
    } else {
        for (int i = 0; array[index] * i <= aim; ++ i) {
            result += process1(array, index + 1, aim - array[index] * i);
        }
    }
    return result;
}

int coins1 (const vector<int> &array, const int aim) {
    if (array.size() <= 0 || aim < 0) {
        return 0;
    }
    return process1 (array, 0, aim);
}

int process2 (const vector<int> &array, const int index, int aim, int map[][100]) {
    int result = 0;
    if (index == array.size()) {
        result = aim == 0 ? 1 : 0;
    } else {
        for (int i = 0; array[index] * i <= aim; ++ i) {
            int value = map[index + 1][aim - array[index] * i];
            if (value != 0) {
                result += value == -1 ? 0 : value;
            } else {
                result += process2 (array, index + 1, aim - array[index] * i, map);
            }
        }
    }
    map[index][aim] = result == 0 ? -1 : result;
    return result;
}

int coins2 (const vector<int> &array, const int aim) {
    if (array.size() <= 0 || aim < 0) {
        return 0;
    }
    int map[array.size() + 1][100];
    memset(map, 0, sizeof(map));
    return process2 (array, 0, aim, map);
}

int coins3 (const vector<int> &array, const int aim) {
    if (array.size() <= 0 || aim < 0) {
        return 0;
    }
    int dp[array.size()][aim + 1];
    for (int i = 0; i < array.size(); ++ i) {
        dp[i][0] = 1;
    }
    for (int i = 1; i <= aim; ++ i) {
        dp[0][i] = 
    }
}

int main() {
    vector<int> array = {5, 10, 25, 1};
    cout << coins2(array, 15) << endl;
    return 0;
}
