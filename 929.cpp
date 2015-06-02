//UVa-929      Number Maze
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
#define INF         1e9
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
typedef pair<int,ii > iii;
typedef priority_queue<iii, vector<iii>, greater<iii> > pq;
typedef vector<int> vi;
typedef vector<dd > vdd;
typedef vector<ii > vii;
typedef map<string,int> mci;

int dist[LIM][LIM];
int maze[LIM][LIM];
int dr[]={ 0, 0,-1, 1};
int dc[]={-1, 1, 0, 0};

int main(){
  int c,n,m,i,x,y,t,j,k,cost,d,a,b,alt;
  iii front;
  pq mpq;
  scanf("%d",&c);
  while(c--){
    SET(maze,0);
    SET(dist,0);
    scanf("%d %d",&n,&m);
    loop(i,0,n) loop(j,0,m){
      scanf("%d",&maze[i][j]);
      dist[i][j]=INF;
    } 
    dist[0][0]=maze[0][0];
    mpq.push(iii(dist[0][0],ii(0,0)));

    while(!mpq.empty()){
      front=mpq.top(); mpq.pop();
      d=front.x; a=front.y.x; b=front.y.y;
      loop(j,0,4){
        if(a+dr[j]<0 || b+dc[j]<0 || a+dr[j]>=n || b+dc[j]>=m) continue;
        //printf("maze[%d][%d]=%d dist=%d\n",a+dr[j],b+dc[j],maze[a+dr[j]][b+dc[j]],dist[a+dr[j]][b+dc[j]]);
        if(d+maze[a+dr[j]][b+dc[j]]<dist[a+dr[j]][b+dc[j]]){
          dist[a+dr[j]][b+dc[j]]=d+maze[a+dr[j]][b+dc[j]];
          //printf("dist[%d][%d]=%d\n",a+dr[j],b+dc[j],dist[a+dr[j]][b+dc[j]]);
          mpq.push(iii(dist[a+dr[j]][b+dc[j]],ii(a+dr[j],b+dc[j])));        
        }
      }
    }

    printf("%d\n",dist[n-1][m-1]);
  }
  return 0;
}