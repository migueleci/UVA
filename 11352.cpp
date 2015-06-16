//UVa-11352           Crazy King
//Pending
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
typedef pair<ii,int > iii;
typedef vector<int> vi;
typedef priority_queue<iii, vector<iii>, greater<iii> > pq;
typedef set<ii > sii;
typedef map<int,string> mis;
typedef map<string,int> msi;

int drh[]={-1, 1,-2, 2,-2, 2,-1, 1};
int dch[]={-2,-2,-1,-1, 1, 1, 2, 2};

int drk[]={ 1, 0,-1, 1,-1, 1, 0,-1};
int dck[]={-1,-1,-1, 0, 0, 1, 1, 1};

char mat[LIM][LIM];
ii s,t;
int ans,n,m;
int visited[LIM][LIM];

void moveHorse(int r, int c){
  int i;
  loop(i,0,8){
    if(r+drh[i]>=0 && r+drh[i]<n && c+dch[i]>=0 && c+dch[i]<m && mat[r+drh[i]][c+dch[i]]=='.')
      mat[r+drh[i]][c+dch[i]]='X';
  }
}

void bfs(){
  deque<iii> pend;
  pend.clear();
  int i;
  iii a;
  pend.push_back(iii(s,0));
  while(!pend.empty() && ans<0){
    a=pend.front();
    pend.pop_front();
    loop(i,0,8 && ans<0){
      if(mat[a.x.x+drk[i]][a.x.y+dck[i]]=='.' && visited[a.x.x+drk[i]][a.x.y+dck[i]]==UNVISITED){
        //printf("mat[%d][%d]\n",a.x.x+drk[i],a.x.y+dck[i]);
        pend.push_back(iii(ii(a.x.x+drk[i],a.x.y+dck[i]),a.y+1));
        visited[a.x.x+drk[i]][a.x.y+dck[i]]=a.y;
      }else if(mat[a.x.x+drk[i]][a.x.y+dck[i]]=='B'){
        ans=a.y+1;
      }
    } 
  }
}

int main(){
  int i,j,a,b;
  int casos;
  scanf("%d",&casos);
  while(casos--){
    scanf("%d %d",&n,&m);
    SET(visited, UNVISITED);
    ans=-1;
    loop(i,0,n) scanf("%s",mat[i]);
    loop(i,0,n){
      loop(j,0,m){
        if(mat[i][j]=='Z') moveHorse(i,j);
        else if(mat[i][j]=='A') s=ii(i,j);
      }
    }

    //loop(i,0,n) printf("%s\n", mat[i]);
    bfs();
    if(ans>0) printf("Minimal possible length of a trip is %d\n", ans);
    else printf("King Peter, you can't go now!\n");
  }
  return 0;
}