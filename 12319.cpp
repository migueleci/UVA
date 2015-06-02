//UVa-12319      Edgetown's Traffic Jams
//#include <bits/stdc++.h>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <map>
#include <queue>
#include <math.h>
#define INF         1000000000
#define LIM         110
#define MAX         11000
#define UNVISITED   -1
#define loop(i,a,b) for(i=a;i<b;i++)
#define SET(a,b)    memset(a,b,sizeof a)
#define pb          push_back
#define x           first
#define y           second
using namespace std;
typedef pair<double,double> dd;
typedef pair<int,int> ii;
typedef pair<int,ii > iii;
typedef priority_queue<iii > pq;
typedef vector<int> vi;
typedef vector<dd > vdd;
typedef vector<ii > vii;
typedef map<string,int> mci;

char tmp[MAX];
char *tok;
int n,A,B;
vi OldAdjList[LIM];
vi NewAdjList[LIM];
int OldAdjMat[LIM][LIM];
int NewAdjMat[LIM][LIM];

int main(){
  int a,b,caso=1,i,j,k,OldSum,NewSum,lim,OldCant,NewCant;
  double OldAver, NewAver;
  gets(tmp);
  sscanf(tmp,"%d",&n);
  while(n!=0){
    OldAver=NewAver=0.0; 
    OldSum=OldCant=0;
    NewSum=NewCant=0;
    SET(OldAdjList,0);
    SET(NewAdjList,0);
    loop(i,0,n) loop(j,0,n) OldAdjMat[i][j]=INF,NewAdjMat[i][j]=INF;
    loop(i,0,n){
    	gets(tmp);
    	tok=strtok(tmp," ");
    	a=atoi(tok);
    	//printf("a=%d\n",a);
    	tok=strtok(NULL," ");
	    while(tok!=NULL){
	      b=atoi(tok);
	      //printf("b=%d\n",b);
	      tok=strtok(NULL," ");
	      OldAdjList[a-1].pb(b-1);
	      OldAdjMat[a-1][b-1]=1;
	    }	
    }
    loop(i,0,n){
    	gets(tmp);
    	tok=strtok(tmp," ");
    	a=atoi(tok);
    	tok=strtok(NULL," ");
	    while(tok!=NULL){
	      b=atoi(tok);
	      tok=strtok(NULL," ");
	      NewAdjList[a-1].pb(b-1);
	      NewAdjMat[a-1][b-1]=1;
	    }	
    }
    gets(tmp);
    sscanf(tmp,"%d %d",&A,&B);

    loop(k,0,n) loop(i,0,n) loop(j,0,n){
    	OldAdjMat[i][j] = min(OldAdjMat[i][j], OldAdjMat[i][k] + OldAdjMat[k][j]);
    	NewAdjMat[i][j] = min(NewAdjMat[i][j], NewAdjMat[i][k] + NewAdjMat[k][j]);
    }
    bool ans=true;
    loop(i,0,n) loop(j,0,n)
    	if(i!=j && A*OldAdjMat[i][j]+B<NewAdjMat[i][j]) ans=ans&&false;

    if(ans) puts("Yes");
    else puts("No");
    gets(tmp);
  	sscanf(tmp,"%d",&n);
  }
  return 0;
}