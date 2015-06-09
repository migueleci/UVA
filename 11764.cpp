//UVa-11764           Jumping Mario
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
#define LIM         1005000
#define EPS         1e-9
#define loop(i,a,b) for(i=a;i<b;i++)
#define SET(a,b)    memset(a,b,sizeof a)
#define pb          push_back
#define x           first
#define y           second
using namespace std;

int main(){
  int n,t,l,hj,lj,casos=1,i,ant;
  scanf("%d",&n);
  while(n--){
    scanf("%d",&t);
    hj=lj=0;
    ant=-1;
    loop(i,0,t){
      scanf("%d",&l);
      if(ant!=-1){
        if(ant>l) lj++;
        else if(ant<l) hj++;
      }
    ant=l;
    }
    printf("Case %d: %d %d\n",casos++,hj,lj);
  }
}