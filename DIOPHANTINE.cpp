#include <bits/stdc++.h>

using namespace std;
///////////////////////////

void ext_gcd(int a, int b, int &d, int &x, int &y) {
    if (b == 0) {
        d = a;
        x = 1;
        y = 0;
    }
    else {
        int x1, y1;
        ext_gcd(b, a%b, d, x1, y1);
        x = y1;
        y = x1 - a/b*y1;
    }
}

int main() {
    freopen("diophantine.inp", "r", stdin);
    freopen("diophantine.out", "w", stdout);

	int 	test;
	cin >> test;
	while (test--)
	{
    	int a, b, c, d, x, y;
    	cin >> a >> b >> c;
    	ext_gcd(a, b, d, x, y);
    	if (c%d != 0) cout << "0\n";
    	else {
        	int t1 = ceil(-1.0*c*x/b);
        	if (c*x % b == 0) t1++;
        	int t2 = floor(1.0*c*y/a);
       		if (c*y % a == 0) t2--;
    	    if (t1 <= t2) 
				cout << t2 - t1 + 1 << '\n';
			else
				cout << "0\n";
    	}
	}

    return 0;
}