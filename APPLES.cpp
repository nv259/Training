#include    <bits/stdc++.h>
#define ll long long

using namespace std;
////////////////////////////

const   int N = 1e6+5;

struct  tree{
    int     x, y, pos;
}a[N], p1;

int     n, min_index;

void    enter(){
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d%d", &a[i].x, &a[i].y);
        a[i].pos = i;
    }
}

ll      area(tree a, tree b, tree c){
    return  1LL*(b.x - a.x)*(b.y + a.y) +
            1LL*(c.x - b.x)*(c.y + b.y) +
            1LL*(a.x - c.x)*(a.y + c.y) ; 
}

bool    cmp(tree a, tree b){
    return area(p1, a, b) < 0;
}

void    solve(){
    min_index = 1;
    for (int i = 1; i <= n; i++)    
        if (a[i].y < a[min_index].y || (a[min_index].y == a[i].y && a[i].x < a[min_index].x)) min_index = i;
    swap(a[1], a[min_index]);
    p1 = a[1];
    sort(a+2, a+n+1, cmp);

    cout << a[1].pos << " " << a[n/2 + 1].pos;
}

int main(){
    freopen("apples.inp","r",stdin);
    freopen("apples.out","w",stdout);
    
    enter();
    solve();

    return 0;
}