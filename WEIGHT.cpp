#include <bits/stdc++.h>

using namespace std;
////////////////////////

const   int N = 1e6;

stack <int> tack;
int     leftMax[N], leftMin[N], rightMin[N], rightMax[N], n, a[N];

void findmMaxLeftRight() {
    tack = stack<int> {};
    for (int i=1; i<=n; ++i) {
        while (!tack.empty() && a[tack.top()]<a[i]) tack.pop();
        leftMax[i] = tack.empty() ? 0 : tack.top();
        //if (tack.empty() || a[i]<a[tack.top()])
        tack.push(i);
    }

    tack = stack<int> {};

    for (int i=n; i>=1; --i) {
        while (!tack.empty() && a[tack.top()]<= a[i]) tack.pop();
        rightMax[i] = tack.empty() ? n+1 : tack.top();
        tack.push(i);
    }
}

void findmMinLeftRight() {
    for (int i=1; i<=n; ++i) {
        while (!tack.empty() && a[tack.top()]>a[i]) tack.pop();
        leftMin[i] = tack.empty() ? 0 : tack.top();
        //if (tack.empty() || a[i]>a[tack.top()])
        tack.push(i);
    }

    tack = stack<int> {};

    for (int i=n; i>=1; --i) {
        while (!tack.empty() && a[tack.top()]>= a[i]) tack.pop();
        rightMin[i] = tack.empty() ? n+1 : tack.top();
        tack.push(i);
    }
}

void xuly()
{
    long long RES1 = 0, RES2 = 0, RES;
    for (int i = 1; i <= n; i++)
        RES1 += 1LL*(i - leftMin[i])*(rightMin[i] - i)*a[i];
    for (int i = 1; i <= n; i++)
        RES2 += 1LL*(i - leftMax[i])*(rightMax[i] - i)*a[i];

    RES = RES2-RES1;
    cout << RES;
}

int main()
{
    freopen("weight.inp","r",stdin);
    freopen("weight.out","w",stdout);

    scanf("%d", &n);
    for (int i = 1; i <=n; i++) scanf("%d", &a[i]);

    findmMinLeftRight();
    findmMaxLeftRight();
    xuly();

    return 0;
}
