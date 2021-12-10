#include    <bits/stdc++.h>

using namespace std;
///////////////////////
const   int N = 1e3+5,
            M = 1e5+5;

struct semgent{
    int x, y, c, f;
} e[2*M];

int     m, n, s, t, trace[2*N], link[2*M], head[2*N], res;

void    enter(){
    int     u, v, c;
    scanf("%d%d%d%d", &n, &m, &s, &t);
    for (int i = 1; i <= m; i++)
    {
        scanf("%d%d%d", &u, &v, &c);
        e[i].x = e[i+m].y = u;
        e[i].y = e[i+m].x = v;
        e[i].c = c; e[i+m].c = 0;
        link[i] = head[u]; head[u] = i;
        link[i+m] = head[v]; head[v] = i+m;
    }
}

bool    findPath(){
    memset(trace, 0, sizeof(trace));
    trace[s] = 1;
    queue <int> Q;
    Q.push(s);
    while (!Q.empty())
    {
        int     u = Q.front();
        Q.pop();
        int     i = head[u];
        while (i)
        {
            int     v = e[i].y;
            if (trace[v] == 0 && e[i].f < e[i].c)
            {
                trace[v] = i;
                if (v == t) return true;
                Q.push(v);
            }   
            i = link[i];
        }
    }
    return false;
}

void    increaseFlow(){
    int     v = t, i;
    int     delta = INFINITY;
    while (v != s)
    {
        i = trace[v];
        delta = min(delta, e[i].c - e[i].f);
        v = e[i].x;
    }
     
    v = t;
    while (v != s)
    {
        i = trace[v];
        e[i].f += delta;
        e[i+m].f -= delta;
        v = e[i].x;
    }
    res += delta;
}

int main(){
    freopen("maxflow.inp","r",stdin);
    freopen("maxflow.out","w",stdout);
    //freopen("a.inp","r",stdin);

    enter();
    while (findPath()) 
        increaseFlow();
    cout << res;

    return 0;
}