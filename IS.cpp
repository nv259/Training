#include    <bits/stdc++.h>
#define ll long long

using namespace std;
////////////////////////
const   int N = 1e5+5;

int     n,a[N], w[N], ans, pos, trace[N];
ll      f[N], bit[N];

void    enter(){
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    for (int i = 1; i <= n; i++) scanf("%d", &w[i]);
}

ll      get(int x){
    ll  result = 0;
    
    while (x)
    {
        result = max(result, bit[x]);
        x -= (x & -x);
    }
    return result;
}

void    update(int x, int val){
    while (x <= N)
    {
        bit[x] = max(bit[x], 1LL*val);
        x += (x & -x);
    }
}

void    print(){
    int cnt = 0, cc = n;
    trace[++cnt] = pos;
    while (cc && cnt <= n)
    {
        while (cc && ans - w[pos] != f[cc]) cc--;
        pos = trace[++cnt] = cc;
        ans = f[cc];
        cc--;
    }

    cout << cnt << "\n";
    for (int i = cnt; i > 0; i--) cout << trace[i] << " ";
}

void    solve(){
    for (int i = 1; i <= n; i++)
    {
        f[i] = get(a[i]-1) + w[i];
        if (ans <= f[i]) { ans = f[i]; pos = i; }
        update(a[i], f[i]);
    }
    print();
}

int main(){
    freopen("is.inp","r",stdin);
    freopen("is.out","w",stdout);
    //freopen("a.inp","r",stdin);

    enter();
    solve();

    return 0;
}