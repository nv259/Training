#define taskname "RACE"
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <stack>
using namespace std;
const int maxN = 1e5 + 1;
int n, a[maxN], b[maxN], ida[maxN], idb[maxN];
bool matchA[maxN], matchB[maxN];

void ReadInput()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        ida[i] = i;
    }
    for (int i = 1; i <= n; ++i)
    {
        cin >> b[i];
        idb[i] = i;
    }
    sort(ida + 1, ida + n + 1, [](int i, int j)
    {
        return a[i] < a[j];
    });
    sort(idb + 1, idb + n + 1, [](int i, int j)
    {
        return b[i] < b[j];
    });
    fill(matchA + 1, matchA + n + 1, false);
    fill(matchB + 1, matchB + n + 1, false);
}

void Solve()
{
    stack<int> S;
    int j = 1;
    for (int i = 1; i <= n; ++i)
    {
		// Observe ida[i] horse
        while (j <= n && b[idb[j]] < a[ida[i]])
            S.push(idb[j++]);
        if (!S.empty())
        {
            cout << ida[i] << ' ' << S.top() << '\n';
            matchA[ida[i]] = true;
            matchB[S.top()] = true;
            S.pop();
        }
    }
    j = n;
    for (int i = 1; i <= n; ++i)
    {
        if (matchA[ida[i]]) continue;
        while (matchB[idb[j]]) --j;
        cout << ida[i] << ' ' << idb[j] << '\n';
        --j;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen(taskname".INP", "r", stdin);
    freopen(taskname".OUT", "w", stdout);
    ReadInput();
    Solve();
}
