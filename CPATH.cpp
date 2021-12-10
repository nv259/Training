#include    <bits/stdc++.h>

using namespace std;
////////////////////////

struct matrix {
    int a[51][51];

    matrix() {
        memset(a, 0, sizeof(a));
    }
};

const int mod = 2017;
int m, n, k;

matrix operator * (const matrix &A, const matrix &B) {
    matrix C = matrix();
    for(int s=1; s<=n; ++s)
        for(int t=1; t<=n; ++t)
            for(int mid=1; mid<=n; ++mid) 
                C.a[s][t] = (C.a[s][t] + A.a[s][mid] * B.a[mid][t]) % mod;
    return C;
}

matrix zero = matrix();

matrix power(matrix A, int b) {
    if (b == 0) return zero;
    matrix tmp = power(A, b / 2);
    tmp = tmp * tmp;
    if (b % 2) tmp = tmp * A;
    return tmp;
}

void    process(){
    matrix A = matrix();
    scanf("%d%d%d", &n, &m, &k);
    for(int i=1; i<=m; ++i) {
        int u, v; scanf("%d%d", &u, &v);
        ++A.a[u][v];
    }

    for(int i=1; i<=n; ++i) zero.a[i][i] = 1;
    cout << power(A, k).a[1][n];
}

int main() {
    freopen("cpath.inp", "r", stdin);
    freopen("cpath.out", "w", stdout);
    
    process();

    return 0;
}
