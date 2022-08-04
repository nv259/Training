#include    <bits/stdc++.h>

using namespace std;
//////////////////////////

int     p, par[20000];

int     root(int x){
    return (par[x] < 0) ? x : par[x] = root(par[x]);
}

void    _union(int x, int y){
    if (x == y) return;
    if (par[y] < par[x]) swap(x, y);
    par[x] += par[y];
    par[y] = x;
}   

int main(){ 
    //freopen("a.inp","r",stdin);

    scanf("%d", &p);
    for (int i = 1; i <= 1e4; i++) par[i] = -1;

    for (int i = 1; i <= p; i++)
    {
        int     x, y, k;
        scanf("%d%d%d", &x, &y, &k);
        x = root(x); y = root(y);
        if (k == 1) _union(x, y);
        else if (x != y) cout << 0 << "\n"; else cout << 1 << "\n";
    }

    return 0;
}