//UVa-12783             Weak Links
//Accepted
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
#include <set>
#include <queue>
#include <math.h>
#define INF         1e9
#define LIM         1090
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
typedef priority_queue<iii, vector<iii>, greater<iii> > pq;
typedef vector<int> vi;
typedef set<ii > sii;
typedef map<int,string> mis;
typedef map<string,int> msi;

vi AdjList[LIM];
sii ans;
sii::iterator it;
vi dfs_num,dfs_low,dfs_parent,articulation_vertex;
int dfsNumberCounter=0;
int dfsRoot,rootChildren;

void articulationBridge(int u){
  int j,v;
  dfs_low[u]=dfs_num[u]=dfsNumberCounter++;
  loop(j,0,(int)AdjList[u].size()){
    v=AdjList[u][j];
    if(dfs_num[v]==UNVISITED){
      dfs_parent[v]=u;
      if(u==dfsRoot) rootChildren++;
      
      articulationBridge(v);
      
      if(dfs_low[v]>dfs_num[u]) ans.insert(ii(min(u,v),max(u,v)));
      dfs_low[u]=min(dfs_low[u], dfs_low[v]);
    } else if(v!=dfs_parent[u]){
      dfs_low[u]=min(dfs_low[u],dfs_num[v]);
    }
  }
}

int main(){
  int n,m,i,j,casos=1,a,b;

  while(scanf("%d %d",&n,&m)==2 && n+m>0){
    SET(AdjList,0);
    ans.clear();
    dfs_num.assign(n,UNVISITED);
    dfs_low.assign(n,0);
    dfs_parent.assign(n,0);
    articulation_vertex.assign(n,0);
    dfsNumberCounter=0;
    loop(i,0,m){
      scanf("%d %d",&a,&b);
      AdjList[a].pb(b);
      AdjList[b].pb(a);
    }
    loop(i,0,n){
      if(dfs_num[i]==UNVISITED){
        dfsRoot=i;
        rootChildren=0;
        articulationBridge(i);
        articulation_vertex[dfsRoot]=(rootChildren>1);
      }
    }
    printf("%d",(int)ans.size());
    //sort(ans.begin(),ans.end());
    for(it=ans.begin(); it!=ans.end(); it++)
      printf(" %d %d", it->x,it->y);
    puts("");

  }
  return 0;
}