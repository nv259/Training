#include <cstdio>
#include <iostream>
#include <algorithm>
#include <queue>
#define llong long long

using namespace std;

int trace[3006], a[1006], cnt[1006], n, q;
const int base = 1000;

void Trace() {
    if (trace[base] == -1) cout << "NO";
    else {
        cout << "YES\n";
        q = 0;
        do {
            ++cnt[trace[q + base]];
            q = q - a[trace[q + base]];
        } while (q != 0);
        ///
        for(int i=1; i<=n; ++i) cout << cnt[i] << " ";
    }
}

int main() {
    freopen("COCKTAIL.inp", "r", stdin);
    freopen("COCKTAIL.out", "w", stdout);
    ///
    scanf("%d%d", &n, &q);
    for(int i=1; i<=n; ++i) scanf("%d", &a[i]), a[i] -= q;
    ///
    queue<int> V;
    for(int i=0; i<=3*base; ++i) trace[i] = -1;
    for(int i=1; i<=n; ++i)
    if (trace[a[i]+base] == -1) {
        trace[a[i]+base] = i;
        V.push(a[i]);
    }
    ///
    while (!V.empty()) {
        int u = V.front(); V.pop();
        for(int i=1; i<=n; ++i) {
            int v = u + a[i];
            if (v >= 0 && v <= 2 * base && trace[v + base] == -1) {
                trace[v + base] = i;
                V.push(v);
            }
        }
    }
    Trace();
    return 0;
}             