#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#define llong long long

using namespace std;

vector<int> V[100006];
int n, m, num_cc, connect[100006], nChild[100006];
bool avail[100006];
int lab[100006], low[100006], num[100006];

void enter() {
    scanf("%d%d", &n, &m);
    for(int i=1; i<=m; ++i) {
        int u, v; scanf("%d%d", &u, &v);
        V[u].push_back(v);
        V[v].push_back(u);
    }
}

void DFS(int u) {
    ++connect[num_cc];
    avail[u] = true;

    for(int v: V[u])
    if (!avail[v]) DFS(v);
}

void Connect() {
    for(int i=1; i<=n; ++i)
    if (!avail[i]) {
        ++num_cc;
        DFS(i);
    }
}

void DFS_2(int u) {
    low[u] = 1e9, num[u] = ++num[0]; nChild[u] = 1;

    for(int v: V[u])
    if (v != lab[u]) {
        if (num[v] > 0) low[u] = min(low[u], num[v]);
        else {
            lab[v] = u;
            DFS_2(v);
            nChild[u] += nChild[v];
            low[u] = min(low[u], low[v]);
        }
    }
}

void process() {
    Connect();
    if (num_cc > 2) cout << 0;
    else {
        llong res = 0;

        for(int u=1; u<=n; ++u)
        if (!num[u]) DFS_2(u);

        int bridges = 0;
        for(int v=1; v<=n; ++v) {
            int u = lab[v];
            if (u == 0) continue;

            if (low[v] >= num[v]) {
                ++bridges;
                if (num_cc == 1)
                    res += 1LL * nChild[v] * (1LL * n - nChild[v]) - 1;
            }
        }

        if (num_cc == 1) res += (1LL * m - bridges) * (1LL * n * (n - 1) / 2 - m);
        else res = (1LL * m - bridges) * (1LL * connect[1] * connect[2]);

        cout << res;
    }
}

int main() {
    freopen("REFORM.inp", "r", stdin);
    freopen("REFORM.out", "w", stdout);

    enter();
    process();

    return 0;
}
