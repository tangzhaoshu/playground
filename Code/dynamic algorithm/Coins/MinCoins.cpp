#include <iostream>
#include <vector>
#include <limits.h>
#include <math.h>
using namespace std;

int minCoins (const vector<int> &array, const int aim) {
    if (array.size() <= 0 || aim <= 0) {
        return -1;
    }
    int dp[array.size()][aim + 1];
    for (int i = 0; i < array.size(); ++ i) {
        dp[i][0] = 0;
    }
    for (int i = 1; i < aim + 1; ++ i) {
        dp[0][i] = INT_MAX;
        if (i >= array[0] && dp[0][i - array[0]] != INT_MAX) {
            dp[0][i] = dp[0][i - array[0]] + 1;
        }
    }
    for (int i = 1; i < aim + 1; ++ i) {
        for (int j = 1; j < array.size(); ++ j) {
            int cur = INT_MAX;
            if (array[j] <= i && dp[j][i - array[j]] != INT_MAX) {
                cur = dp[j][i - array[j]] + 1;
            }
            dp[j][i] = min(cur, dp[j - 1][i]);
        }
    }
    for (int i = 0; i < array.size(); ++ i) {
        for (int j = 0; j < aim + 1; ++ j) {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    return dp[array.size() - 1][aim];
}

int minCoins2 (const vector<int> &array, int aim) {
    if (array.size() <= 0 || aim < 0) {
        return -1;
    }
    int dp[aim + 1];
    dp[0] = 0;
    for (int i = 1; i < aim + 1; ++ i) {
        dp[i] = INT_MAX;
        if (i >= array[0] && dp[i - array[0]] != INT_MAX) {
            dp[i] = dp[i - array[0]] + 1;
        }
    }
    for (int i = 1; i < array.size(); ++ i) {
        for (int j = 1; j < aim + 1; ++ j) {
            int cur = INT_MAX;
            if (j >= array[i] && dp[j - array[i]] != INT_MAX) {
                cur = dp[j - array[i]] + 1;
            }
            dp[j] = min(cur, dp[j]);
        }
    }
    return dp[aim];
}

int minCoins3 (const vector<int> &array, const int aim) {
    if (array.size() <= 0 || aim < 0) {
        return -1;
    }
    int dp[array.size()][aim + 1];
    for (int i = 0; i < aim + 1; ++ i) {
        dp[0][i] = INT_MAX;
    }
    for (int i = 0; i < array.size(); ++i){
        dp[i][0] = 0;
    }
    if (array[0] <= aim) {
        dp[0][array[0]] = 1;
    }
    for (int i = 1; i < array.size(); ++ i) {
        for (int j = 1; j <= aim; ++ j) {
            int cur = INT_MAX;
            if (array[i] <= j && dp[i - 1][j - array[i]] != INT_MAX) {
                cur = dp[i - 1][j - array[i]] + 1;
            }
            dp[i][j] = min(cur, dp[i - 1][j]);
        }
    }
    for (int i = 0; i < array.size(); ++ i) {
        for (int j = 0; j < aim + 1; ++ j) {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    return dp[array.size() - 1][aim];
}

int main() {
    vector<int> array = {1, 2, 5};
    cout << minCoins3(array, 8) << endl;
    return 0;
}
