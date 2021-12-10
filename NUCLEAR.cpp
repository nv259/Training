#include    <bits/stdc++.h>
#define file_name "NUCLEAR"

using namespace std;

struct Point {
    int x, y;
} P[200006];

struct Data {
    int R1, R2;
};

Point A, B;
int n, m, x_max = 0, y_max = 0, cnt_a[200006], cnt_b[200006];
vector<int> Seg[800006], X[200006];

int dist(const Point &tmp, const Point &tmp_2) {
    return ceil(sqrt((1LL * tmp_2.x - tmp.x) * (1LL * tmp_2.x - tmp.x) + (1LL * tmp_2.y - tmp.y) * (1LL * tmp_2.y - tmp.y)));
}

void Build(int id, int l, int r) {
    if (l > r) return;
    if (l == r) {
        Seg[id] = X[l];
        return;
    }

    int mid = (l + r) >> 1;
    int id_l = id<<1;
    int id_r = id<<1 | 1;
    Build(id_l, l, mid);
    Build(id_r, mid+1, r);

    int sz_l = Seg[id_l].size();
    int sz_r = Seg[id_r].size();
    int sz = sz_l + sz_r;
    Seg[id].resize(sz);

    int cur_l = 0, cur_r = 0, cur = 0;
    while (cur_l < sz_l && cur_r < sz_r)
        if (Seg[id_l][cur_l] < Seg[id_r][cur_r]) Seg[id][cur++] = Seg[id_l][cur_l++];
        else Seg[id][cur++] = Seg[id_r][cur_r++];

    while (cur_l < sz_l) Seg[id][cur++] = Seg[id_l][cur_l++];
    while (cur_r < sz_r) Seg[id][cur++] = Seg[id_r][cur_r++];
}

int Query(int id, int l, int r, int pivot_a, int pivot_b) {
    if (l > pivot_a) return 0;
    if (r <= pivot_a) return upper_bound(Seg[id].begin(), Seg[id].end(), pivot_b) - Seg[id].begin();

    int mid = (l + r) >> 1;
    int _left_ = Query(id<<1, l, mid, pivot_a, pivot_b);
    int _right_ = Query(id<<1 | 1, mid+1, r, pivot_a, pivot_b);
    return _left_ + _right_;
}

void init() {
    for(int i=1; i<=n; ++i) {
        Data E = {dist(P[i], A), dist(P[i], B)};
        if (E.R1 <= 200000) {
            ++cnt_a[E.R1];
            x_max = max(x_max, E.R1);
            if (E.R2 <= 200000) {
                X[E.R1].push_back(E.R2);
                ++cnt_b[E.R2];
                y_max = max(y_max, E.R2);
            }
        }
    }

    for(int i=0; i<=x_max; ++i) {
        sort(X[i].begin(), X[i].end());
        if (i > 0) cnt_a[i] += cnt_a[i-1];
    }

    for(int i=1; i<=y_max; ++i) cnt_b[i] += cnt_b[i-1];
    Build(1, 0, x_max);
}

template<typename T>
bool fast_scan(T &num) {
    num = 0;
    register char c = getchar();
    while (c != '-' && (c < '0' || '9' < c)) {
        if (feof(stdin)) return false;
        c = getchar();
    }
    bool neg = false;
    if (c == '-') {
        neg = true;
        c = getchar();
    }
    for(; '0' <= c && c <= '9'; c = getchar()) num = (num << 1) + (num << 3) + (c - '0');
    if (neg) num = -num;
    return true;
}

int main() {
    freopen(file_name".INP", "r", stdin);
    freopen(file_name".OUT", "w", stdout);

    fast_scan(n);
    for(int i=1; i<=n; ++i) fast_scan(P[i].x), fast_scan(P[i].y);
    fast_scan(A.x), fast_scan(A.y);
    fast_scan(B.x), fast_scan(B.y);
    init();

    fast_scan(m);
    while (m--) {
        int R1, R2; fast_scan(R1), fast_scan(R2);
        R1 = min(R1, x_max); R2 = min(R2, y_max);

        int ans = Query(1, 0, x_max, R1, R2);
        cout << cnt_a[R1] + cnt_b[R2] - ans << "\n";
    }

    return 0;
}
