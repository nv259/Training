#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
typedef pair <long long, long long> ii;

ii p[1000005];
int n = 0, m = 0, c[1000005];

void mergePoint() {
    int k, n, x, y;
    scanf("%d", &k);
    while (k--) {
        scanf("%d", &n);
        ++n;
        while (n--) {
            scanf("%d%d", &x, &y);
            p[m++] = make_pair(abs(x), y);
        }
    }
    sort(p, p + m, [] (const ii &a, const ii &b) {
         return a.x < b.x || a.x == b.x && a.y < b.y;
    });
    m = unique(p, p + m) - p;
}

bool ccw(const ii &a, const ii &b, const ii &c) {
    return (b.x - a.x) * (a.y + b.y) + (c.x - b.x) * (b.y + c.y) + (a.x - c.x) * (c.y + a.y) >= 0;
}

void findConvexHull() {
    c[1] = 1;
    n = 2;
    for (int i = 2; i <= m; ++i) {
        while (n > 1 && ccw(p[c[n - 2]], p[c[n - 1]], p[i])) --n;
        c[n++] = i;
    }
}

double area(const ii &a, const ii &b) {
    double A = b.y - a.y, B = a.x - b.x, C = a.y * b.x - a.x * b.y;
    return C * C / (A * B);
}

int main() {
    freopen("saw.inp","r",stdin);
    freopen("saw.out","w",stdout);
    
    mergePoint();
    findConvexHull();
    double ans = 0;
    for (int i = 0; i < n - 1; ++i)
        ans = max(ans, area(p[c[i]], p[c[i + 1]]));
    printf("%.6lf", ans);

    return 0;
}
