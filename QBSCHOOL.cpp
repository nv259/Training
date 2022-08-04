#include    <bits/stdc++.h>
#define V second
#define W first
#define ll long long

using namespace std;
/////////////////////////
const   int N = 6000;
typedef pair <int, int> ii;

int     n, m, d[N];
ll      c[N];
vector <ii> e[N];

void    enter(){
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++) 
    {
        int     k, u, v, l;
        scanf("%d%d%d%d", &k, &u, &v, &l);
        e[u].push_back({l, v});
        if (k == 2)     
            e[v].push_back({l, u});
    }    
}

void    dijkstra(){
    for (int i = 0; i <= n; i++) 
        d[i] = INFINITY, c[i] = 1;
    d[1] = 0;
    priority_queue <ii, vector <ii>, greater <ii> > pq;
    pq.push({0, 1});

    while (!pq.empty())
    {
        int u = pq.top().V;
        int du = pq.top().W;
        pq.pop();

        if (du != d[u]) continue;

        for (ii x : e[u])
        {
            int uv = x.W;
            if (d[x.V] > du + uv)
            {
                c[x.V] = c[u];
                d[x.V] = du + uv;
                pq.push({d[x.V], x.V});
            }
            else if (d[x.V] == du + uv) c[x.V] += c[u];
        }
    }

    cout << d[n] << " " << c[n];
}

int main(){
    //freopen("a.inp","r",stdin);

    enter();
    dijkstra();

    return 0;
}