#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct data{
    long long x,y,z;
    operator<(data &other) { return y<other.y || y==other.y && x>other.x ; }
} a[100005];

struct gap{
    long long left,right;
    operator<(gap &other) { return right<other.right; }
};

long long n,r,f[100005];
vector <gap> S;

bool cmp(long long a,gap b) {return a<=b.right;}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    freopen("rep2.inp","r",stdin);
    freopen("rep2.out","w",stdout);

    cin>>n;
    for(int i=0;i<n;i++) cin>>a[i].x>>a[i].y>>a[i].z;

    sort(a,a+n);
    S.push_back({a[0].y-a[0].z+1,a[0].y});
    f[1]=a[0].z ; r=1 ;

    for(int i=1;i<n;i++) {
        long long k,dem;
        if (a[i].x > S.back().right ) dem=0;else {
            k = upper_bound(S.begin(),S.end(),a[i].x,cmp) - S.begin();
            dem = f[r]-f[k+1]+max(0LL,S[k].right-max(S[k].left,a[i].x)+1LL);
        }
        if (dem < a[i].z) {
            long long t = a[i].y - a[i].z + dem + 1;
            while (!S.empty() && t<=S.back().right) {
                t-=S.back().right - S.back().left + 1;
                t=min(t,S.back().left) ;
                S.pop_back() ;
                r-- ;
            }
            S.push_back({t,a[i].y}); r++ ;
            f[r] = f[r-1] + a[i].y - t + 1;
        };
    }
    cout<<f[r];

    return 0;
}