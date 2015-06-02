#include <bits/stdc++.h>
#define LIM 100100
#define x first
#define y second
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
typedef queue<ii> qii; 

qii pos;
qii neg;

int main(){
	int n,i,x,dif;
	ll t;
	while(scanf("%d",&n)>0 && n>0){
		while(!pos.empty()) pos.pop();
		while(!neg.empty()) neg.pop();
		for(i=0;i<n;i++){ 
			scanf("%d",&x); 
			if(x>0) pos.push(ii(x,i));
			else neg.push(ii(x,i));
		}
		t=0;
		while(!pos.empty() || !neg.empty()){
			dif=pos.front().x+neg.front().x;
			if(dif>0){
				t+=abs(neg.front().x)*(abs(neg.front().y-pos.front().y));
				pos.front().x+=neg.front().x;
				neg.pop();
			} else if(dif<0) {
				t+=pos.front().x*(abs(neg.front().y-pos.front().y));
				neg.front().x+=pos.front().x;
				pos.pop();
			} else {
				t+=abs(neg.front().x)*(abs(neg.front().y-pos.front().y));
				pos.pop();
				neg.pop();
			}
		}
		printf("%ld\n",t); 
	}
	return 0;
}