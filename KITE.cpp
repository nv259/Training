#include    <bits/stdc++.h>
#define val first
#define pos second

using namespace std;
////////////////////////
const   int N = 1e5+5;
typedef pair <int, int> ii;

int     a[N], n, f[N];
ii      c[N];

bool    cmp(ii a, ii b){
    return a.val < b.val || a.val == b.val && a.pos < b.pos;
}

void    enter(){
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) 
    {
        scanf("%d", &c[i].val);
        c[i].pos = i;
    }
    //compress
    sort(c+1, c+n+1, cmp);
    int cc = 1, cnt = 1;
    while (cc <= n)
    {
        while (c[cc].val == c[cc+1].val) a[c[cc++].pos] = cnt; 
        a[c[cc++].pos] = cnt++; 
    }
}

int     get(int x){
    int result = 0;

    while (x <= n)
    {
        result += f[x];
        x += (x & -x);
    }
    return result;
}

void    update(int x){
    while (x)
    {
        f[x]++;
        x -= (x & -x);
    }
}

void    solve(){
    for (int i = 1; i <= n; i++)
    {
        cout << get(a[i]+1) + 1 << "\n";
        update(a[i]);
    }
}

int main(){
    freopen("kite.inp","r",stdin);
    freopen("kite.out","w",stdout);
    //freopen("a.inp","r",stdin);

    enter();
    solve();

    return 0;
}