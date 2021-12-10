#include    <bits/stdc++.h>
#define llong long long
#define ldouble long double

using namespace std;

struct Data {
    llong val, tmp;
};

llong mulmod(llong a, llong n, llong m){
  llong q = ((ldouble) a * (ldouble) n/ (ldouble) m);
  llong res = a * n - m * q;
  res =(res % m + m) % m;
  return res;
}

Data cal_mod(llong a, llong n, llong base, llong m) {
    if (n == 0) return {0, 1};
    ///
    Data z = cal_mod(a, n>>1, base, m);
    z.val = (z.val + mulmod(z.val, z.tmp, m)) % m;
    z.tmp = mulmod(z.tmp, z.tmp, m);
    ///
    if (n & 1) {
        z.val = (mulmod(z.val, base, m) + a) % m;
        z.tmp = mulmod(z.tmp, base, m);
    }
    return z;
}

int main() {
    freopen("remainder.inp", "r", stdin);
    freopen("remainder.out", "w", stdout);

    int test; 
    cin >> test;
    while (test--) 
    {
        llong a, n, m;
        scanf("%lld%lld%lld", &a, &n, &m);
        ///
        llong tmp = a, base = 1;
        while (tmp > 0) tmp /= 10, base *= 10, base %= m;
        ///
        cout << cal_mod(a, n, base, m).val << "\n";
    }

    return 0;
}