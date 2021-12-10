#include    <bits/stdc++.h>

using namespace std;
////////////////////////

const   int N = 1e6;

int     k, n, bottom, top, _min, a[N], d[N];

void    enter(){
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
}

void    push(int i){
    while (top >= bottom && a[d[top]] > a[i]) top--;
    d[++top] = i;
    _min = min(_min, a[d[bottom]]);
}


void    pop(int i){
    if (d[bottom] <= i) bottom++;
    _min = a[d[bottom]];
}

void    solve(){
    _min = INFINITY;
    bottom = 1;

    for (int i = 1; i <= k; i++) push(i);
    cout << _min << "\n";

    for (int i = k+1; i <= n; i++) 
    {
        push(i);
        pop(i-k);
        cout << _min << "\n";
    }
}

int main(){
    freopen("minimum.inp","r",stdin);
    freopen("minimum.out","w",stdout);

    enter();
    solve();

    return 0;
}