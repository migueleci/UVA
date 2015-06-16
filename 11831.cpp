//UVa-11831          Sticker Collector Robot
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
#define LIM         109
#define UNVISITED   -1
#define loop(i,a,b) for(i=a;i<b;i++)
#define SET(a,b)    memset(a,b,sizeof a)
#define pb          push_back
#define x           first
#define y           second
using namespace std;
typedef pair<int,int> ii;

char mat[LIM][LIM];
ii loc;
char dir,pos;
int ans,n,m;

void ver(){
  if(mat[loc.x][loc.y]=='*'){
    ans++;
    mat[loc.x][loc.y]='.';
  } 
}

void movement(){
  if(dir=='N'){
    if(pos=='D') dir='L';
    else if(pos=='E') dir='O';
    else if(pos=='F') 
      if(loc.x>0 && mat[loc.x-1][loc.y]!='#'){
        loc.x--;
        ver();
      } 
  } else if(dir=='S'){
    if(pos=='D') dir='O';
    else if(pos=='E') dir='L';
    else if(pos=='F') 
      if(loc.x<n-1 && mat[loc.x+1][loc.y]!='#'){
        loc.x++;
        ver();
      } 
  } else if(dir=='L'){
    if(pos=='D') dir='S';
    else if(pos=='E') dir='N';
    else if(pos=='F') 
      if(loc.y<m-1 && mat[loc.x][loc.y+1]!='#'){
        loc.y++;
        ver();
      } 
  } else if(dir=='O'){
    if(pos=='D') dir='N';
    else if(pos=='E') dir='S';
    else if(pos=='F') 
      if(loc.y>0 && mat[loc.x][loc.y-1]!='#'){
        loc.y--;
        ver();
      } 
  }
}

int main(){
  int s,i,j,a,b;
  char ins[50500];
  bool f=false;
  while(scanf("%d %d %d",&n,&m,&s)==3 && s+n+m>0){
    ans=0; f=false;
    loop(i,0,n){
      scanf("%s",mat[i]);
      loop(j,0,m && !f){
        pos=mat[i][j];
        if(pos=='N' || pos=='S' ||pos=='L' || pos=='O'){
          dir=pos;
          loc=ii(i,j);
          mat[i][j]='.';
          f=true;
        }
      }
    }
    scanf("%s",ins);
    loop(i,0,s){
      pos=ins[i];
      movement();
    }
    printf("%d\n", ans);
  }
  return 0;
}