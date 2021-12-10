#include <bits/stdc++.h>
#define foru(i, a, b) for(int i=a; i<=b; i++)

const int maxn =505;

struct edge
{
    int x, y, c, f;
};

using namespace std;

int     n, bd, kt, dem, sum;
vector  <int> adj[maxn];
edge    e[maxn*maxn];
int     d[maxn];
queue   <int> q;

void add_edge(int i, int x, int y, int c)
{
    e[i].x = x; e[i].y = y; e[i].c = c; e[i].f = 0;
    adj[x].push_back(i);
    adj[y].push_back(-i);
}

void enter()
{
    int x;
    scanf("%d", &n);
    bd = n+1; kt = n+2;
    foru (i, 1, n)
    {
        scanf("%d", &x);
        if (x < 0) add_edge(++dem, i, kt, -x);
        if (x > 0) add_edge(++dem, bd, i, x), sum += x;
    }

    int xx, y;
    scanf("%d", &xx);
    foru (i, 1, xx)
    {
        scanf("%d%d", &x, &y);
        add_edge(++dem, x, y, sum+1);
    }
}

void reset()
{
    foru (i, 1, n) d[i] = 0;
    while (!q.empty()) q.pop();
}

bool find_path()
{
    q.push(bd);
    d[bd] = bd;
    int  u, v;
    while (!q.empty())
    {
        u = q.front(); q.pop();
        if (u == kt) return true;
        for (int i:adj[u])
        {
            if (i > 0)
            {
                v = e[i].y;
                if (d[v] != 0) continue;
                if (e[i].c == e[i].f) continue;

                d[v] = i;
                q.push(v);
            }
            else
            {
                v = e[-i].x;
                if (d[v] != 0) continue;
                if (e[-i].f == 0) continue;

                d[v] = i;
                q.push(v);
            }
        }
    }
    return false;
}

void them()
{
    int delta = INFINITY, u, i;
    u = kt;
    while (u != bd)
    {
        i = d[u];
        if (i > 0)
        {
            delta = min(delta, e[i].c - e[i].f);
            u = e[i].x;
        }
        else
        {
            delta = min(delta, e[-i].f);
            u = e[-i].y;
        }
    }
    u = kt;
    while (u != bd)
    {
        i = d[u];
        if (i > 0) e[i].f += delta, u = e[i].x;
        if (i < 0) e[-i].f -= delta, u= e[-i].y;
    }
}

void solve()
{
    n += 2;
    while (true)
    {
        reset();
        if (!find_path()) break;
        them();
    }

    int re = 0;
    for (int i:adj[bd])
    {
        if (i > 0) re += e[i].f;
    }
    cout << sum - re;
}

int main()
{
    freopen("jobset.inp", "r", stdin);
    freopen("jobset.out", "w", stdout);

    enter();
    solve();

    return 0;
}
