using namespace std;
#include<bits/stdc++.h>
#define x first
#define y second
#define FORE(i,a,b) for(int i=(a),b_=(b);i<=b_;++i)
#define FORD(i,a,b) for(int i=(a),b_=(b);i>=b_;--i)
#define TR(c, it) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)

const int MOD = 1e9 + 7 ;
const int MAXN = 1e5 + 5 ;
typedef pair < long long , long long > point ;
point origin ;
point operator - (point A , point B) {return point (A.x - B.x , A.y - B.y) ;}
point operator + (point A , point B) {return point (A.x + B.x , A.y + B.y) ;}
long long operator * (point A , point B) {return abs(1LL * A.x * B.y - B.x * A.y ) ;}
void operator -= (point &A , point B) {A.x -= B.x ; A.y -= B.y ; }
bool ccw (point O , point A , point B ) {A -= O ; B -= O ; return 1LL * A.x * B.y > 1LL * A.y * B.x ;}
bool cmp (point A , point B ) { return ccw(origin , A , B) ; }
long long area (point A , point B , point C) {
    return abs(((B.x - A.x) * (C.y - A.y) - (C.x - A.x) * (B.y - A.y)));
}
bool check (point A , point B , point C , point P) {
  point PA = A - P ;
  point PB = B - P ;
  point PC = C - P ;
  point AB = B - A ;
  point AC = C - A ;
  if (PA * PB + PB * PC + PC * PA > AB * AC) return false ;
  else return true ;
}
vector < point > convex ;
int n ;
long long S ;
point a[MAXN] ;
int main()
{
#define TASK "NAME"
    // freopen(TASK".inp","r",stdin);
    // freopen(TASK".out","w",stdout);
    cin >> n >> S ;
    for(int i = 1 ; i <= n ; ++i ) cin >> a[i].x >> a[i].y ;
    sort(a + 1 , a + n + 1) ;
    point A = a[1] , B = a[2] , C = a[3];
    long long SMax = area(A, B, C) ;
    while(1)
    {
        bool ans = false ;
        for(int i = 1 ; i <= n ; ++i ) if (area(A , B , a[i]) > SMax) SMax = area(A, B, a[i]), C = a[i], ans = true ;
        for(int i = 1 ; i <= n ; ++i ) if (area(A , a[i] , C) > SMax) SMax = area(A, a[i], C), B = a[i], ans = true ;
        for(int i = 1 ; i <= n ; ++i ) if (area(a[i] , B , C) > SMax) SMax = area(a[i], B, C), A = a[i], ans = true ;
        if (ans == false) break ;
    }
    point X = (A + B) - C ;
    point Y = (B + C) - A ;
    point Z = (A + C) - B ;
    //printf("(%d %d)\n", A.x, A.y);
    //printf("(%d %d)\n", B.x, B.y);
    //printf("(%d %d)\n", C.x, C.y);
    cout << X.x << " " << X.y << endl;
    cout << Y.x << " " << Y.y << endl;
    cout << Z.x << " " << Z.y << endl;

    return 0;
}