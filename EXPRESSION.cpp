#include    <bits/stdc++.h>
#define ll long long

using namespace std;
///////////////////////

char    s[2000000];
int     n;
ll      num;
bool    checkFirst, checkSecond, check;

ll      gcd(ll a, ll b){
    if (b == 0) return a;
    return gcd(b, a%b);
}

int     scan(int *pos){
    num = 0;
    int     pospos = *pos;
    check = true;

    if ('0' <= s[pospos] && s[pospos] <= '9' ) 
    {
        check = false; 
        while ('0' <= s[pospos] && s[pospos] <= '9') 
            { num = num*10 + s[pospos] - '0'; pospos++; }
    }
    
    while (pospos <= n && ((s[pospos] == '(' || s[pospos] == ')') || s[pospos] == ',')) pospos++;
    *pos = pospos;
    return num;
}

ll      process(int *pos){
    ll  First, Second;

    int     current1 = *pos + 4;
    First = scan(&current1);
    if (First == 0) First = process(&current1);  

    int     current2 = current1;
    Second = scan(&current2);
    if (Second == 0) Second = process(&current2);
     
    int     pospos = *pos;
    *pos = current2;
    if (s[pospos] == 'M')
    {
        pospos++;
        if (s[pospos] == 'I') return min(First, Second); 
        if (s[pospos] == 'A') return max(First, Second); 
    }
    if (s[pospos] == 'G') return gcd(First, Second); 
    if (s[pospos] == 'S') return First + Second; 
    if (s[pospos] == 'D') return First - Second; 
}

int main(){
    freopen("expression.inp","r",stdin);
    freopen("expression.out","w",stdout);
    //freopen("a.inp","r",stdin);

    scanf("%s", s+1);
    n = strlen(s+1);
    int     pos = 1;
    cout << process(&pos);

    return 0;
}
