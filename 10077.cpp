//UVa-10077      The Stern-Brocot Number System asdsa
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
#define LIM         500
#define UNVISITED   -1
#define loop(i,a,b) for(i=a;i<b;i++)
#define X first
#define Y second
using namespace std;
typedef pair<int,int> ii;

int main(){
  int m,n;
  while(scanf("%d %d",&n,&m)==2 && (n>1 || m>1)){
    //printf("OK %d %d\n", n,m);
    while(n+m>2){
      if(n<m){
        printf("L");
        m=m-n;
      } 
      else{
        printf("R");
        n=n-m;
      }
    }
    puts("");
  }
  //printf("###############\n");
  return 0;
}
