#include <iostream>
#include <algorithm>
#include <climits>
#include <vector>
#define _pos(x, y) ((x-1)*n+y)

using namespace std;

vector<int> r[1000002];
int n, m, min_val = INT_MAX, max_val = INT_MIN, num=0, res = 1;
int father[1000002], p[1000002];
bool avail[1000007];

int findset(int i) {
    if (father[i] != i ) father[i] = findset(father[i]);
    return father[i];
}

bool Union(int x, int y) {
    int u,v;
    u = findset(x);
    v = findset(y);
    if (u==v) return false;
    if (p[u]==p[v]) p[u]++;
    if (p[u]>p[v]) father[v]=u; else father[u]=v;
    return true;
}

void solve(int first, int second) {
    if (second > 0 && second <= n*m && avail[second])
    if (Union(first, second)) num--;
}

void process() {
    for(int i=max_val; i>=min_val; i--) {
        for(int v: r[i]) {
            num++;
            solve(v, v-n);
            solve(v, v+n);
            if(v%n != 1) solve(v, v-1);
            if(v%n) solve(v, v+1);
            avail[v]=true;
        }
        res = max(res, num);
    }
    cout << res;
    //cerr << res;
}

template<typename T>
bool fast_scan(T &num) {
    num = 0;
    register char c = getchar();
    while (c != '-' && (c < '0' || '9' < c)) {
        if (feof(stdin)) return false;
        c = getchar();
    }
    bool neg = false;
    if (c == '-') {
        neg = true;
        c = getchar();
    }
    for(; '0' <= c && c <= '9'; c = getchar()) num = (num << 1) + (num << 3) + (c - '0');
    if (neg) num = -num;
    return true;
}

void enter() {
    fast_scan(m), fast_scan(n); int x;
    for(int i=1; i<=m; i++)
    for(int j=1; j<=n; j++) {
        fast_scan(x);
        r[x].push_back(_pos(i, j));
        min_val=min(x, min_val);
        max_val=max(max_val, x);
        father[_pos(i, j)]=_pos(i, j);
    }
}

int main() {
    freopen("islands.inp", "r", stdin);
    freopen("islands.out", "w", stdout);

    enter();
    process();

    return 0;
}
