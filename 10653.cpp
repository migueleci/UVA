//UVa-10653      Bombs! NO they are Mines!!
//#include <bits/stdc++.h>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <map>
#include <queue>
#include <math.h>
#define INF         1000000000
#define LIM         1010
#define MAX         11000
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
typedef queue<iii > qiii;
typedef priority_queue<iii > pq;
typedef vector<int> vi;
typedef vector<dd > vdd;
typedef vector<ii > vii;
typedef map<string,int> mci;

int R,C,tr,tc;
int mat[LIM][LIM];
int ban[LIM][LIM];
bool found;
int dr[]={ 0, 0,-1, 1};
int dc[]={-1, 1, 0, 0};

int bfs(int sr, int sc){
  int i,r,c;
  iii front;
  ban[sr][sc]=1;
  qiii pend; pend.push(iii(1,ii(sr,sc)));
  while(!pend.empty() && !found){
    front=pend.front(); pend.pop();
    sr=front.y.x; sc=front.y.y;
    loop(i,0,4 && !found){
      if(sr+dr[i]<0 || sc+dc[i]<0 || sr+dr[i]>=R || sc+dc[i]>=C) continue;
      if(ban[sr+dr[i]][sc+dc[i]]==1 || mat[sr+dr[i]][sc+dc[i]]==-1) continue;
      if(sr+dr[i]==tr && sc+dc[i]==tc) { found=true; break; }
      ban[sr+dr[i]][sc+dc[i]]=1;
      pend.push(iii(front.x+1,ii(sr+dr[i],sc+dc[i])));
    }  
  }
  return front.x;
}

int main(){
  int r,c,b,i,j,n,sr,sc,ans;
  while(scanf("%d %d",&R,&C)==2 && R+C>0){
    SET(mat,0);
    SET(ban,0);
    found=false;
    scanf("%d",&b);
    loop(i,0,b){
      scanf("%d %d",&r,&n);
      loop(j,0,n){
        scanf("%d",&c);
        mat[r][c]=-1;
      }
    }
    scanf("%d %d",&sr,&sc);
    scanf("%d %d",&tr,&tc);
    ans=bfs(sr,sc);
    printf("%d\n",ans);
  }
  return 0;
}