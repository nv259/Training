#include    <bits/stdc++.h>
#define V first
#define W second

using namespace std;
/////////////////////////
const   int N = 1e5+5;
typedef pair <int, int> ii;

int     n, m, topo[N], len, f[N];
vector <ii> e[N];
bool    marked[N];

void    enter(){
    int     u, v, w;

    scanf("%d%d", &n, &m);
    for (int i  = 1; i <= n; i++) 
    {
        scanf("%d%d%d", &u, &v, &w);
        e[u].push_back({v, w});
        //e[v].push_back({u, w});
    }
}

void    dfs(int u){
    marked[u] = true;

    for (ii U : e[u])
    {
        int v = U.V;
        if (!marked[v]) dfs(v);
    }
    topo[len--] = u;
}

void    toposort(){
    len = n;
    for (int i = 1; i <= n; i++)
        if (!marked[i]) dfs(i);
}

void    solve(){
    int     ans = 0;
    for (int i = 1; i <= n; i++)
        for (ii U : e[topo[i]]) f[U.V] = max(f[U.V], f[topo[i]] + U.W);
    for (int i = 1; i <= n; i++) ans = max(ans, f[i]);
    cout << ans;
}

int main(){
    freopen("maxpdag.inp","r",stdin);
    freopen("maxpdag.out","w",stdout);
    //freopen("a.inp","r",stdin);

    enter();
    toposort();    
    solve();

    return 0;
}