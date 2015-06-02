//UVa-10321            Polygon Intersection
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
typedef pair<double, double> dd;
typedef set<dd> sdd;
typedef vector<dd> vdd;

struct line{ double a,b,c;};

sdd ans;
vdd pol1,pol2;
int n,m;
vector<line> line1,line2;

line points2Line(dd p1, dd p2){
  line l;
  if(fabs(p1.x - p2.x) < EPS) {
    l.a=1.0; l.b=0.0; l.c=-p1.x;
  } else {
    l.a=-(double)(p1.y-p2.y) / (double)(p1.x-p2.x);
    l.b=1.0;
    l.c=-(double)(l.a*p1.x)-p1.y;
  }
  return l;
}

int ccw(dd a0, dd a1, dd a2){
  int result = (a2.x - a1.x)*(a0.y-a1.y) - (a2.y-a1.y)*(a0.x-a1.x);
  if (result < 0) return -1;
  if (result > 0) return 1;
  return 0;
}

bool intss(dd a0,dd a1,dd b0,dd b1){
  if(ccw(a0,a1,b0)*ccw(a0,a1,b1)<=0 && ccw(b0,b1,a0)*ccw(b0,b1,a1)<=0) return true;
  return false;
}

void areIntersect(line l1, line l2){
  dd p;
  //if(areParallel(l1,l2)) return;
  p.x=(l2.b*l1.c-l1.b*l2.c) / (l2.a*l1.b-l1.a*l2.b);
  if(fabs(l1.b)>EPS) p.y=-(l1.a*p.x+l1.c);
  else p.y=-(l2.a*p.x+l2.c);
  ans.insert(p);
}

bool inpol2(dd a){
  int wn=0,i;
  loop(i,0,m)
    if(pol2[i].y <=a.y){ if(pol2[i+1].y>a.y && ccw(a,pol2[i],pol2[i+1])==1) wn++; }
    else if(pol2[i+1].y<=a.y && ccw(a,pol2[i],pol2[i+1])==-1) wn--;
  return !(wn==0);
}

bool inpol1(dd a){
  int wn=0,i;
  loop(i,0,n)
    if(pol1[i].y <=a.y){ if(pol1[i+1].y>a.y && ccw(a,pol1[i],pol1[i+1])==1) wn++; }
    else if(pol1[i+1].y<=a.y && ccw(a,pol1[i],pol1[i+1])==-1) wn--;
  return !(wn==0);
}

int main(){
  int l,i,j;
  double x,y;
  while(scanf("%d",&n)==1 && n>=3){
    ans.clear();
    pol1.clear(); pol2.clear();
    loop(i,0,n){
      scanf("%lf %lf",&x,&y);
      pol1.pb(dd(x,y));
    }
    pol1.pb(pol1[0]);
    scanf("%d",&m);
    loop(i,0,m){
      scanf("%lf %lf",&x,&y);
      pol2.pb(dd(x,y));
    }
    pol2.pb(pol2[0]);

    loop(i,1,n+1) loop(j,1,m+1) 
      if(intss(pol1[i-1],pol1[i],pol2[j-1],pol2[j]))
        if(!(ccw(pol1[i-1], pol1[i], pol2[j-1])==0 && 
              ccw(pol1[i-1], pol1[i], pol2[j])==0))
        areIntersect(points2Line(pol1[i-1],pol1[i]),points2Line(pol2[j-1],pol2[j]));
      
    loop(i,0,n) if(inpol2(pol1[i])) ans.insert(pol1[i]);
    loop(i,0,m) if(inpol1(pol2[i])) ans.insert(pol2[i]);

    printf("%d\n",(int)ans.size()); 
    for(set<dd>::iterator it=ans.begin(); it!=ans.end();it++) 
      printf("%0.2lf %0.2lf\n",it->x+0.0005,it->y+0.0005); 
  }
  return 0;
}