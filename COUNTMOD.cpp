#include <bits/stdc++.h>
using namespace std;

void ext_gcd(long long a, long long b, long long &d, long long &x, long long &y)
{
    if (b == 0)
    {
        d = a;
        x = 1;
        y = 0;
    }
    else
    {
        long long x1, y1;
        ext_gcd(b, a%b, d, x1, y1);
        x = y1;
        y = x1 - a/b*y1;
    }
}

long long mul_mod(long long a, long long b, long long m)
{
    if (b == 0)
        return 0;
    if (b < 0)
    {
        a = -a;
        b = -b;
    }
    long long t = mul_mod(a, b/5, m);
    return (5*t + a*(b%5)) % m;
}

bool solve(long long m1, long long a1, long long m2, long long a2, long long &m12, long long &a12)
{
    long long d, u, v;
    ext_gcd(m1, m2, d, u, v);
    if ((a2-a1)%d != 0)
        return false;

    m12 = m1*m2/d;
    a12 = ((a1 + mul_mod(m1*(a2-a1)/d, u, m12)) % m12 + m12) % m12;
    return true;
}

int main()
{
    freopen("countmod.inp", "r", stdin);
    freopen("countmod.out", "w", stdout);
    long long t, m1, a1, m2, a2, m3, a3, m4, a4;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        cin >> m1 >> a1 >> m2 >> a2 >> m3 >> a3 >> m4 >> a4;
        long long m12, a12, m34, a34, m, a;
        if (!solve(m1, a1, m2, a2, m12, a12))
        {
            cout << "-1\n";
            continue;
        }
        if (!solve(m3, a3, m4, a4, m34, a34))
        {
            cout << "-1\n";
            continue;
        }
        if (!solve(m12, a12, m34, a34, m, a))
        {
            cout << "-1\n";
            continue;
        }
        cout << a << '\n';
    }
    return 0;
}


