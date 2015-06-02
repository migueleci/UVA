//UVa-12372        Packing for Holiday
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
  int n,l,w,h,casos=1;
  scanf("%d",&n);
  while(n--){
    scanf("%d %d %d",&l,&w,&h);
    printf("Case %d: ",casos++);
    if(l>20 || w>20 || h>20) printf("bad\n");
    else printf("good\n");
  }
  return 0;
}