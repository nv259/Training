#include <bits/stdc++.h>

using namespace std;
///////////////////////

void ext_gcd(long long a, long long b, long long &d, long long &x, long long &y) {
    if (b == 0) {
        d = a;
        x = 1;
        y = 0;
        return;
    }
    long long x1, y1;
    ext_gcd(b, a%b, d, x1, y1);
    x = y1;
    y = x1 - a/b*y1;
}

long long dong_nuoc(long long a, long long b, long long c) {
    if (a > b) swap(a, b);
    long long d, x, y;
    ext_gcd(a, b, d, x, y);
    if (c%d != 0) return -1;

    long long t1, t2, ans = 1e18;
    t1 = ceil(-1.0*c*x/b);
    t2 = floor(1.0*c*y/a);
    if (t1 <= t2)
        ans = min(ans, c*(x+y)/d + (b-a)/d*t1);

    t1 = ceil(-1.0*c*x/b);
    t2 = ceil(1.0*c*y/a);
    ans = min(ans, c*(x-y)/d + (b+a)/d*max(t1, t2));

    t1 = floor(-1.0*c*x/b);
    t2 = floor(1.0*c*y/a);
    ans = min(ans, c*(-x+y)/d - (b+a)/d*min(t1, t2));

    return ans;
}

int main() {
    freopen("cwater.inp", "r", stdin);
    freopen("cwater.out", "w", stdout);

    long long k, a, b, c;
    cin >> k;
    for (int i = 1; i <= k; i++) {
        cin >> a >> b >> c;
        cout << dong_nuoc(a, b, c) << '\n';
    }

    return 0;
}