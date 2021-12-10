#include    <bits/stdc++.h>

using namespace std;
///////////////////////

const   int N = 1e5+5;

int     n, m, a[N], f[N][20];

void    enter(){
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
}

void    init(){
    for (int i = 1; i <= n; i++) f[i][0] = a[i];

    for (int k = 1; (1 << k) <= n; k++)
        for (int i = 1; i + (1 << k) - 1 <= n; i++)  
            f[i][k] = min(f[i][k-1], f[i + (1 << (k-1))][k-1]);
}

void    answer(){
    int     u, v;
    while (m--)
    {
        scanf("%d%d", &u, &v);
        int k = log2(v - u + 1);
        cout << min(f[u][k], f[v - (1 << k) + 1][k]) << "\n";
    }
}

int main(){
    freopen("rmq.inp","r",stdin);
    freopen("rmq.out","w",stdout);
    //freopen("a.inp","r",stdin);

    enter();
    init();
    answer();

    return 0;
}
