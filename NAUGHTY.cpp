#include    <bits/stdc++.h>

using namespace std;
/////////////////////////
const   int N = 1e5+5;

int     n, k, ans, h[N], f[N][20];

void    enter(){
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++) scanf("%d", &h[i]);
}

void    init(){
    for (int i = 1; i <= n; i++) f[i][0] = h[i];
    for (int k = 1; (1 << k) <= n; k++) 
        for (int i = 1; i + (1 << k) - 1 <= n; i++) 
            f[i][k] = max(f[i][k-1], f[i + (1 << (k-1))][k-1]);
}

int     get(int u, int v){
    int     k = log2(v - u + 1);
    return max(f[u][k], f[v - (1 << k) + 1][k]);    
}

void    process(int first, int last, int key, int problem){
    int     mid;
    while (first <= last)
    {
        mid = (first + last) >> 1;
        switch (problem)
        {
        case 0:
            if (get(first, mid) - key <= k) { ans += (mid - first + 1); first = mid + 1; }
            else last = mid - 1;
            break;
        case 1: 
            if (get(mid, last) - key <= k) { ans += (last - mid + 1); last = mid - 1; }
            else first = mid + 1;
            break;
        }
           
    }
}

void    solve(){
    for (int i = 1; i <= n; i++)
    {
        ans = 0;
        process(i, n, h[i], 0);
        process(1, i-1, h[i], 1);
        cout << ans << " ";
    }
}

int main(){
    freopen("naughty.inp","r",stdin);
    freopen("naughty.out","w",stdout);
    //freopen("a.inp","r",stdin);

    enter();
    init();
    solve();

    return 0;
}