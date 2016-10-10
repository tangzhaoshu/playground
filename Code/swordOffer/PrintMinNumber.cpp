#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

bool operator < (const string str1, const string str2) {
    if (str1.size() == 0 && str2.size() > 0) {
        return true;
    }
    if (str1.size() > 0 && str2.size() == 0) {
        return false;
    }
    int i = 0;
    while (i < str1.size() && i < str2.size()) {
        if (str1[i] < str2[i]) {
            return true;
        } else if (str1[i] > str2[i]) {
            return false;
        } else {
            i ++;
        }
    }
    if (str1.size() < str2.size()) {
        if (str2[i] < str1[0]) {
            return false;
        } else {
            return true;
        }
    } else if (str1.size() > str2.size()){
        if (str1[i] < str2[0]) {
            return true;
        } else {
            return false;
        }
    }
    return false;
}

void PrintMinNumber (int *numbers, int length) {
    if (numbers == NULL || length <= 0) {
        return;
    }
    vector<string> strNumbers;
    string temp;
    stringstream ss;
    for (int i = 0; i < length; i ++) {
        ss << numbers[i];
        strNumbers.push_back(ss.str());
        ss.str("");
    }
    for (int i = 0; i < length; i ++) {
        for (int j = 0; j < length - i - 1; j ++) {
            if (strNumbers[j + 1] < strNumbers[j]) {
                temp = strNumbers[j];
                strNumbers[j] = strNumbers[j + 1];
                strNumbers[j + 1] = temp;
            }
        }
    }
    for (int i = 0; i < length; i ++) {
        cout << strNumbers[i];
    }
    cout << endl;
}

int main() {
    int numbers[] = {3, 321, 32, 4, 1, 33};
    PrintMinNumber(numbers, 6);
    return 0;
}
