#include    <bits/stdc++.h>

using namespace std;
///////////////////////

int     n, k, f[100005];
bool    exist[100005];

void    enter(){
    int     x;

    scanf("%d%d", &n, &k);
    for (int i = 1; i <= k; i++)
    {
        scanf("%d", &x);
        exist[x] = true;
    }
}

void    solve(){
    int     cnt = 0, res = 0;

    for (int i = 1; i <= n; i++) 
        if (!exist[i]) f[++cnt] = i;
    
    f[cnt+1] = n+1;
    for (int i = 1; i <= cnt; i++)
    {
        if (exist[0]) 
            res = max(res, f[i+1] - f[i-1] -1);
        else 
            res = max(res, f[i+1] - f[i] -1);
    }
    cout << res;
}

int main(){
    freopen("a.inp","r",stdin);

    enter();
    solve();

    return 0;
}