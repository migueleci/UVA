//UVa-436      Arbitrage (II)
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
#include <queue>
#include <math.h>
#define INF         1e9
#define LIM         35
#define UNVISITED   -1
#define loop(i,a,b) for(i=a;i<b;i++)
using namespace std;
typedef map<string,int> mci;

mci cur;
double AdjMat[LIM][LIM];
char cur1[LIM],cur2[LIM];

int main(){
  int n,i,m,j,k,casos=1;
  double val;
  while(scanf("%d",&n)==1 && n>0){
    cur.clear();
    memset(AdjMat,0,sizeof AdjMat);
    loop(i,0,n){
      scanf("%s",cur1);
      cur[cur1]=i;
    }
    scanf("%d",&m);
    loop(i,0,m){
      scanf("%s %lf %s",cur1,&val,cur2);
      //printf("%s=%d %s=%d %lf\n",cur1,cur[cur1],cur2,cur[cur2],val);
      AdjMat[cur[cur1]][cur[cur2]]=val;
      //AdjMat[cur[cur2]][cur[cur1]]=val;
    }
    loop(k,0,n) loop(i,0,n) loop(j,0,n)
      AdjMat[i][j]=max(AdjMat[i][j],AdjMat[i][k]*AdjMat[k][j]);

    //loop(i,0,n){ loop(j,0,n) printf("%lf ",AdjMat[i][j]); puts(""); }
    //puts(""); 
    printf("Case %d: ", casos++);
    if(AdjMat[0][0]>=1.0) printf("Yes\n");
    else printf("No\n");
  }
  return 0;
}