//UVa-661          Blowing Fuses
//Accepted
//#include <bits/stdc++.h>
#include <algorithm>
#include <cstdio>
#include <string>
#include <cstring>
#include <map>
#include <set>
#include <vector>
#include <math.h>
#define LIM         105
#define EPS         1e-9
#define loop(i,a,b) for(i=a;i<b;i++)
#define SET(a,b)    memset(a,b,sizeof a)
#define pb          push_back
#define x           first
#define y           second
using namespace std;

int dev[LIM], st[LIM];

int main(){
  int n,m,c,maxc,i,j,op,con,w,seq=1;
  while(scanf("%d %d %d",&n,&m,&c)==3 && n+m+c>0){
    SET(dev,0);
    SET(st,0);
    loop(i,0,n) scanf("%d",&dev[i]);
    maxc=con=0; w=1;
    loop(i,0,m){
      scanf("%d",&op);
      op--;
      if(st[op]==0 && w){
        con+=dev[op];
        st[op]=1;
      } else if(st[op]==1 && w){
        con-=dev[op];
        st[op]=0;
      }
      //printf("con=%d dev=%d\n",con,op);
      if(con>c && w) w=0;
      else {
        maxc=max(maxc,con);
      }
    }
    if(w) printf("Sequence %d\nFuse was not blown.\nMaximal power consumption was %d amperes.\n",seq++,maxc);
    else printf("Sequence %d\nFuse was blown.\n",seq++);
    puts("");
  }
}