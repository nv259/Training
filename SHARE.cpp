#include    <bits/stdc++.h>

using namespace std;
///////////////////////

long long   n, m, res;

int main(){
    freopen("share.inp","r",stdin);
    freopen("share.out","w",stdout);

    cin >> n >> m;
    while (m > 0 && n%m != 0)
    {
        n %= m;
        res += (m-1)/n * n;
        m %= n;
    }
    cout << res;

    return 0;
}