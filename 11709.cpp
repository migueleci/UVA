//UVa-11709    Trust groups 
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
typedef vector<pair<double ,ii  > > vdii;
typedef map<string,int> mci;

vi AdjList[LIM];
mci persons;
char tmp[30], tmp2[30];

vi dfs_num, dfs_low, S, visited;
int dfsNumberCounter,ans;

void tarjanSCC(int u){
  int i,j;
  dfs_low[u]=dfs_num[u]=dfsNumberCounter++;
  S.pb(u);
  visited[u]=1;
  loop(i,0,(int)AdjList[u].size()){
    int v=AdjList[u][i];
    if(dfs_num[v]==UNVISITED) tarjanSCC(v);
    if(visited[v]) dfs_low[u]=min(dfs_low[u],dfs_low[v]);
  }
  if(dfs_low[u]==dfs_num[u]){
    ans++;
    while(1){
      int nn=S.back();
      S.pop_back();
      visited[nn]=0;
      if(u==nn) break;
    }
  }
}

int main(){
  int p,t,i,j;
  gets(tmp);
  sscanf(tmp,"%d %d",&p,&t);
  while(p+t>0){
    persons.clear();
    SET(AdjList,0);
    loop(i,0,p){
      gets(tmp);
      //printf("node=%s %d\n",tmp,i );
      persons[tmp]=i;
    }
    //for (map<string,int>::iterator it=persons.begin(); it!=persons.end(); it++)
      //cout << it->first << " => " << it->second << '\n';
    loop(i,0,t){
      gets(tmp);
      gets(tmp2);
      AdjList[persons[tmp]].pb(persons[tmp2]);
      //AdjList[persons[tmp2]].pb(persons[tmp]);
      //printf("u=%s u=%d v=%s v=%d\n",tmp, persons[tmp],tmp2,persons[tmp2]);
    }
    ans=dfsNumberCounter=0;
    dfs_num.assign(p,UNVISITED); dfs_low.assign(p,0); visited.assign(p,0);
    loop(i,0,p) if(dfs_num[i]==UNVISITED) tarjanSCC(i);
    printf("%d\n",ans );
    gets(tmp);
    sscanf(tmp,"%d %d",&p,&t);
  }
  return 0;
}