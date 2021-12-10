#include <bits/stdc++.h>
#define foru(i, a, b) for(int i=a; i<=b; i++)

const int maxn=1e6+5, maxf= -1e8;

struct data
{
    int d[2][2];
};

using namespace std;

char s[maxn];
int ct;

int max1(int a, int b, int c, int d, int k)
{
    int t1= a + b, t2 = c + d;

    if (k == 1)
        t2--;
    if (k == 2)
        t1--;
    if (k == 3)
        t1--;
    if (k == 4)
        t1--;

    if (a == maxf || b == maxf)
        t1= maxf;
    if (c == maxf || d == maxf)
        t2= maxf;

    return max(t1, t2);
}

int cong(int a, int b, int k)
{
    if (a == maxf || b == maxf)
        return maxf;
    return (a+b-k);
}

data dq(int i)
{
    data a, b, c;
    ct++;

    if (s[ct] == 'g')
    {
        c.d[1][0] = 1;
        c.d[0][1] = 1;
        c.d[0][0] = 0;
        c.d[1][1] = maxf;
    }

    if (s[ct] == 'S')
    {
        a= dq(i+1);
        b= dq(i+1);
        c.d[0][0] = max1(a.d[0][0], b.d[0][0], a.d[0][1], b.d[1][0], 1);
        c.d[1][1] = max1(a.d[1][1], b.d[1][1], a.d[1][0], b.d[0][1], 2);
        c.d[1][0] = max1(a.d[1][1], b.d[1][0], a.d[1][0], b.d[0][0], 3);
        c.d[0][1] = max1(a.d[0][1], b.d[1][1], a.d[0][0], b.d[0][1], 4);
    }

    if (s[ct] == 'P')
    {
        a= dq(i+1);
        b= dq(i+1);
        c.d[0][0] = cong(a.d[0][0], b.d[0][0], 0);
        c.d[0][1] = cong(a.d[0][1], b.d[0][1], 1);
        c.d[1][0] = cong(a.d[1][0], b.d[1][0], 1);
        c.d[1][1] = cong(a.d[1][1], b.d[1][1], 2);
    }

    return c;
}

void solve()
{
    data c;
    c=dq(1);
    cout << max(c.d[1][1], max(c.d[1][0], max(c.d[0][1], c.d[0][0])));
}

int main()
{
    freopen("indep.inp", "r", stdin);
    freopen("indep.out", "w", stdout);

    scanf("%s", s+1);
    solve();
}

