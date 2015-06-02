//UVa-558    Wormholes
//#include <bits/stdc++.h>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <queue>
#include <math.h>
#define INF         1000000000
#define LIM         1010
#define UNVISITED   -1
#define loop(i,a,b) for(i=a;i<b;i++)
#define SET(a,b)    memset(a,b,sizeof a)
#define pb          push_back
#define x           first
#define y           second
using namespace std;
typedef pair<double,double> dd;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<dd > vdd;
typedef vector<ii > vii;
typedef map<string,int> mci;

vii AdjList[LIM];
int dist[LIM];

int main(){
  int c,n,m,i,x,y,t,j,k;
  bool hasNegativeCycle;
  ii v;
  scanf("%d",&c);
  while(c--){
    SET(AdjList,0);
    SET(dist,0);
    scanf("%d %d",&n,&m);
    loop(i,0,m){
      scanf("%d %d %d",&x,&y,&t);
      AdjList[x].pb(ii(y,t));
    }
    loop(i,0,n-1) loop(j,0,n) loop(k,0,(int)AdjList[j].size()){
      v=AdjList[j][k];
      dist[v.x]=min(dist[v.x],dist[j]+v.y);
    }

    hasNegativeCycle=false;
    loop(i,0,n) loop(j,0,(int)AdjList[i].size()){
      v=AdjList[i][j];
      if(dist[v.x]>dist[i]+v.y) hasNegativeCycle=true;
    }
    if(hasNegativeCycle) printf("possible\n");
    else printf("not possible\n");
  }
  return 0;
}