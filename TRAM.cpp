#include    <bits/stdc++.h>
#define file_name "TRAM"

using namespace std;
//////////////////////////
const   int N = 1e5+5;

int n, m;
int depth[100006], pos[100006], cnt[100006];
int nChild[100006], lab[100006], chain[100006];
vector<int> V[100006];

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

void DFS(int u) {
    nChild[u] = 1;
    int max_pos = -1;

    for(int i=0; i<(int) V[u].size(); ++i) {
        int v = V[u][i];
        if (v == lab[u]) continue;

        lab[v] = u;
        depth[v] = depth[u]+1;
        DFS(v);
        nChild[u] += nChild[v];

        if (max_pos == -1 || nChild[V[u][max_pos]] < nChild[v]) max_pos = i;
    }

    if (max_pos != -1) swap(V[u][max_pos], V[u][0]);
}

void HLD(int u, int c) {
    chain[u] = c; pos[u] = pos[0]++;

    if (lab[u] == V[u][0]) return;
    HLD(V[u][0], c);

    for(int i=1; i<(int) V[u].size(); ++i) {
        int v = V[u][i];
        if (v != lab[u]) HLD(v, v);
    }
}

int main() {
    freopen(file_name".INP", "r", stdin);
    freopen(file_name".OUT", "w", stdout);

    fast_scan(n);
    for(int i=1; i<n; ++i) {
        int u, v; fast_scan(u), fast_scan(v);
        V[u].push_back(v);
        V[v].push_back(u);
    }

    DFS(1);
    HLD(1, 1);

    fast_scan(m);
    while (m--) {
        int s, t; fast_scan(s), fast_scan(t);

        while (chain[s] != chain[t]) {
            if (depth[chain[s]] < depth[chain[t]]) swap(s, t);
            ++cnt[pos[chain[s]]]; --cnt[pos[s]+1];
            s = lab[chain[s]];
        }

        if (depth[s] < depth[t]) swap(s, t);
        ++cnt[pos[t]+1], --cnt[pos[s]+1];
    }

    for(int i=1; i<n; ++i) cnt[i] += cnt[i-1];

    int res = 0;
    for(int v=2; v<=n; ++v) res += max(0, 1 - cnt[pos[v]]);
    cout << res;

    return 0;
}