/// hhoangcpascal

#include <iostream>
#include <algorithm>
#include <vector>
#define llong long long
#define file_name "CHOCOLATE"

using namespace std;

template<typename _type_>
void writeInt(_type_ num) {
    if (num > 9) writeInt(num / 10);
    putchar(num % 10 + '0');
}

struct Point {
    int x, y;

    bool operator == (const Point &other) const {
        return x == other.x && y == other.y;
    }

    bool operator < (const Point &other) const {
        return x < other.x || (x == other.x && y < other.y);
    }
};

typedef Point *PPoint;

/// 0: R, 1: U, 2: L, 3: D
Point P[1200006];
char S[200006];
int m, n, k, link[1200006][4], cnt = 1;

void Enter() {
    scanf("%d%d%d%d%d", &m, &n, &k, &P[0].x, &P[0].y);
    scanf("%s", S);
}

PPoint PP[1200006];
int rep[1200006];

void Set_link(int u, int v, int type) {
    link[u][type] = v;
    link[v][(type + 2) % 4] = u;
}

void Set_link_1(int u, int v, int type) {
    link[u][type] = v;
    link[v][(type + 2) % 4] = -1;
}

int Find(PPoint X) {
    PPoint pos = *lower_bound(PP, PP+cnt, X, [] (const PPoint A, const PPoint B) {
        return *A < *B;
    });

    return rep[pos - P];
}

void Init() {
    int x = P[0].x, y = P[0].y;

    for(int i=0; i<k; ++i) {
        switch(S[i]) {
            case 'L': --x; break;
            case 'R': ++x; break;
            case 'U': ++y; break;
            case 'D': --y; break;
        }

        P[cnt++] = {x, y};
    }

    for(x = 0; x <= m; ++x) {
        P[cnt++] = {x, 0};
        P[cnt++] = {x, n};
    }

    for(y = 1; y < n; ++y) {
        P[cnt++] = {0, y};
        P[cnt++] = {m, y};
    }

    for(int i=0; i<cnt; ++i) PP[i] = &P[i];

    sort(PP, PP+cnt, [] (const PPoint A, const PPoint B) {
        return *A < *B;
    });

    rep[PP[0]-P] = PP[0] - P;
    for(int i=1; i<cnt; ++i)
        if (*PP[i] == *PP[i-1]) rep[PP[i]-P] = rep[PP[i-1]-P];
        else rep[PP[i]-P] = PP[i] - P;

    fill(link[0], link[cnt], -1);
    for(int i=0; i<k; ++i) {
        int type = -1;

        switch (S[i]) {
            case 'R': type = 0; break;
            case 'U': type = 1; break;
            case 'L': type = 2; break;
            case 'D': type = 3; break;
        }

        int u = rep[i], v = rep[i+1];
        Set_link(u, v, type);
    }

    for(int x=0; x<m; ++x) {
        Point p1 = {x, 0}, p2 = {x+1, 0};
        int pos1 = Find(&p1), pos2 = Find(&p2);
        Set_link_1(pos1, pos2, 0);
    }

    for(int y=0; y<n; ++y) {
        Point p1 = {m, y}, p2 = {m, y+1};
        int pos1 = Find(&p1), pos2 = Find(&p2);
        Set_link_1(pos1, pos2, 1);
    }

    for(int x=m; x>0; --x) {
        Point p1 = {x, n}, p2 = {x-1, n};
        int pos1 = Find(&p1), pos2 = Find(&p2);
        Set_link_1(pos1, pos2, 2);
    }

    for(int y=n; y>0; --y) {
        Point p1 = {0, y}, p2 = {0, y-1};
        int pos1 = Find(&p1), pos2 = Find(&p2);
        Set_link_1(pos1, pos2, 3);
    }
}

llong Cross_Product(const Point &A, const Point &B) {
    return 1LL * A.x * B.y - 1LL * B.x * A.y;
}

llong Get_area(int u, int d) {
    int Start = u, Start_d = d;
    u = link[u][d];
    llong res = 0;

    do {
        d = (d + 1) % 4;
        int v = -1;

        while (true) {
            v = link[u][d];
            if (v != -1) break;
            d = (d + 3) % 4;
        }

        res += Cross_Product(P[u], P[v]);
        link[u][d] = -1;
        if (u == Start && d == Start_d) break;
        u = v;
    } while (true);

    return res / 2;
}

llong area[1200006];
int cnt_area = 0;

void Process() {
    for(int i=0; i<cnt; ++i) {
        if (rep[i] != i) continue;
        for(int d=0; d<4; ++d)
        if (link[i][d] != -1) {
            llong A = Get_area(i, d);
            if (A > 0) area[++cnt_area] = A;
        }
    }

    sort(area+1, area + cnt_area + 1);

    writeInt(cnt_area), putchar('\n');
    for(int i=1; i <= cnt_area; ++i) writeInt(area[i]), putchar(' ');
}

int main() {
    freopen(file_name".INP", "r", stdin);
    freopen(file_name".OUT", "w", stdout);

    Enter();
    Init();
    Process();

    return 0;
}
