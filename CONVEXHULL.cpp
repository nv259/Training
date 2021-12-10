#include    <bits/stdc++.h>
#define ll long long

using namespace std;
///////////////////////

const   int N = 1e5+5;

struct  node{
    int     x, y;
}_min, a[N], convex[N];

int     n, pos;

bool    cmp(node a, node b){
    return (a.y < b.y) || (a.y == b.y && a.x < b.x);
}

void    enter(){
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d%d", &a[i].x, &a[i].y);
    sort(a+1, a+n+1, cmp);
    _min = a[1];
    //for (int i = 1; i <= n; i++) 
       //a[i].x -= _min.x, a[i].y -= _min.y;
};

ll      area(node a, node b, node c){
    return  1LL*(b.x - a.x)*(b.y + a.y) + 
            1LL*(c.x - b.x)*(c.y + b.y) + 
            1LL*(a.x - c.x)*(a.y + c.y) ;
}

bool    ccw(node a, node b, node c){
    return area(a, b, c) < 0;
}

void    print(){
    cout << pos-1 << "\n";
    
    long double  res = 0;
    for (int i = 2; i < pos; i++)
        res += abs(area(convex[1], convex[i], convex[i+1]));
    res /= 2;
    cout << fixed;
    cout << setprecision(1) << res << "\n";

    for (int i = 1; i < pos; i++) cout << convex[i].x << " " << convex[i].y << "\n";
}

void    solve(){
    convex[1] = a[1];
    convex[2] = a[2];
    pos = 2;

    for (int i = 3; i <= n; i++) 
    {
        while (pos >= 2 && !ccw(convex[pos-1], convex[pos], a[i])) pos--;
        convex[++pos] = a[i];
    }

    int     temp = pos+1;
    convex[++pos] = a[n-1];

    for (int i = n-2; i >= 1; i--)
    {
        while (pos >= temp && !ccw(convex[pos-1], convex[pos], a[i])) pos--;
        convex[++pos] = a[i];
    }
    print();
}

int main(){
    freopen("convexhull.inp","r",stdin);
    freopen("convexhull.out","w",stdout);
    
    enter();
    solve();

    return 0;
}