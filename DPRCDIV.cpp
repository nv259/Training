#include    <bits/stdc++.h>

using namespace std;
//////////////////////////
const   int N = 1e6+5;

int     n, m, a[N];
bool    avail[N];

void    read(int &x){
    bool negative = false;
    x = 0;
    register char c;
    c = getchar();
    if (c == '-') 
    {
        c = getchar();
        negative = true;
    }
    for (; c >= '0' && c <= '9'; c = getchar())
        x = (x << 1) + (x << 3) + c -'0';
    if (negative) x = -x;
}

void    enter(){
    scanf("%d%d\n", &n, &m);
    for (int i = 1; i <= n; i++) 
    {
        read(a[i]);
        a[i] %= m;
    }
}

bool    check(int pos, int mod){
    if (avail[mod]) return true;
    avail[mod] = true;
    for (int i = pos+1; i <= n; i++) check(i, (mod + a[i])%m);
}

int main(){
    //freopen("a.inp","r",stdin);
    
    enter();
    if (n > m)
    {
        cout << "YES";
        return 0;
    }
    for (int i = 1; i <= n; i++) check(i, a[i]);
    if (avail[0]) cout << "YES";
    else cout << "NO";

    return 0;
}