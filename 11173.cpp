//UVa-11173      Grey Codes 
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
#define LIM         10100
#define UNVISITED   -1
#define loop(i,a,b) for(i=a;i<b;i++)
using namespace std;
typedef priority_queue<int> pq;
typedef priority_queue<int, vector<int>, greater<int> > minHeap;

int unrank(int n, int r ){
  int T=0;
  int bp=0,i,b,dd;
  for(i=n-1;i>=0;i--){
    dd=i-1<0?1: 2<<(i-1);
    b=r/dd;
    //printf("b'=%d r=%d i=%d 2i=%d b=%d\n",bp,r,i,dd,b);
    //printf("OK\n");
    if(b!=bp) T+=dd;
    bp=b;
    r-=b*(2<<(i-1));
  }
  return T;
}

int main(){
  int cant,n,r;
  scanf("%d",&cant);
  while(cant--){
    scanf("%d %d",&n,&r);
    printf("%d\n",unrank(n,r) );
  }
  return 0;
}