//UVa-10189     Minesweeper
//#include <bits/stdc++.h>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
#include <math.h>
#define LIM         110
#define loop(i,a,b) for(i=a;i<b;i++)
#define SET(a,b)    memset(a,b,sizeof a)
#define pb          push_back
using namespace std;
typedef vector<int> vi;

char tmp[LIM];
char mat[LIM][LIM];
char *tok;

int df[]={ 0, 0,-1, 1,-1, 1,-1, 1};
int dc[]={-1, 1, 0, 0, 1,-1,-1, 1};
int n,m;
int vis[LIM][LIM];
int ans[LIM][LIM];

void fill(int a, int b){
  if(a<0 || b<0 || a>=n || b>=m || mat[a][b]!='.') return;
  ans[a][b]++;
}

void mine(int a, int b){
  int i;
  vis[a][b]=1;
  ans[a][b]=-1;
  loop(i,0,8) fill(a+df[i],b+dc[i]);
}

int main(){
  int i,j,casos=1;
  gets(tmp);
  sscanf(tmp,"%d %d",&n,&m);
  while(n+m>0){
    SET(vis,0);
    SET(ans,0);
    SET(mat,0);
    loop(i,0,n) gets(mat[i]);
    loop(i,0,n) loop(j,0,m) if(mat[i][j]=='*') mine(i,j);
    printf("Field #%d:\n", casos++);
    loop(i,0,n){
      loop(j,0,m){
        if(ans[i][j]==-1) printf("*");
        else printf("%d", ans[i][j]);
      }
      puts("");
    }

    gets(tmp);
    sscanf(tmp,"%d %d",&n,&m);
    if(n+m>0) puts("");
  }
  return 0;
}