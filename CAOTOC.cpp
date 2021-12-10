#include    <bits/stdc++.h>
#define ll long long

using namespace std;
/////////////////////////
const   int N = 1e6+5;

struct  point{
    ll  x, y;
}a[N];

ll      n;

void    fastscan(ll &x){
    bool    negative = false;
    register char c;
    c = getchar();

    if (c == '-') 
    {
        negative = true;
        c = getchar();
    }

    for (; c >= '0' && c <= '9'; c = getchar())
        x = (x<<1) + (x<<3) + c - '0';
    if (negative) x *= -1;  
}

void    enter(){
    fastscan(n);    scanf("\n");
    for (int i = 1; i <= n; i++) 
    {
        fastscan(a[i].x);
        fastscan(a[i].y);
        scanf("\n");
    }
}

bool    cmp(point a, point b){
    return a.y < b.y || a.y == b.y && a.x <= b.x;
}

void    solve(){
    sort(a+1, a+n+1, cmp);

    ll  res, lower = 0, upper = 0;
    int     id1, id2;

    for (int i = 2; i <= n; i++) 
        upper += a[i].y - a[1].y;
    res = upper;
    id1 = 1; id2 = n-1;

    for (int i = 2; i <= n; i++)
    {
        lower += 1LL*id1*(a[i].y - a[i-1].y);
        upper -= 1LL*id2*(a[i].y - a[i-1].y);
        res = min(res, lower + upper);
        id1++;  id2--;
    }
    
    cout << res;
}

int main(){
    freopen("caotoc.inp","r",stdin);
    freopen("caotoc.out","w",stdout);
    //freopen("a.inp","r",stdin);

    enter();
    solve();

    return 0;
}