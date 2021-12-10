#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

int n,k;
int c[34][34];
int digit,d[34];

void getC()
{
     memset(c,0,sizeof(c));
     for (int i = 0; i <= 32; i++) c[0][i] = 1;
     for (int j = 1; j <= 32; j++)
       for (int i = 1; i <= 32; i++) c[i][j] = c[i - 1][j - 1] + c[i][j - 1];     
};

ll rec(int pos,int p)
{
   if (p < 0) return 0;
   if (!pos) return (p == 0) ? 1 : 0;
   if (d[pos] == 0) return (rec(pos - 1,p - 1));
   else
   {
     ll tmp = rec(pos - 1,p);
     if (p) tmp += c[p - 1][pos - 1];
//     cout << "answer: " << pos << ' ' << p << ' ' << tmp << endl;
     return tmp;
   };
};

ll calc(int x)
{
   //x zeroes in the numbers
//   if (x != 2) return 0;
   ll ret = 0;
   for (int i = 2; i < digit; i++) ret += c[x][i - 1];
//   cout << ret << endl;
   ret += rec(digit - 1,x);
   return ret;
};

ll solve()
{
   if (k > 31) return 0;
   if (!n) return (k == 1) ? 1 : 0;
   digit = 0;  int tmp = n;
   while (tmp)
   {
         d[++digit] = tmp % 2;  tmp /= 2;
   };
   ll ret = calc(k);  if (k == 1) ret++;
   return ret;
};

int main()
{
   freopen("soluong.inp","r",stdin);
   freopen("soluong.out","w",stdout);
    getC();
    while (cin >> n >> k) cout << solve() << endl;
};
