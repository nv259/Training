#include    <bits/stdc++.h>
using namespace std;

char    a[2000000];
int     n, t;

int main(){ 
    freopen('a.inp', 'r', stdin)

    scanf("%d%d", &n, &t)
    for (int i = 0; i < t; i++)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        a[x]++; a[y+1]--;
    }

    int     result = 0;

    for (int i = 1; i <= n; i++)
    {
        a[i] = a[i-1] + a[i];
        if (a[i] % 3 == 0) result++;
    }

    return 0;
}
