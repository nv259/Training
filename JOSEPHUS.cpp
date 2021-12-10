#include <bits/stdc++.h>
#define foru(i, a, b) for(int i=a; i<=b; i++)

const int maxn = 4e5+5;

using namespace std;

int n, dem, k;
int     it[maxn], s[maxn], dd[maxn];

void build(int i)
{
    if (i > n) return;
    build(i*2);
    dem++;
    it[i] = dem;
    build(i*2+1);
    s[i] = 1;
    if (i*2 <= n)
        s[i] += s[i*2];
    if (i*2+1 <= n)
        s[i] += s[i*2+1];
}

int get(int p)
{
    int re = 1, lef;
    while (true)
    {
        if (re * 2 <= n) lef = s[re*2]; else lef = 0;
        if (!dd[re] && lef +1 == p) break;

        if (lef >= p) re = re*2;
        else
        {
            p -= lef;
            if (!dd[re]) p--;
            re = re*2+1;
        }
    }
    return re;
}

void setmark(int i)
{
    dd[i]= true;
    while (i > 0)
    {
        s[i]--;
        i = i / 2;
    }
}

void solve()
{
    build(1);

    int p = 1, node;
    for (int i=n; i>=1; i--)
    {
        p = (p+k-2) % i +1;
        node = get(p);
        cout << it[node] << ' ';
        setmark(node);
    }
}

int main()
{
    freopen("josephus.inp", "r", stdin);
    freopen("josephus.out", "w", stdout);
    //freopen("a.inp","r",stdin);

    scanf("%d%d", &n, &k);
    solve();

    return 0;
}