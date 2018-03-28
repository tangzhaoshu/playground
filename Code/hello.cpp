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

enum class color {
    red,
    yellow,
    green
};

class model {
    public:
        int **p;
        int m_x, m_y;
        model(int x, int y): m_x(x), m_y(y) {
            p = new int* [m_x];
            for (int i =0; i < m_x; i ++) {
                p[i] = new int[m_y];
            }
        }
        ~model() {
            for (int i = 0; i < m_x; i ++) {
                delete [] p[i];
            }
            delete [] p;
        }
};

int main() {
    string ch = "中国北京";
    string en = "china beijing";
    cout << ch.length() << endl;
    cout << en.length() << endl;
    cout << ch.substr(0,3) << endl;
    cout << "分割线" << endl;
    model mod(3, 4);
    for (int i = 0; i < 3; i ++) {
        for (int j = 0; j < 4; j ++) {
            mod.p[i][j] = 10;
        }
    }
    cout << mod.p[1][1] << endl;

    enum weather {Rainy, Sunny};
    weather weat = Rainy;
    float tes[3][2];
    tes[4][0] = 1;
    cout << tes[4][0] << endl;
    cout <<static_cast<float>( 2 ) /static_cast<float>( 3) << endl;
    string str;
    vector<string> vec;
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
