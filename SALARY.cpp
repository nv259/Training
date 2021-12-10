#include <bits/stdc++.h>
#define foru(i, a, b) for(int i=a; i<=b; i++)

const int maxn=1e5+5;

struct data
{
    int a;
    long long b;
    data (){}
    data (int c, long long d):a(c), b(d){}
};

using namespace std;

long long h[maxn], kq[maxn], bi[maxn];
vector <int> a[maxn];
vector <data> v[2][maxn];
int n, m, dem;

void enter()
{
    int x;
    scanf("%d%d", &n, &m);
    scanf("%I64d", &h[1]);
    foru(i, 1, n-1)
    {
        scanf("%I64d%d", &h[i+1], &x);
        a[x].push_back(i+1);
    }
    scanf("\n");

    char t;
    int u;
    long long p;
    foru (i, 1, m)
    {
        scanf("%c", &t);
        if (t == 'p')
        {
            scanf("%d%I64d", &u, &p);
            v[0][u].emplace_back(i, p);
        }
        if (t == 'u')
        {
            dem++;
            scanf("%d", &u);
            v[1][u].emplace_back(i, dem);
        }
        scanf("\n");
    }
}

void up(int n, long long x)
{
    while (n<=m)
    {
        bi[n] += x;
        n += (n & (-n));
    }
}

long long get(int n)
{
    long long re = 0;
    while (n>0)
    {
        re += bi[n];
        n -= (n & (-n));
    }
    return re;
}

void dfs(int u)
{
    int l, l2;
    data t;

    l = v[1][u].size();
    foru (i, 0, l-1)
    {
        t = v[1][u][i];
        kq[t.b] = get(t.a) + h[u];
    }

    l2 = v[0][u].size();
        foru (j, 0, l2-1)
        {
            t = v[0][u][j];
            up(t.a, t.b);
        }

    l = a[u].size();
    foru (i, 0, l-1)
    {
        dfs(a[u][i]);
    }

    l2 = v[0][u].size();
        foru (j, 0, l2-1)
        {
            t = v[0][u][j];
            up(t.a, -t.b);
        }
}

void solve()
{
    dfs(1);

    foru (i, 1, dem) cout << kq[i] << '\n';
}

int main()
{
    freopen("SALARY.inp", "r", stdin);
    freopen("SALARY.OUT", "w", stdout);

    enter();
    solve();
}