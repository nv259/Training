#include "iostream"
#include "cstdio"
//#include "conio.h"

using namespace std;

int n, m, res;
char a[21][21];

void nhap() {
    cin>>m>>n;
    for(int i=0;i<m;++i)
    	for(int j=0;j<n;++j)
    		cin>>a[i][j];
}    

bool check1(int x1,int y1,int x2,int y2) {
    for(int i=x1;i<x2;++i) for(int j=y1;j<y2;++j) if(a[i][j]!=0) return true;
    return false;
}    

bool checkout(int x1,int y1,int x2,int y2, int xx1,int yy1,int xx2,int yy2) {
    for(int i=x1;i<x2;++i) for(int j=y1;j<y2;++j) {
        if(i>=xx1 && i<xx2 && j>=yy1 && j<yy2) continue;
        if(a[i][j]!=0) return true;
    }    
    return false;
}    

void phu(int x1,int y1,int x2,int y2) {
    for(int i=x1;i<x2;++i) for(int j=y1;j<y2;++j) a[i][j]=0;
}    

void cat(int x1,int y1,int x2,int y2) {
//    cout<<x1<<" "<<y1<<" "<<x2<<" "<<y2<<" "<<res<<endl;
    
    if(x1==x2 || y1==y2) return;
    for(int d=x1+1;d<x2;++d) {
        bool ok=true;
        for(int c=y1;c<y2;++c) if(a[d-1][c]==a[d][c] && a[d][c]!=0) {
            ok=false;
            break;
        }    
//            cout<<"aaa"<<endl;
        if(ok && check1(x1,y1,d,y2) && check1(d,y1,x2,y2)) {
            ++res;
            cat(x1,y1,d,y2);
            cat(d,y1,x2,y2);
            return;
        }    
    }    
    for(int c=y1+1;c<y2;++c) {
        bool ok=true;
        for(int d=x1;d<x2;++d) if(a[d][c-1]==a[d][c] && a[d][c]!=0) {
            ok=false;
            break;
        }    
        if(ok && check1(x1,y1,x2,c) && check1(x1,c,x2,y2)) {
            ++res;
            cat(x1,y1,x2,c);
            cat(x1,c,x2,y2);
            return;
        }    
    }    
    for(int d=x1;d<x2-1;++d)
    	for(int c=y1;c<y2-1;++c) {
    	    bool ok1, ok2, ok3, ok4;
    	    ok1=ok2=ok3=ok4=true;
    	    for(int t=y1;t<=c;++t) if(a[d][t]==a[d+1][t] && a[d][t]!=0) {
    	        ok1=false;
    	        break;
    	    }    
    	    for(int t=x1;t<=d;++t) if(a[t][c]==a[t][c+1] && a[t][c]!=0) {
    	        ok2=false;
    	        break;
    	    }    
    	    for(int t=c+1;t<y2;++t) if(a[d][t]==a[d+1][t] && a[d][t]!=0) {
    	        ok3=false;
    	        break;
    	    }    
    	    for(int t=d+1;t<x2;++t) if(a[t][c]==a[t][c+1] && a[t][c]!=0) {
    	        ok4=false;
    	        break;
    	    }    
    	    if(ok1 && ok2 && check1(x1,y1,d+1,c+1) && checkout(x1,y1,x2,y2,x1,y1,d+1,c+1)) {
    	        ++res;
    	        cat(x1,y1,d+1,c+1);
    	        phu(x1,y1,d+1,c+1);
    	        cat(x1,y1,x2,y2);
    	        return;
    	    }    
    	    if(ok2 && ok3 && check1(x1,c+1,d+1,y2) && checkout(x1,y1,x2,y2,x1,c+1,d+1,y2)) {
    	        ++res;
    	        cat(x1,c+1,d+1,y2);
    	        phu(x1,c+1,d+1,y2);
    	        cat(x1,y1,x2,y2);
    	        return;
    	    }    
    	    if(ok1 && ok4 && check1(d+1,y1,x2,c+1) && checkout(x1,y1,x2,y2,d+1,y1,x2,c+1)) {
    	        ++res;
    	        cat(d+1,y1,x2,c+1);
    	        phu(d+1,y1,x2,c+1);
    	        cat(x1,y1,x2,y2);
    	        return;
    	    }    
    	    if(ok4 && ok3 && check1(d+1,c+1,x2,y2) && checkout(x1,y1,x2,y2,d+1,c+1,x2,y2)) {
    	        ++res;
    	        cat(d+1,c+1,x2,y2);
    	        phu(d+1,c+1,x2,y2);
    	        cat(x1,y1,x2,y2);
    	        return;
    	    }    
    	}    
	
}    

void xuly() {
    res=1;
    cat(0,0,m,n);
    printf("%d\n",res);
}

int main() {
    freopen("catbanh.inp","rt",stdin);
    freopen("catbanh.out","wt",stdout);
    nhap();
    xuly();
//    getch();
    return 0;
}    
