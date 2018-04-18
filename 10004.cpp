// gaeasdasd
//UVa-10004    Bicoloring  asd asdas
//#include <bits/stdc++.h>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <math.h>
#define INF         1000000000
#define LIM         210
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
typedef vector<pair<double ,ii  > > vdii;

vi AdjList[LIM];

int main(){
  int nodes, edges, i, j, u, v;
  while(scanf("%d",&nodes)==1 && nodes>0){
    SET(AdjList,0);
    scanf("%d",&edges);
    loop(i,0,edges){
      scanf("%d %d",&u,&v);
      AdjList[u].pb(v);
      AdjList[v].pb(u);
    }
    queue<int> q; q.push(0);
    vi color(nodes,INF); color[0]=0;
    bool isBipartite=true;
    while(!q.empty() & isBipartite){
      int u=q.front(); q.pop();
      loop(j,0,(int)AdjList[u].size()){
        int nn=AdjList[u][j];
        if(color[nn]==INF){
          color[nn]=1-color[u];
          q.push(nn);
        } else if(color[nn]==color[u]){
          isBipartite=false;
          break;
        }
      }
    }
    if(isBipartite) printf("BICOLORABLE.\n");
    else printf("NOT BICOLORABLE.\n");
  }
  return 0;
}
