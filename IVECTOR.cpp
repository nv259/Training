#include    <bits/stdc++.h>

using namespace std;
//////////////////////////

const   int N = 1e5+5;

int     n, a[N], t[N], f[N];

int     get(int x){
    int result = 0;

    while (x <= n)
    {
        result += f[x];
        x += (x & -x);
    }
    return result;
}

void    update(int x){
    while (x)
    {
        f[x]++;
        x -= (x & -x);
    }
}

void    solve1(){
    for (int i = 1; i <= n; i++) 
    {
        scanf("%d", &a[i]);
        t[a[i]] = get(a[i]+1);
        update(a[i]);
    }
    for (int i = 1; i <= n; i++) cout << t[i] << " ";
    cout << "\n";
}

int     get2(int x){
    int     result = 0;

    while (x)
    {
        result += f[x];
        x -= (x & -x);    
    }
    return result;
}

void    update2(int x){
    while (x <= n)
    {
        f[x]++;
        x += (x & -x);
    }
}

bool    check(int x, int k){
    int t = get2(x);
    if (x - t - 1 >= k) return true;
    return false;
}

void    solve2(){
    for (int i = 1; i <= n; i++) 
    {
        scanf("%d", &t[i]);
        f[i] = 0;
        a[i] = 0;   
    }
    
    for (int i = 1; i <= n; i++)
    {
        int first = 1, last = n, mid = (first + last) >> 1;
        while (first != mid && last != mid) 
        {
            if (check(mid, t[i])) last = mid;
            else first = mid;
            mid = (first + last) >> 1;
        }
        for (int j = first; j <= last; j++) 
            if (check(j, t[i]))
            {
                a[j] = i;
                update2(j);
                break;
            } 
    }
    for (int i = 1; i <= n; i++) cout << a[i] << " ";
}

int main(){
    freopen("ivector.inp","r",stdin);
    freopen("ivector.out","w",stdout);
    //freopen("a.inp","r",stdin);

    scanf("%d", &n);
    solve1();
    solve2();

    return 0;
}