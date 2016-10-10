#include <iostream>
#include <limits.h>
#include <queue>
using namespace std;

class Dist {
public:
    int index;
    int length;
    int pre;
};
const int MAXNUM = 10;
int dist[MAXNUM];
int prev[MAXNUM];
int A[MAXNUM][MAXNUM];

void Dijkstra(int resource) {
    bool S[MAXNUM];
    int n = MAXNUM;
    for (int i = 1; i <= n; i ++) {
        dist[i] = A[resource][i];
        S[i] = false;
        if(dist[i] == INT_MAX) {
            prev[i] = -1;
        } else {
            prev[i] = resource;
        }
    }
    dist[resource] = 0;
    S[resource] = true;
    for (int i = 2; i <= n; i ++) {
        int next = resource;
        int min = INT_MAX;
        for (int j = 1; i <= n; j ++) {
            if (dist[j] != 0 && dist[j] < min) {
                next = j;
                min = dist[j];
            }
        }
        S[next] = true;
        for (int j = 1; j <= n; j ++) {
            if (S[j] == 0 && A[next][j] < INT_MAX) {
                if (A[next][j] + dist[next] < dist[j]) {
                    dist[j] = A[next][j] + dist[next];
                    prev[j] = next;
                }
            }
        }
    }
}

void searchPath(int pos, int resource) {
    int path[MAXNUM];
    queue<int> que;
    while (prev[pos] != resource) {
        que.push(prev[pos]);
        pos = prev[pos];
    }
    que.push(resource);
    while (!que.empty()) {
        int temp = que.front();
        cout << temp << "-->>";
        que.pop();
    }
    cout << pos << endl;
}

int main() {
    int n, line;
    cin >> n;
    cin >> line;
    int p, q, len;
    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= n; j ++) {
            A[i][j] = INT_MAX;
        }
    }
    for (int i = 0; i < line; i ++) {
        cin >> p >> q >> len;
        if (len < A[p][q]) {
            A[p][q] = len;
            A[q][p] = len;
        }
    }
    for (int i = 1; i <= n; i ++) {
        dist[i] = INT_MAX;
    }
    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= n; j++) {
            if (A[i][j] == INT_MAX) {
                cout << "&" << " ";
            } else {
                cout << A[i][j] << " ";
            }
        }
        cout << endl;
    }
    Dijkstra(1);
    int pos;
    cin >> pos;
    searchPath(pos, 1);
    return 0;
}
