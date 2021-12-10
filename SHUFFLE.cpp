#include <bits/stdc++.h>

using namespace std;
//////////////////////////     
struct data
{
	int front;
	int behind;
} typedef data;

data 	dlist [500005];
int 	n, x, Begin, End;

void	init(){
	scanf("%d%d", &n, &x);
	for (int i=1; i<=n; i++)
    {
    	dlist[i].front=i-1;
    	dlist[i].behind=i+1;
    }
}

void	run(){
	for (int i=1; i<=x; i++)
    {
    	int a, b;
    	scanf("%d%d", &a, &b);
    	// Xoa node;
    	dlist[dlist[a].front].behind = dlist[a].behind;
    	dlist[dlist[a].behind].front = dlist[a].front;
    	//Chen node;
    	dlist[dlist[b].front].behind = a;
    	dlist[a].front = dlist[b].front;
    	dlist[a].behind = b;
		dlist[b].front = a;
    }
}

void	find()
    for (int i=1; i<=n; i++)
    {
        if (dlist[i].front==0)
    		Begin = i;
    	if (dlist[i].behind==n+1)
    		End = i;
    }
}

void	print(){
	while (true)
    {
    	if (Begin==End)
		{
    		cout<<End;
    		break;
		}
        cout<<Begin<<" ";
    	Begin = dlist[Begin].behind;
	}
}

int main ()
{
    freopen("shuffle.inp","r",stdin);
    freopen("shuffle.out","w",stdout);
   
    init();
    run();
	find();
    print();
    
   	return 0;
}
