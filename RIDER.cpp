#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAX_N = 1e5 + 5;

struct point {
    ll x, y;
};

point t[MAX_N], s[MAX_N];
int c[MAX_N];
double v[MAX_N];

bool ccw(const point &a, const point &b, const point &c) {
    point u = {b.x - a.x, b.y - a.y};
    point v = {c.x - a.x, c.y - a.y};
    return u.x*v.y - u.y*v.x > 0;
}

int main() {
    freopen("RIDER.INP", "r", stdin);
    freopen("RIDER.OUT", "w", stdout);

    int n, k = 0;
    scanf("%d", &n);

    for (int i = 0; i < n; ++i) {
        scanf("%lld", &t[i].y);
        t[i].x = i + 1;
        while (k > 1 && ccw(t[c[k - 2]], t[c[k - 1]], t[i]))
            --k;
        c[k++] = i;
    }

    int m;
    scanf("%d", &m);
    for (int i = 0; i < m; ++i) {
        scanf("%lld", &s[i].y);
        s[i].x = i;
    }

    sort(s, s + m, [] (const point &a, const point &b) {
        return a.y < b.y;
    });

    for (int i = 0, j = 0; i < m; ++i) {
        point p = {0, s[i].y};
        while (j < k - 1 && ccw(p, t[c[j]], t[c[j + 1]]))
            ++j;
        v[s[i].x] = t[c[j]].x / double(t[c[j]].y - s[i].y);
    }

    for (int i = 0; i < m; ++i)
        printf("%.12f\n", v[i]);
}