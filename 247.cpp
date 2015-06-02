//UVa-247     Calling Circles
//#include <bits/stdc++.h>
#include <algorithm>
#include <cstdio>
#include <string>
#include <cstring>
#include <map>
#include <vector>
#include <math.h>
#define LIM         110
#define loop(i,a,b) for(i=a;i<b;i++)
#define SET(a,b)    memset(a,b,sizeof a)
#define pb          push_back
using namespace std;
typedef vector<int> vi;
typedef map<string,int> msi;
typedef map<int,string> mis;

char n2[LIM];
char tmp[LIM];
char n1[LIM];
char mat[LIM][LIM];
vi AdjList[LIM];
vector<string> circle[LIM];
msi nodes;
mis names;

int df[]={ 0, 0,-1, 1,-1, 1,-1, 1};
int dc[]={-1, 1, 0, 0, 1,-1,-1, 1};
int n,m;
int vis[LIM];
int ans[LIM][LIM];

bool calls(int s, int c){
  int i;
  bool ans, ins=false;
  vis[s]=1;
  loop(i,0,AdjList[s].size()){
    if(vis[AdjList[s][i]]==0) ans=calls(AdjList[s][i],c);
    else{
      circle[c].pb(names[s]);
      return true;
    } 
    if(ans && !ins) circle[c].pb(names[s]), ins=true;
  } 
}

void call_circle(int s, int c){
  int i;
  vis[s]=1;
  loop(i,0,AdjList[s].size()) if(vis[AdjList[s][i]]==0) calls(AdjList[s][i],c);
  circle[c].pb(names[s]);
}

int main(){
  int i,j,casos=1,num=0, cur;
  scanf("%d %d",&n,&m);
  while(n+m>0){
    nodes.clear();
    names.clear();
    SET(vis,0);
    SET(cricle,0);
    loop(i,0,m){
      scanf("%s %s", n1,n2);
      if(nodes.find(n1)==nodes.end()) nodes[n1]=num, names[num++]=n1;
      if(nodes.find(n2)==nodes.end()) nodes[n2]=num, names[num++]=n2;
      AdjList[nodes[n1]].pb(nodes[n2]);
    } 
    cur=0;
    loop(i,0,n) if(vis[i]==0) call_circle(i,cur++);

    printf("Calling circles for data set %d:\n", casos++);
    loop(i,0,cur){
      printf("%s\n",circle[i][0]);
      loop(j,1,circle[i].size() 
        printf(", %s", circle[i][j]);
      puts("");
    }

    scanf("%d %d",&n,&m);
    if(n+m>0) puts("");
  }
  return 0;
}