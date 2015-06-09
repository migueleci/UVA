//UVa-12894            Perfect Flag
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
  int x0,y0,x1,y1,cx,cy,r,nc;
  int l,w;
  double ll, pos;
  scanf("%d",&nc);
  while(nc--){
    scanf("%d %d %d %d %d %d %d",&x0,&y0,&x1,&y1,&cx,&cy,&r);
    l=fabs(x0-x1);
    w=fabs(y0-y1);
    ll=cx*1.0;
    pos=l/20.0;
    //printf("%lf %lf\n",ll,pos*9+x0*1.0);
    if(10*w!=6*l || l!=r*5 || ll!=pos*9+x0*1.0 || cy!=w/2+y0) printf("NO\n");
    else printf("YES\n");
  }
  return 0;
}