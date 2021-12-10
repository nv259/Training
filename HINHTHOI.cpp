#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
 
typedef pair <int, int> ii;
#define x first
#define y second
 
const int MAX_N = 1505;
 
ii p[MAX_N];
int c[MAX_N * MAX_N];
vector <ii> mid[205][205], v;
 
inline ii vect(const ii &a, const ii &b) {
    int A = b.y - a.y, B = a.x - b.x, C = a.y * b.x - a.x * b.y, gcd = __gcd(A, __gcd(B, C));
    A /= gcd, B /= gcd;
    if (A < 0 || !A && B < 0)
        A = -A, B = -B;
    return make_pair(A, B);
}
 
void gather_mid_point() {
    int n; scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d%d", &p[i].x, &p[i].y);
        p[i].x += 50;
        p[i].y += 50;
    }
    for (int i = 0; i < n - 1; ++i)
    for (int j = i + 1; j < n; ++j)
        if (p[i] != p[j])
            mid[p[i].x + p[j].x][p[i].y + p[j].y].emplace_back(vect(p[i], p[j]));
}
 
void count_perpendicular() {
    long long res = 0;
    for (int p = 0; p <= 200; ++p)
    for (int q = 0; q <= 200; ++q)
        if (mid[p][q].size() > 1) {
            v = mid[p][q];
            sort(v.begin(), v.end());
            int nv = 0;
            c[0] = 1;
            for (int i = 1; i < v.size(); ++i) {
                if (v[i] != v[i - 1]) v[++nv] = v[i], c[nv] = 0;
                ++c[nv];
            }
            for (int i = 0; i <= nv; ++i) {
                ii u = make_pair(-v[i].y, v[i].x);
                if (u.x < 0 || !u.x && u.y < 0) u.x = -u.x, u.y = -u.y;
                int pos = lower_bound(v.begin() + i + 1, v.begin() + nv + 1, u) - v.begin();
                if (pos <= nv && v[pos] == u)
                    res += 1LL * c[i] * c[pos];
            }
        }
    printf("%lld", res);
}
 
int main() {
    gather_mid_point();
    count_perpendicular();
}
