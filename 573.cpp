//UVa-573          The Snail
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
  double pos,up,fac;
  int h,u,d,f,i;
  while(scanf("%d %d %d %d",&h,&u,&d,&f)==4 && h!=0){
    i=1; up=u*1.0; pos=up;
    fac=(double)(u*f)/100.0;
    //printf("%d %d\n",pos<EPS,fabs(pos-h)<EPS);
    while(pos>0.0 && pos<=h){
      //printf("pos=%0.2lf        Up=%0.2lf\n",pos,up);
      pos-=d;
      //printf("pos=%0.2lf %d\n",pos,d);
      if(pos<0.0) break;
      i++;
      up-=fac;
      if(up<0.0) fac=up=0;
      pos+=up;
    }
    //printf("POS=%lf\n", pos);
    if(pos>=h) printf("success on day %d\n",i);
    else printf("failure on day %d\n",i);
  }
  return 0;
}