//#include <bits/stdc++.h>
#include <algorithm>
#include <cstdio>
#include <cstring>
#define LIM 25
using namespace std;

int N,n,total,mx,ans,cant;
int tracks[LIM], rec[LIM], save[LIM];

void recordCD(int last){
	for (int i = last+1; i < n; ++i){
		cant+=tracks[i];
		if(cant<=N){
			rec[mx++]=tracks[i];
			recordCD(i);
			mx--;
		}
		cant-=tracks[i];
	}
	if(last==n-1 && (cant>total || (cant==total && mx>ans) ) ){
		for (int j = 0; j < mx; j++) save[j]=rec[j];
		ans=mx;
		total=cant;
	}
}

int main(){
	while(scanf("%d",&N)>0){
  		memset(tracks,0,sizeof tracks);
  		memset(rec,0,sizeof rec);
  		memset(save,0,sizeof save);
  		total=mx=ans=cant=0;
  		scanf("%d",&n);
  		for (int i = 0; i < n; i++) scanf("%d",&tracks[i]);
  		recordCD(-1);
  		for (int i = 0; i < ans; ++i) printf("%d ", save[i]);
  		printf("sum:%d\n", total);
  	}
  	return 0;
}