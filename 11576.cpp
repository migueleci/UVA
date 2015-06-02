#include <stdio.h>
#include <string.h>
#define MAX_N 400
using namespace std;

char T[MAX_N], P[MAX_N];
int b[MAX_N], n, m,len;

void kmpPreprocess() {
	int j=-1, i=0;
	for(i=0;i<m;i++){
		if(j>=0 && P[i]==P[j]) b[i]=b[j];
		else b[i]=j;
		while(j>=0 && P[i]!=P[j]) j=b[j];
		j++;
	}
}

int kmpSearch() {
	int j=0, i;
	for(i=0;i<n;i++){
		while(j>=0 && T[i]!=P[j]) j=b[j];
		if(j+1==m){
			return 1;
		}
		j++;
	}
	return 0;
}

int kmpSearch2() {
	int j=0, i;
	for(i=1;i<n;i++){
		while(j>=0 && T[i]!=P[j]) j=b[j];
		if(j+1==m){
			return j;
		}
		j++;
	}
	return j;
}

int main(){
	int l,k,nc,i,t,j,x,eq;
	fgets(T, sizeof T, stdin);
	sscanf(T,"%d",&nc);
	for(i=0;i<nc;i++){
		fgets(T, sizeof T, stdin);
		sscanf(T,"%d %d",&n,&t);
		len=0;
		m=n;
		fgets(T, sizeof T, stdin);
		for(j=0;j<t-1;j++){
			//puts(T);
			memset(b,0,sizeof b);
			fgets(P, sizeof P, stdin);
			eq=0;
			//puts(P);
			for(x=0;x<n && eq==0;x++) if(T[x]!=P[x]) eq=1;
			if(eq==1){
				k=0;
				kmpPreprocess();
				k=kmpSearch2();
				//printf("kmp=%d\n",k);
				len+=n-k;
				for(x=0;x<n;x++) T[x]=P[x];
			}
		}
		printf("%d\n", len+n);
	}
	return 0;
}