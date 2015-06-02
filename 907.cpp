//UVa-907      Winterim Backpacking
//#include <bits/stdc++.h>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <iostream>
#include <map>
#include <queue>
#include <math.h>
#define INF         1e9
#define LIM         625
#define UNVISITED   -1
#define loop(i,a,b) for(i=a;i<b;i++)
#define X first
#define Y second
using namespace std;
typedef pair<int,int> ii;

int n;
ii memo[LIM][LIM];
int travelTime[LIM][LIM], toll[LIM][LIM];

ii go(int cur, int t_left){
  int i;
  //printf("%d %d\n",memo[cur][t_left].X, memo[cur][t_left].Y);
  if(t_left<0) return ii(INF, INF);
  if(cur==n-1) return ii(0,0);
  if(memo[cur][t_left] != ii(-1,-1)) return memo[cur][t_left];
  //puts("OK");
  ii ans=ii(INF,INF);
  loop(i,cur,n) {
    ii next = go(i,t_left - travelTime[cur][i]);
    if(next.X + travelTime[cur][i] < ans.X){
      ans.X = next.X + travelTime[cur][i];
      ans.Y = next.Y + travelTime[cur][i];
    }
  }
  return memo[cur][t_left] = ans;
}

int main(){
  int k,i,j,num;
  while(scanf("%d %d",&n,&k)==2){
    //loop(i,0,n) loop(j,0,n) memo[i][j]=ii(-1,-1);
    memset(memo,-1,sizeof memo);
    memset(travelTime,0,sizeof travelTime);
    memset(toll,0,sizeof toll);
    n++;
    loop(i,0,n){
      scanf("%d",&num);
      loop(j,i,n) travelTime[i][j]=num;
    }
    for(i=n;i>=0;i--) for(j=i;j>=0;j--) if(i!=j) 
      travelTime[j][i]+=travelTime[j+1][i];

    //loop(i,0,n) { loop(j,0,n) printf("%3d ",travelTime[i][j]); puts(""); }

    ii ans=go(0,24);
    printf("%d %d\n",ans.X, ans.Y);
  }
  return 0;
}