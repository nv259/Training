#include    <bits/stdc++.h>

using namespace std;
///////////////////////

int     n;
long long   k, tmp = 1;

int main(){
    cin >> n >> k;
    
    for (int i = 1; i <= 2000000; i++)
    {
        if (i > n) 
            { cout << n; break; }
        k -= tmp;
        if (k == 0) 
            { cout << i; break; }
        if (k < 0) 
            { cout << i-1; break; }
        tmp += 3;
    }

    return 0;
}