//UVa-12808          Banning Balconing
//#include <bits/stdc++.h>
#include <algorithm>
#include <cstdio>
#include <string>
#include <cstring>
#include <map>
#include <set>
#include <vector>
#include <math.h>
#define GRAV        9.81
#define LIM         1005000
#define EPS         1e-9
#define loop(i,a,b) for(i=a;i<b;i++)
#define SET(a,b)    memset(a,b,sizeof a)
#define pb          push_back
#define x           first
#define y           second
using namespace std;

int main(){
  double l,d,h,v,dist,tim;
  int n;
  scanf("%d",&n);
  while(n--){
    scanf("%lf %lf %lf %lf",&l,&d,&h,&v);
    l/=1000;
    d/=1000;
    h/=1000;
    v/=1000;
    tim=sqrt((h*2)/GRAV);
    dist=v*tim;
    if(dist < d-0.5 || dist > d+l+0.5) printf("FLOOR\n");
    else if(dist > d+0.5 && dist < d+l-0.5) printf("POOL\n");
    else printf("EDGE\n");
  }
}