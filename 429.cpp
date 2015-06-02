//UVa-429    Word Transformation 
//#include <bits/stdc++.h>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <math.h>
#define LIM         210
#define loop(i,a,b) for(i=a;i<b;i++)
#define SET(a,b)    memset(a,b,sizeof a)
#define pb          push_back
using namespace std;
typedef vector<int> vi;

char tmp[LIM];
char s[LIM];
char t[LIM];
char *tok;

vi adjList[LIM];

int df[]={ 0, 0,-1, 1,-1, 1,-1, 1};
int dc[]={-1, 1, 0, 0, 1,-1,-1, 1};
int idx,f,c,node;
int ans[LIM][LIM];
int vis[LIM];
int spa[LIM];

char dic[LIM][LIM];

int find_dic_s(){int i; loop(i,0,node) if(strcmp(s,dic[i])==0) return i; return 0;}
int find_dic_t(){int i; loop(i,0,node) if(strcmp(t,dic[i])==0) return i; return 0;}

int bfs(){
  int c=0,st,ta,i,v,cant,j;
  bool ffind=false;
  queue<int> pend;
  SET(vis,0);
  st=find_dic_s();
  ta=find_dic_t();
  if(st==ta) return 0;
  vis[st]++;
  pend.push(st);
  while(!pend.empty() && !ffind){
    c++;
    cant=pend.size();
    loop(j,0,cant && !ffind){
      v=pend.front(); pend.pop();
      loop(i,0,adjList[v].size() && !ffind){
        if(vis[adjList[v][i]]==0){
          pend.push(adjList[v][i]);
          vis[adjList[v][i]]++;
        } 
        if(adjList[v][i]==ta) ffind=true;
      }
    }
  }
  return c;
}

int comp(int a, int b){
  int i,j,diff=0, lim;
  lim=max(strlen(dic[a]),strlen(dic[b]));
  loop(i,0,lim && diff<2) if(dic[a][i]!=dic[b][i]) diff++;
  return diff;
}

void conections(){
  int i,j,k;
  SET(adjList,0);
  loop(i,0,node) loop(j,i+1,node) if(comp(i,j)==1) adjList[i].pb(j), adjList[j].pb(i);
}

int main(){
  int nc;
  gets(tmp);
  sscanf(tmp,"%d",&nc);
  gets(tmp);
  while(nc--){
    SET(dic,0);
    node=0;
    gets(tmp);
    while(tmp[0]!='*'){
      strcpy(dic[node++],tmp);
      gets(tmp);
    }
    conections();
    if(nc>0){
      gets(tmp);
      while(tmp[0]!='\n' && strlen(tmp)>0){
        tok=strtok(tmp," ");
        while(tok!=NULL){
          strcpy(s,tok);
          tok=strtok(NULL," ");
          strcpy(t,tok);
          tok=strtok(NULL," ");
        }
        printf("%s %s %d\n",s,t,bfs());
        gets(tmp);
      }
      puts("");
    } else {
      while(gets(tmp)){
        tok=strtok(tmp," ");
        while(tok!=NULL){
          strcpy(s,tok);
          tok=strtok(NULL," ");
          strcpy(t,tok);
          tok=strtok(NULL," ");
        }
        printf("%s %s %d\n",s,t,bfs());
      }
    }
  }
  return 0;
}