//UVa-11770      Divisible Group Sums
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
#define LIM         100010
#define UNVISITED   -1
#define loop(i,a,b) for(i=a;i<b;i++)
#define X first
#define Y second
#define pb push_back
#define DFS_WHITE -1
#define DFS_BLACK 1
using namespace std;
typedef pair<int,int> ii;
typedef vector<ii>    vii;
typedef vector<int>   vi;

int numSCC,N,M;
vi AdjList[LIM];
vi dfs_num, dfs_low, visited, S;
int dfsNumberCounter;

void tarjanSCC(int u) {
  int i,j;
  dfs_low[u] = dfs_num[u] = dfsNumberCounter++;
  S.pb(u);
  visited[u] = 1;
  loop(i,0,(int)AdjList[u].size()){
    int v = AdjList[u][i];
    if (dfs_num[v] == DFS_WHITE) tarjanSCC(v);
    if (visited[v]) dfs_low[u] = min(dfs_low[u], dfs_low[v]);
  }

  if(dfs_low[u]==dfs_num[u]){
    numSCC++;
    while(1){
      int nn=S.back();
      S.pop_back();
      visited[nn]=0;
      if(u==nn) break;
    }
  }
}

int main(){
  int n,i,j,a,b;
  scanf("%d",&n);
  loop(i,0,n){
    scanf("%d %d",&N,&M);
    memset(AdjList,0,sizeof AdjList);
    dfs_num.assign(N, DFS_WHITE); 
    dfs_low.assign(N, 0);
    visited.assign(N, 0);
    dfsNumberCounter = numSCC = 0;
    loop(j,0,M){
      scanf("%d %d",&a,&b);
      if(a!=b){
        AdjList[a-1].pb(b-1);
        AdjList[b-1].pb(a-1);
      }
    }
    printf("Case %d: ",i+1);
    loop(j,0,N) if (dfs_num[j] == DFS_WHITE) tarjanSCC(j);
    printf("%d\n",numSCC);
  }
  return 0;
}
