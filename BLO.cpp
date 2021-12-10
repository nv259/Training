#include    <bits/stdc++.h>
#define ll long long

using namespace std;
////////////////////////
const   int N = 5e5 + 5;

int     n, m, num[N], low[N], down[N], up[N];
vector <int> e[N];
bool    component[N], marked[N];

void    enter(){
    int     u, v;

    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++)
    {
        scanf("%d%d", &u, &v);
        e[u].push_back(v);
        e[v].push_back(u);
    }
}

int     cnt = 0;

void    dfs(int u, int p){
    int     numChild = 0;
    num[u] = low[u] = ++cnt;

    for (int v : e[u])
    if (v != p) {
        if (num[v]) 
            low[u] = min(low[u], num[v]);
        else
        {
            dfs(v, u);
            numChild++;
            low[u] = min(low[u], low[v]);

            //if (low[v] >= num[v]) criticalEdges++;
            if (u == p) 
                { if (numChild >= 2) component[u] = true; }
            else 
                { if (low[v] >= num[u]) component[u] = true; }
        }
    }
}

void    init(){
    for (int i = 1; i <= n; i++)
        if (!num[i]) dfs(i, i);
}

void    make_tree(int u){
    up[u] = 1;
    marked[u] = true;

    for (int v : e[u]) 
    {
        if (!marked[v])
        {   
            down[v] = down[u] + 1;
            make_tree(v);   
            up[u] += up[v];
        }
    }
}

void    solve(){
    make_tree(1);
    for (int u = 1; u <= n; u++)
    {
        ll ans = n-1;
        if (component[u]) ans += 1LL*down[u]*(up[u]-1); 
        cout << ans*2LL << "\n";
    }
}

int main(){
    freopen("blo.inp","r",stdin);
    freopen("blo.out","w",stdout);
    //freopen("a.inp","r",stdin);

    enter();
    init();
    solve();

    return 0;
}