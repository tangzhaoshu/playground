#include <iostream>
#include <vector>
#include <limits.h>
#include <string>
#include <sstream>
#include <queue>
#include <typeinfo>

using namespace std;
  /* code */

int function(int a, int b) {
    char *c;
    c = (char *) a;
    return (int) &c[b];
}

int main() {
    short s = 2;
    float f = 1.0f;
    double d = 2;
    int i = 42;
    cout << typeid(s).name() << endl;
    cout << typeid(f).name() << endl;
    cout << typeid(i).name() << endl;
    cout << typeid(d).name() << endl;
    int &r = i;
    int &&rr = i * 2;
    cout << r << endl;
    cout << rr << endl;
    cout << function(10, 4) << endl;
    cout << INT_MAX << endl;
    stringstream ss;
    ss.str("111");
    int a;
    ss >> a;
    cout << a << endl;
    ss << INT_MAX;
    cout << ss.str() + "hello" << endl;
    cout << "hello" << endl;
    priority_queue<int, vector<int>, greater<int> > que;
    int n, input;

    cout << endl;
    return 0;
}
