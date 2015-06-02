#include <bits/stdc++.h>
#define LIM 110
using namespace std;

int m[LIM];
int e[LIM];

int main(){
	int n,d,r,i,s,x,y,j;
	while(scanf("%d %d %d",&n,&d,&r)>0 && n+d+r>0){
		memset(e,0,sizeof e);
		memset(m,0,sizeof m);
		s=0;
		for(i=0;i<n;i++) scanf("%d",&m[i]); 
		for(i=0;i<n;i++) scanf("%d",&e[i]);
		sort(e,e+n);
		sort(m,m+n);
		for(i=0;i<n;i++){
			if((e[i]+m[n-1-i])-d>0) s+=(e[i]+m[n-1-i])-d;
		}
		if(s>0) printf("%d\n",s*r);
		else printf("0\n"); 
	}
	return 0;
}