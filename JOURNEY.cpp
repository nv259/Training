#include    <bits/stdc++.h>

using namespace std;
/////////////////////////

const   int N = 1e6+5;

int     Tx, Ty, n, cnt;
char    s[N], a[N];

void    enter(){
    cin >> Tx >> Ty;
    scanf("%s", s+1); 
    n = strlen(s+1);
}

void    solve(){
    int     x, y;
    x = y = 0;
    for (int i = 1; i <= n; i++) 
    {
        switch (s[i])
        {
            case 'D' :  y--;    break;
            case 'L' :  x--;    break;
            case 'R' :  x++;    break;
            case 'U' :  y++;    break;
            default :   cnt++;  break;
        }
    }
    Tx -= x;    Ty -= y;
    int     cc = cnt;

    while (Tx < 0) a[cnt--] = 'L', Tx++;
    while (Ty < 0) a[cnt--] = 'D', Ty++; 
    while (Ty > 0) a[cnt--] = 'U', Ty--;
    while (Tx > 0) a[cnt--] = 'R', Tx--;
    
    if (cnt < 0 || cnt&1) 
        { cout << "IMPOSSIBLE"; return; }  
    while (cnt)
    {
        if (cnt&1) a[cnt] = 'D';
        else a[cnt] = 'U';
        cnt--;
    }
    
    sort(a+1, a+cc+1);
    cc = 0;
    for (int i = 1; i <= n; i++) 
        if (s[i] != '?') cout << s[i];
        else cout << a[++cc];
}

int main(){
    freopen("journey.inp","r",stdin);
    freopen("journey.out","w",stdout);
    //freopen("a.inp","r",stdin);

    enter();
    solve();

    return 0;
}