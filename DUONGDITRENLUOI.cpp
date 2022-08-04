#include    <bits/stdc++.h>
#define ll long long
#define X first
#define Y second

using namespace std;
///////////////////////

const   int N = 2e3+5;

int     n, m, a[N][N];
pair <int, int> trace[N*N*2];
ll      f[N][N];

void    enter(){
    scanf("%d%d", &m, &n);
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++) scanf("%d", &a[i][j]);
}

void    solve(){
    for (int i = 1; i <= m; i++) f[i][1] = f[i-1][1] + a[i][1];
    for (int j = 1; j <= n; j++) f[1][j] = f[1][j-1] + a[1][j];

    for (int i = 2; i <= m; i++) 
        for (int j = 2; j <= n; j++) f[i][j] = max(f[i-1][j], f[i][j-1]) + a[i][j];

    int     i = m, j = n, cnt = 0;
    while (i != 1 || j != 1)
    {
        trace[++cnt].X = i; trace[cnt].Y = j;
        if (f[i][j] == f[i-1][j] + a[i][j]) i--;
        else
        if (f[i][j] == f[i][j-1] + a[i][j]) j--; 
    }   
    trace[++cnt] = {1, 1};

    cout << f[m][n] << "\n" << cnt << "\n";
    for (int i = cnt; i >= 1; i--) cout << trace[i].X << " " << trace[i].Y << "\n"; 
}

int main(){
    freopen("a.inp","r",stdin);

    enter();
    solve();

    return 0;
}