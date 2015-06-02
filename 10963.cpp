//UVa-10963        The Swallowing Ground
//#include <bits/stdc++.h>
#include <cstdio>
#include <cmath>
#define LIM         110
#define loop(i,a,b) for(i=a;i<b;i++)
#define SET(a,b)    memset(a,b,sizeof a)
using namespace std;

int main(){
  int casos,cant,x,y,i,gap,hole;
  scanf("%d",&casos);
  while(casos--){
    scanf("%d",&cant);
    gap=-1;
    hole=0;
    loop(i,0,cant){
      scanf("%d %d",&x,&y);
      if(gap==-1) gap=fabs(x-y);
      else if(gap!=fabs(x-y)) hole=1;
    }
    if(!hole) printf("yes\n");
    else printf("no\n");
    if(casos>0) puts("");
  }
  return 0;
}