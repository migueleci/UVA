//#include <bits/stdc++.h>
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#define LIM 200
using namespace std;

int rocks[LIM];
int dist[LIM];

int main(){
	int i,n,m,d,j,md,dd,total;
	char t;
	scanf("%d",&n);
	for(i=0;i<n;i++) {
		md=-1; total=0;
		memset(rocks,0,sizeof rocks);
		memset(dist,0,sizeof dist);
		scanf("%d %d",&m,&d);
		for(j=1;j<=m;j++) {
			scanf(" %c-%d",&t,&dd);
			dist[j]=dd-total;
			total+=dist[j];
			if(t=='S') rocks[j]=1;
		}
		dist[m+1]=d-total;
		m+=2;
		for (j=1;j<m;j++) {
			if(rocks[j]==1){ 
				md=max(md,dist[j]+dist[j+1]);
				j++;
			}
			else md=max(md,dist[j]);
			if(rocks[j]==1) rocks[j]=-1;
		}

		for (j=1;j<m;j++) {
			if(rocks[j]==-1){
				dist[j+1]+=dist[j];
				continue;
			}
			md=max(md,dist[j]);
		}

		printf("Case %d: ",i+1);
		if(md>0) printf("%d\n",md);
		else printf("%d\n",d);
	}
	return 0;
}