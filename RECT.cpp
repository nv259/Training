#include    <bits/stdc++.h>
#define ll long long

using namespace std;
/////////////////////////

ll      process(vector <int> a, int n){
    stack <int> d, dd;
    vector <int> l, r;

    d.push(-1);  d.push(0); l.push_back(0);

    for (int i = 1; i < n; i++) 
    {
        while (d.size() > 1 && a[d.top()] >= a[i]) d.pop();
        l.push_back(d.top()+1);
        d.push(i);
    }

    dd.push(n); dd.push(n-1); r.push_back(n-1);

    for (int i = n-2; i >= 0; i--)
    {
        while (dd.size() > 1 && a[dd.top()] >= a[i]) dd.pop();
        r.push_back(dd.top()-1);
        dd.push(i);
    }

    ll       result = 0;
    for (int i = 0; i < n; i++) 
        result = max(result, 1LL*(r[n-i-1] - l[i] + 1)*a[i]);
    return result;
}

int main(){
    freopen("rect.inp","r",stdin);
    freopen("rect.out","w",stdout);
    
    int     m, n, y, b;
    vector <int> yellow, blue;

    scanf("%d%d", &m, &n);
    for (int i = 0; i < n; i++) 
    {
        scanf("%d", &y);
        yellow.push_back(y);
        blue.push_back(m-y);
    }

    cout << max(process(yellow, n), process(blue, n));

    return 0;
}