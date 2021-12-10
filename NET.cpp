#include    <bits/stdc++.h>

using namespace std;
////////////////////////////
const   int N = 2e6;

struct TEdge {
    int u, v, pos;
} E[N];

int     link[N], head[N], low[N], num[N], a[N], lab[N], nChild[N], 
        n, m, K, L , lab_edge[N];
bool    A[N], B[N];

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
    fast_scan(n), fast_scan(m), fast_scan(K), fast_scan(L);
    for(int i=1; i<=K; ++i) {
        int u; fast_scan(u);
        A[u] = true;
    }
    for(int i=1; i<=L; ++i) {
        int u; fast_scan(u);
        B[u] = true;
    }

    for(int i=1; i<=m; ++i) {
        int u, v; scanf("%d%d", &u, &v);
        E[i] = {u, v, i}; E[i+m] = {v, u, i};

        link[i] = head[u]; head[u] = i;
        link[i+m] = head[v]; head[v] = i+m;
    }
}

void DFS(int u) {
    low[u] = 1e9, num[u] = ++num[0];

    int i = head[u];
    while (i != 0) {
        int v = E[i].v;
        if (lab[u] != v) {
            if (num[v] > 0) low[u] = min(low[u], num[v]);
            else {
                lab[v] = u;
                lab_edge[v] = E[i].pos;
                DFS(v);
                low[u] = min(low[u], low[v]);
            }
        }
        i = link[i];
    }
}

bool bridges[1000006];
int res = 0;

void get_bridges() {
    for(int u=1; u<=n; ++u)
    if (num[u] == 0) DFS(u);

    for(int v=1; v<=n; ++v) {
        int u = lab[v];
        if (u == 0) continue;

        int p = lab_edge[v];
        if (low[v] >= num[v]) ++res, bridges[p] = true;
    }
}

struct Data {
    int ser_A, ser_B;

    Data operator + (const Data &other) const {
        return {ser_A + other.ser_A, ser_B + other.ser_B};
    }

    Data operator - (const Data &other) const {
        return {ser_A - other.ser_A, ser_B - other.ser_B};
    }
} dp[100006];

bool avail[100006];
int connect = 0;
vector<int> V[100006];

void DFS2(int u) {
    avail[u] = true;
    lab[u] = connect;

    if (A[u]) ++dp[connect].ser_A;
    if (B[u]) ++dp[connect].ser_B;

    for(int i=head[u]; i>0; i = link[i]) {
        if (bridges[E[i].pos]) continue; 
        if (!avail[E[i].v]) DFS2(E[i].v);
    }
}

void init() {
    for(int i=1; i<=n; ++i) lab[i] = 0;
    for(int i=1; i<=n; ++i)
    if (!avail[i]) { 
        ++connect;
        DFS2(i);
    }

    for(int i=1; i<=m; ++i)
    if (bridges[i]) {
        int u = E[i].u;
        int v = E[i].v;

        V[lab[u]].push_back(lab[v]);
        V[lab[v]].push_back(lab[u]);
    }
}

Data Tree(int u, int par) {
    for(int v: V[u]) {
        if (v == par) continue;
        dp[u] = dp[u] + Tree(v, u);
    }

    return dp[u];
}

bool important(const Data &A, const Data &B) {
    if (A.ser_A == 0 && B.ser_A != 0) return true;
    if (A.ser_B == 0 && B.ser_B != 0) return true;
    if (B.ser_A == 0 && A.ser_A != 0) return true;
    if (B.ser_B == 0 && A.ser_B != 0) return true;
    return false;
}

void Rotate(int u, int par) {
    for(int v: V[u]) {
        if (v == par) continue;

        Data tmp_u = dp[u];
        Data tmp_v = dp[v];

        dp[u] = dp[u] - dp[v];
        if (!important(dp[u], dp[v])) --res;

        dp[v] = dp[v] + dp[u];
        Rotate(v, u);

        dp[u] = tmp_u;
        dp[v] = tmp_v;
    }
}

void process() {
    Tree(1, 0);
    Rotate(1, 0);
    cout << res;
}

int main() {
    freopen("NET.inp", "r", stdin);
    freopen("NET.out", "w", stdout);

    enter();
    get_bridges();
    init();
    process();

    return 0;
}
