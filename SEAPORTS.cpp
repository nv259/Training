#include <cstdio>
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

struct Ship {
    int s, t, port;
} P[100006];

typedef Ship *PShip;


struct cmp {
    bool operator () (PShip A, PShip B) {
        return A->t < B->t;
    }
};

struct Data {
    int x, type;
    PShip cur;

    bool operator < (const Data &other) const {
        if (x != other.x) return x < other.x;
        return type < other.type;
    }
} T[200006];

int n, m;

int main() {
    freopen("SEAPORTS.inp", "r", stdin);
    freopen("SEAPORTS.out", "w", stdout);
    ///
    scanf("%d%d", &m, &n);
    for(int i=1; i<=n; ++i) {
        scanf("%d%d", &P[i].s, &P[i].t);
        T[2*i-1] = {P[i].s, 1, &P[i]};
        T[2*i] = {P[i].t, 0, &P[i]};
    }
    ///
    sort(T+1, T+2*n+1);
    vector<int> S;
    for(int i=m; i>=1; --i) S.push_back(i);
    int res = n;
    priority_queue<PShip, vector<PShip>, cmp> PQ;
    ///
    for(int i=1; i<=2*n; ++i) {
        PShip cur = T[i].cur;
        ///
        if (T[i].type) {
            if (S.empty()) {
                cur->port = 0;
                PQ.push(cur);
                PShip tmp = PQ.top(); PQ.pop();
                cur->port = tmp->port;
                tmp->port = 0;
                --res;
            } else {
                cur->port = S.back();
                S.pop_back();
                PQ.push(cur);
            }
        } else {
            if (cur->port != 0) S.push_back(cur->port);
        }
    }
    ///
    cout << res << "\n";
    for(int i=1; i<=n; ++i) cout << P[i].port << " ";
    return 0;
}