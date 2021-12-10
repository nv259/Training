#include <iostream>
#include <algorithm>
#define llong long long

using namespace std;

struct Data {
    int a, b;
} P[100006];

int     w, h, n;

void    enter(){
    scanf("%d%d%d", &n, &w, &h);
    for(int i = 1; i <= n; ++i) scanf("%d%d", &P[i].a, &P[i].b);
}

bool    check(double k) {
    double W = 0, H = 0, mmax_W = 0;
    
    for(int i = 1; i <= n; ++i) {
        double a = k * P[i].a, b = k * P[i].b;
        if (i > 1 && P[i].b == P[i-1].b && W + a <= w) W += a;
        else {
            W = a;
            H += b;
        }
        mmax_W = max(mmax_W, W);
        if (mmax_W > w || H > h) return false;
    }
    return mmax_W <= w && H <= h;
}

void    solve(){
    double L = 0, R = 1e9, ans = 0;
    while (R - L > 1e-7) {
        double mid =  (L + R) / 2.0;
        if (check(mid)) {
            ans = mid;
            L = mid;
        } else R = mid;
    }

    (cout << fixed).precision(6);
    cout << ans;
}

int main() {
    freopen("advert.inp", "r", stdin);
    freopen("advert.out", "w", stdout);
    //freopen("a.inp","r",stdin);

    enter();
    solve();

    return 0;
}