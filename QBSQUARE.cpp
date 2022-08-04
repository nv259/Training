#include    <bits/stdc++.h>
#define FOR(i,a,b) for (int i = a; i <= b; i++)

using namespace std;
////////////////////////
const   int N = 1e3+5;

int     m, n, a[N][N], f[N][N];

void    enter(){
    scanf("%d%d", &m, &n);
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++) scanf("%d", &a[i][j]);
}

void    solve(){
    int     res = 0;
    FOR(i,1,n) if (a[1][i] == 1) f[1][i] = 1;
    FOR(i,1,m) if (a[i][1] == 1) f[i][1] = 1;
    FOR(i,1,m) FOR(j,1,n)
    {
        if (a[i][j] == a[i-1][j] && a[i][j] == a[i][j-1] && a[i][j] == a[i-1][j-1] /*&& a[i][j] == 1*/) 
            f[i][j] = min(f[i-1][j], min(f[i][j-1], f[i-1][j-1])) + 1;
        else 
            /*if (a[i][j] == 1)*/ f[i][j] = 1;
        res = max(res, f[i][j]);
    }
    cout << res;
}

int main(){
    //freopen("a.inp","r",stdin);
    
    enter();
    solve();

    return 0;
}