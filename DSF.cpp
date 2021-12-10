#include <bits/stdc++.h>
#define foru(i, a, b) for(int i=a; i<=b; i++)

const int maxn=2e5+5;

using namespace std;

int n, m, kq;
int x[maxn], y[maxn], cha[maxn];;

void enter()
{
    scanf("%d%d", &n, &m);
    foru (i, 1, m)
        scanf("%d%d", &x[i], &y[i]);
}

int goc(int x)
{
    if (cha[x] < 0) return x;
    cha[x] = goc(cha[x]);
    return cha[x];
}

void hop(int x, int y) {

    if ((x = goc(x)) == (y = goc(y))) return ;

    kq++;
    if (cha[y] < cha[x]) swap(x, y);
    cha[x] += cha[y];
    cha[y] = x;
}

void solve()
{
    foru (i, 1, n) cha[i] = -1;

    foru (i, 1, m)
    {
        hop(x[i], y[i]);
        cout << n-kq << '\n';
    }
}

int main()
{
    freopen("dsf.inp", "r", stdin);
    freopen("dsf.out", "w", stdout);

    enter();
    solve();

    return 0;
}
