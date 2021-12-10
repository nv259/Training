#include    <bits/stdc++.h>

using namespace std;

int     n, m, b[100006], a[100006], ans;
vector < pair<int, int> > trace;

bool check(int mid) {
    int ans = 2e9+7; trace.clear();
    for(int i=1, cur = 1; i<=n; ++i) {
        while (cur <= m && a[i] + b[cur] < mid) ++cur;
        if (cur > m) ans = min(ans, a[i]);
        else if (a[i] < mid) {
            ans = min(ans, a[i] + b[cur]);
            trace.push_back(make_pair(i, cur));
        }
        if (a[i] < mid) ++cur;
    }
    return ans >= mid;
}

void    enter(){
    scanf("%d", &n);
    for(int i=1; i<=n; ++i) scanf("%d", &a[i]);
    scanf("%d", &m);
    for(int i=1; i<=m; ++i) scanf("%d", &b[i]);
}

void    solve(){
    int l = 0, r = 2e9;
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (check(mid)) {
            ans = mid;
            l = mid + 1;
        } else r = mid - 1;
    }
}

void    print(){
    cout << ans << " ";
    check(ans);
    cout << trace.size() << "\n";
    for(pair<int, int> p: trace) cout << p.first << " " << p.second << "\n";
}

int main() {
    freopen("WALL.inp", "r", stdin);
    freopen("WALL.out", "w", stdout);
    //freopen("a.inp","r",stdin);

    enter();
    solve();
    print();

    return 0;
}