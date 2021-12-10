#include <cstdio>
#include <iostream>
#include <algorithm>
#include <deque>
#define llong long long

using namespace std;

int n, h, s, d, a[400006], a_max[400006], b[400006];

int main() {
    freopen("PROJECT.inp", "r", stdin);
    freopen("PROJECT.out", "w", stdout);
    ///
    scanf("%d", &n);
    scanf("%d%d%d", &h, &s, &d);
    ///
    int k = (h + d) / s;
    deque<int> Q;
    ///
    llong Cost = 0;
    for(int i=1; i<=n; ++i) scanf("%d", &a[i]);
    ///
    for(int i=n; i>=1; --i) {
        while (!Q.empty() && a[Q.back()] <= a[i]) Q.pop_back();
        Q.push_back(i);
        while (!Q.empty() && Q.front() - i > k) Q.pop_front();
        a_max[i] = a[Q.front()];
    }
    ///
    b[1] = a[1];
    Cost += 1LL * h * b[1] + 1LL * s * b[1];
    for(int i=2; i<=n; ++i) {
        if (b[i-1] <= a[i]) b[i] = a[i]; else b[i] = min(b[i-1], a_max[i]);
        ///
        if (b[i] > b[i-1]) Cost += 1LL * h * (b[i] - b[i-1]);
        else Cost += 1LL * d * (b[i-1] - b[i]);
        ///
        Cost += 1LL * s * b[i];
    }
    ///
    Cost += 1LL * d * b[n];
    cout << Cost << "\n";
    for(int i=1; i<=n; ++i) cout << b[i] << " ";
    return 0;
}