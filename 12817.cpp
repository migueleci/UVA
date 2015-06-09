//UVa-12817          Sleight of Hand
//#include <bits/stdc++.h>
#include <algorithm>
#include <cstdio>
#include <string>
#include <cstring>
#include <map>
#include <set>
#include <vector>
#include <math.h>
#define LIM         1005000
#define EPS         1e-9
#define loop(i,a,b) for(i=a;i<b;i++)
#define SET(a,b)    memset(a,b,sizeof a)
#define pb          push_back
#define x           first
#define y           second
using namespace std;

int main(){
  double p,r,rv,pr,pp,t;
  int n,i;
  char c[5];
  while(scanf("%lf",&r)==1){
    p=1.0-r;
    //pp=pr=0.0;
    scanf("%d",&n);
    loop(i,0,n){
      scanf("%s %lf",c,&rv);
      if(c[0]=='P') p*=rv,r*=(1-rv);
      else p*=(1.0-rv),r*=rv;
    }
    t=r+p;
    pp=p/t;
    printf("%0.6lf %0.6lf\n",(1.0-pp),pp);
  }
  return 0;
}