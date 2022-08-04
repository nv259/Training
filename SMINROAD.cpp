#include    <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
#define ull unsigned long long

using namespace std;
////////////////////////
typedef pair <int, int> ii;
typedef pair <int, ii> iii;
const   int N = 5e5+5;

int     n, m, a[N], par[N], weight[N];
vector <iii> edge;

void    enter(){
    cin >> n >> m;
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    for (int i = 1; i <= m; i++) 
    {
        int u, v;
        scanf("%d%d", &u, &v);
        edge.push_back({min(a[u], a[v]), {u, v}});
    }   
}

void    init(){
    for (int i = 1; i <= n; i++) 
        par[i] = -1, weight[i] = 1;
    sort(edge.begin(), edge.end(), greater<iii>());
}

int     root(int x){
    return (par[x] < 0) ? x : par[x] = root(par[x]);
}

void    _union(int x, int y){
    if (par[y] < par[x]) swap(x, y);
    par[x] += par[y];
    par[y] = x;
    weight[x] += weight[y];
}

void    solve(){
    init();
    ull res = 0;
    for (iii X : edge)
    {
        int x = X.se.fi;
        int y = X.se.se;
        x = root(x);    y = root(y);
        if (x == y) continue;
        res += 1LL*X.fi*weight[x]*weight[y];
        _union(x, y);
    }
    res <<= 1;
    cout << res;
}

int main(){
    //union sets
    enter();
    solve();

    return 0;
}