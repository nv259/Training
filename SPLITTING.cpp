#include    <bits/stdc++.h>

using namespace std;
//////////////////////////
const   int N = 1e6;//5e5+5;

int     n, k, first, len, sum[N], cleft, cright, cnt, cnt_ans, ans[N];
char    s[N], maximum[N], other[N];

void    enter(){
    scanf("%d%d", &n, &k);
    scanf("%s", s+1);
}

void    init(){
    bool    check = true;
    first = 1;
    cleft = 1;
    for (int i = 1; i <= n; i++)    
    {
        if (check && s[i] == '0') { cleft = i+1; continue; } 
        maximum[++len] = s[i];
        check = false;
        if (n-len == k-1) break;    
    }
    cright = cleft + len - 1;
    for (int i = 1; i <= n; i++) 
        sum[i] = sum[i-1] + s[i] - '0';
}

bool    compare(int pos, int pos_max){
    int     cr = pos+len-1,
            cr_max = pos_max+len-1;

    while (s[pos] == maximum[pos_max] && pos_max <= cr_max && pos <= cr) { pos_max++; pos++; }
    
    if (pos_max > cr_max || pos > cr) 
        if (sum[pos-len-1] + sum[n] - sum[pos-1] > sum[pos_max-len-1] + sum[n] - sum[pos_max-1]) return true;
        else return false;

    if (s[pos] < maximum[pos_max]) return false;
    if (s[pos] > maximum[pos_max]) return true;
}

void    convert(int x){
    while (x)
    {
        other[++cnt] = x%10 + '0';
        x /= 10; 
    }
    for (int i = 1; i <= cnt/2; i++) swap(other[i], other[cnt-i+1]);
}

void    calc(){
    int     nho = 0;
    cnt_ans = len+1;

    for (int i = first+len-1; i >= first; i--)
    {
        if (cnt == 0) ans[cnt_ans--] = (nho + (maximum[i] - '0'));
        else    ans[cnt_ans--] = (nho + (maximum[i] - '0') + (other[cnt--] - '0'));
        nho = ans[cnt_ans+1]/10;
        ans[cnt_ans+1] %= 10;
    }   
    if (nho) ans[cnt_ans--] = 1;
}

void    solve(){
    int     cc = len, run = cright, first_new = 1;
    for (int i = cleft+1; i <= n-len+1; i++) 
    {
        maximum[++cc] = s[++run];
        first_new++;
        if (s[i] == '0') continue;
        if (compare(i, first)) { first = first_new; cleft = i; cright = cleft + len - 1; /*maximum[first+len-1] = s[i+len-1];*/ }
    }
    //cout << maximum;
    int     temp = sum[cleft-1] + sum[n] - sum[cright];
    convert(temp);
    //reserve();
    calc(); 
    
    bool    check = true;
    for (int i = 0; i <= len+1; i++)
    {
        if (check && ans[i] == 0) continue;
        cout << ans[i];
        check = false;
    }
}

int main(){
    freopen("splitting.inp","r",stdin);
    freopen("splitting.out","w",stdout);
    //freopen("a.inp","r",stdin);

    enter();
    init();
    solve();

    return 0;
}