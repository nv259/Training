#include    <bits/stdc++.h>

using namespace std;
//////////////////////

const   int N = 1e4+5;

struct  edge{
    int     x, y, c, f;
}e[N];

int     n, m, link[N], head[N], FlowValue, trace[N], delta, s, t;

void    enter(){
    int     x, y, c;

    scanf("%d%d", &n, &m, &s, &t);
    for (int i = 1; i <= m; i++) 
    {
        scanf("%d%d%d", &x, &y, &c);
        e[i].x = e[i+m].y = x;
        e[i].y = e[i+m].x = y;
        link[i] = head[x];  head[x] = i;
        link[i+m] = head[y];  head[y] = i+m;
    }
}

bool    find_path(){
    for (int i = 1; i <= m; i++) trace[i] = 0;
    queue <int> Q;

    trace[s] = 1;
    Q.push(s);

    while (!Q.empty())
    {
        int u = Q.front();
        Q.pop();

        int i = head[u];
        while (i)
        {   
            int v = e[i].y;
            if (!trace[v] && e[i].f < e[i].c)
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

void    AugmentFlow(){
    int     v = t, i;
    delta = INFINITY;

    do{
        i = trace[v];
        delta = min(delta, e[i].c - e[i].f);
        v = e[i].x;
    } while (v != s);

    v = t;
    do{
        i = trace[v];
        e[i].f += delta;
        e[i+m].f -= delta;
        v = e[i].x;
    } while (v != s);
    FlowValue += delta;
}

void    print(){

}

int main(){
    freopen("a.inp","r",stdin);

    enter();
    while (find_path()) AugmentFlow();
    print();

    return 0;
}