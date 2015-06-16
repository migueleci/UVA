//UVa-762          We Ship Cheap
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
typedef pair<string,string> ss;
typedef pair<int,int> ii;
typedef pair<ii,int > iii;
typedef vector<int> vi;
typedef deque<ss> vss;
typedef vector<ii> vii;
typedef set<ii > sii;
typedef map<int,string> mis;
typedef map<string,int> msi;

int n,cant,s,t;
vi AdjList[LIM];
vss ans;
vii parent;
mis n2c;
msi c2n;

void bfs(){
  deque<ii> pend;
  pend.clear();
  int i;
  ii a;
  pend.push_back(ii(s,0));
  parent[s].y=0;
  while(!pend.empty()){
    a=pend.front();
    pend.pop_front();
    //printf("%d %s %d\n", a.x,n2c[a.x].c_str(), (int)AdjList[a.x].size());
    loop(i,0,(int)AdjList[a.x].size()){
      //printf("%s %s\n", n2c[a.x].c_str(),n2c[AdjList[a.x][i]].c_str());
      if(parent[AdjList[a.x][i]].y>a.y+1){
        pend.push_front(ii(AdjList[a.x][i],a.y+1));
        parent[AdjList[a.x][i]].y=a.y+1;
        parent[AdjList[a.x][i]].x=a.x;
      }
    } 
  }
}

int main(){
  char c1[5],c2[5];
  int i,a,p;
  bool f=true;
  while(scanf("%d",&n)==1){
    if(!f) puts("");
    else f=false;
    cant=0;
    n2c.clear();
    c2n.clear();
    SET(AdjList,0);
    parent.clear();
    loop(i,0,n){
      scanf("%s %s",c1,c2);
      if(c2n.find(c1)==c2n.end()) {
        n2c[cant]=c1;
        c2n[c1]=cant++;
      }
      if(c2n.find(c2)==c2n.end()) {
        n2c[cant]=c2;
        c2n[c2]=cant++;
      }
      //printf("%s=%d %s=%d\n",c1,c2n[c1],c2,c2n[c2]);
      AdjList[c2n[c2]].pb(c2n[c1]);
      AdjList[c2n[c1]].pb(c2n[c2]);
    }
    scanf("%s %s",c1,c2);
    if(c2n.find(c2)==c2n.end() || c2n.find(c1)==c2n.end()){
      if(strcmp(c2,c1)==0) printf("%s %s\n",c1,c2);
      else printf("No route\n");
    } else {
      s=c2n[c1];
      t=c2n[c2];
      loop(i,0,cant) parent.pb(ii(-1,1000000));
      bfs();
      if(parent[t].y!=1000000){
        ans.clear();
        a=t;
        p=parent[t].x;
        ans.push_front(ss(n2c[p],n2c[a]));
        while(p!=s){
          a=p;
          p=parent[a].x;
          ans.push_front(ss(n2c[p],n2c[a]));
        }
        while(!ans.empty()){
          printf("%s %s\n",ans.front().x.c_str(),ans.front().y.c_str());
          ans.pop_front();
        }
      } else printf("No route\n");
    }
  }
  return 0;
}