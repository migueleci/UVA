//UVa-821      Page Hopping 
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
vi AdjList[LIM];
int AdjMat[LIM][LIM];

int main(){
  int a,b,caso=1,i,j,k,sum,lim,cant;
  float aver;
  while(gets(tmp) && tmp[0]!='0'){
    aver=0.0; sum=lim=cant=0;
    loop(i,0,LIM) loop(j,0,LIM) AdjMat[i][j]=INF;
    tok=strtok(tmp," ");
    while(tok!=NULL){
      a=atoi(tok);    
      lim=max(lim,a);
      tok=strtok(NULL," ");
      b=atoi(tok);
      lim=max(lim,b);
      tok=strtok(NULL," ");
      if(a==0 && b==0) break;
      AdjList[a].pb(b);
      AdjMat[a-1][b-1]=1;
      //printf("%d %d\n",a,b); 
    }

    loop(k,0,lim) loop(i,0,lim) loop(j,0,lim) 
      AdjMat[i][j] = min(AdjMat[i][j], AdjMat[i][k] + AdjMat[k][j]);
     
    loop(i,0,lim) loop(j,0,lim) if(i!=j && AdjMat[i][j]!=INF) sum+=AdjMat[i][j],cant++;
    aver=(sum*1.0)/cant;
    printf("Case %d: average length between pages = %0.3f clicks\n",caso++,aver);
  }
  return 0;
}