//UVa-12468            Zapping
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
  int c1,c2;
  while(scanf("%d %d",&c1,&c2)==2 && c1+c2>-1){
    if(c1>c2) swap(c1,c2);
    printf("%d\n",min(c2-c1,99-c2+c1+1));
  }
}