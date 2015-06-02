//UVa-776   Monkeys in a Regular Forest 
//#include <bits/stdc++.h>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
#include <math.h>
#define LIM         220
#define loop(i,a,b) for(i=a;i<b;i++)
#define SET(a,b)    memset(a,b,sizeof a)
#define pb          push_back
using namespace std;
typedef vector<int> vi;

char tmp[LIM];
char *tok;

int df[]={ 0, 0,-1, 1,-1, 1,-1, 1};
int dc[]={-1, 1, 0, 0, 1,-1,-1, 1};
int idx,f,c;
int mat[LIM][LIM];
int ans[LIM][LIM];
int vis[LIM][LIM];
int spa[LIM];

void floodfill(int a, int b, char c1){
  int i,sp;
  if(a<0 || b<0 || a>=f || b>=c || mat[a][b]!=c1 || vis[a][b]!=0) return;
  vis[a][b]=1;
  ans[a][b]=idx;
  sp=idx>9999?4:(idx>999?3:(idx>99?2:(idx>9?1:0)));
  spa[b]=max(spa[b],sp);
  loop(i,0,8) floodfill(a+df[i],b+dc[i],c1);
}

void algor(){
  int i,j,k;
  idx=1;
  SET(vis,0);
  SET(spa,0);
  loop(i,0,f) loop(j,0,c) if(vis[i][j]==0) floodfill(i,j,mat[i][j]), idx++;
  loop(i,0,f){
    loop(j,0,c-1){
      loop(k,0,spa[j]) if(ans[i][j]<pow(10,k+1)) printf(" ");
      printf("%d ",ans[i][j]);
    } 
    loop(k,0,spa[c-1]) if(ans[i][c-1]<pow(10,k+1)) printf(" ");
    printf("%d\n",ans[i][c-1]);
  } puts("%");
}

int main(){
  int i,j,hh,kk,total;
  f=c=i=j=0;
  while(gets(tmp)){
    if(tmp[0]=='%'){ algor(); gets(tmp); f=c=i=j=0; }
    j=0;
    tok=strtok(tmp," ");
    while(tok!=NULL){
      mat[f][j++]=tok[0];
      tok=strtok(NULL," ");
    } if(c==0) c=j;
    f++;
  }
  algor();
  return 0;
}