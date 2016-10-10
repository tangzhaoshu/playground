#include <iostream>
#include <vector>
#include <limits.h>
#include <string>
#include <sstream>
#include <queue>
using namespace std;
  /* code */
int main() {
    cout << INT_MAX << endl;
    stringstream ss;
    ss << INT_MAX;
    cout << ss.str() + "hello" << endl;
    cout << "hello" << endl;
    priority_queue<int, vector<int>, greater<int> > que;
    int n, input;
    cin >> n;
    for (int i = 0; i < n; i ++) {
        cin >> input;
        que.push(input);
    }
    while(!que.empty()) {
        cout << que.top() << " ";
        que.pop();
    }
    cout << endl;
    return 0;
}
