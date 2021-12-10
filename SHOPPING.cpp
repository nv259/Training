#include    <bits/stdc++.h>
#define ll long long

using namespace std;
///////////////////////

const   int N = 2e5+50;
int     n, q;
ll      a[N], f[N][20];

void    enter(){
    scanf("%d%d", &n, &q);
    for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);
    a[++n] = 0;
}

void    init(){
    for (int i = 1; i <= n; i++) f[i][0] = a[i];

    for (int k = 1; (1 << k) <= n; k++)
        for (int i = 1; i + (1 << k) - 1 <= n; i++) 
            f[i][k] = min(f[i][k-1], f[i + (1 << k-1)][k-1]);
}

void    answer(){
    while (q--)
    {
        ll  ans;
        int l, r;
        scanf("%lld%d%d", &ans, &l, &r);

        while (l <= r)
        {
            int u = l;
            for (int i = log2(n); i >= 0; i--)
                if (f[u][i] > ans) u += (1 << i);
            if (u > r) break;
            ans %= a[u];
            l = u + 1;
        }
        cout << ans << "\n";
    }
}

int main(){
    freopen("shopping.inp","r",stdin);
    freopen("shopping.out","w",stdout);
    //freopen("a.inp","r",stdin);

    enter();
    init();
    answer();

    return 0;
}