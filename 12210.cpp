#include <bits/stdc++.h>
using namespace std;

int main(){
	int b,s,i,mm,x,y,caso=0;
	while(scanf("%d %d",&b,&s)>0 && b+s>0){
		mm=20000000;
		for(i=0;i<b;i++){
			scanf("%d",&x); 
			mm=min(x,mm);
		}
		for(i=0;i<s;i++) scanf("%d",&y);
		printf("Case %d: ",++caso); 
		if(b>s) printf("%d %d\n",b-s,mm); 
		else printf("0\n"); 
	}
	return 0;
}