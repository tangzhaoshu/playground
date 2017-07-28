#include <iostream>
#include <string>
#include <vector>
#include <limits.h>
#include <sstream>
#include <typeinfo>

using namespace std;

long bigram(vector<string> str, string str1, string str2) {
    string s, word;
    int total = 0;
    int target = 0;
    int pos_h = 0;
    int pos_e = 0;
    int flag = 0;
    for (auto iter = str.begin(); iter != str.end(); iter ++) {
        s = *iter;
        for (pos_e = 0, pos_h = 0; pos_e < s.length(); pos_e ++) {
            if (s[pos_e] == ' ' && pos_e == pos_h) {
                pos_h ++;
            } else {
                if (s[pos_e] == ' ') {
                    word = s.substr(pos_h, pos_e - pos_h);
                    pos_h = pos_e + 1;
                    if (word == str2 && flag == 1) {
                        target ++;
                        flag = 0;
                    }
                    if (word == str1) {
                        total ++;
                        flag = 1;
                    }
                } else if (pos_e + 1 == s.length() && pos_h != pos_e) {
                    word = s.substr(pos_h, pos_e + 1 - pos_h);
                    if (word == str2 && flag == 1) {
                        target ++;
                        flag = 0;
                    }
                    if (word == str1) {
                        total ++;
                        cout << pos_h << " " << pos_e << endl;
                        flag = 1;
                    }
                }
            }
        }
    }
    cout << target << "  " << total << endl;
    return (long) target / total;
}

void trigram (vector<string> str, string str1, string str2, string str3) {
    int total = 0;
    int target = 0;
    int pos_h, pos_e;
    string s, word, temp;
    int flag = 0;
    for (auto iter = str.begin(); iter != str.end(); iter ++) {
        s  = *iter;
        cout << s << endl;
        for (pos_h = 0, pos_e = 0; pos_e < s.length(); pos_e ++) {
            if (s[pos_e] == ' ' && pos_e == pos_h) {
                pos_h ++ ;
            } else {
                if (s[pos_e] == ' ') {
                    word = s.substr(pos_h, pos_e - pos_h);
                    cout << word << endl;
                    pos_h = pos_e + 1;
                    if (flag == 0 && word == str1) {
                        flag = 1;
                        temp = word;
                    } else if (flag == 1 && word == str2) {
                        flag = 2;
                        temp = word;
                        total ++;
                    } else if (flag == 1 && word != str2) {
                        flag = 0;
                        if (word == str1) {
                            flag = 1;
                            temp = word;
                        }
                    } else if (flag == 2) {
                        if (word == str3) {
                            flag = 0;
                            target ++;
                        }
                        if (temp == str1 && word == str2) {
                            flag = 2;
                            temp = word;
                            total ++;
                        } else if (word == str1) {
                            flag = 1;
                            temp = word;
                        }
                    }
                } else if (pos_e + 1 == s.length() && pos_h != pos_e) {
                    word = s.substr(pos_h, pos_e - pos_h + 1);
                    cout << word << endl;
                    pos_h = pos_e + 1;
                    if (flag == 0 && word == str1) {
                        flag = 1;
                        temp = word;
                    } else if (flag == 1 && word == str2) {
                        flag = 2;
                        temp = word;
                        total ++;
                    } else if (flag == 1 && word != str2) {
                        flag = 0;
                        if (word == str1) {
                            flag = 1;
                            temp = word;
                        }
                    } else if (flag == 2) {
                        if (word == str3) {
                            flag = 0;
                            target ++;
                        }
                        if (temp == str1 && word == str2) {
                            flag = 2;
                            temp = word;
                            total ++;
                        } else if (word == str1) {
                            flag = 1;
                            temp = word;
                        }
                    }
                }
            }
        }
    }
    cout << target << "  " << total << endl;
    cout << static_cast<float>(target) / static_cast<float>(total) << endl;
}

int main(){
    vector<string> str;
    string input1, input2;
    getline(cin, input1);
    str.push_back(input1);
    string str1, str2, str3;
    cout << "input str1 and str2" << endl;
    cin >> str1 >> str2 >> str3;
    trigram(str, str1, str2, str3);
    return 0;
}
