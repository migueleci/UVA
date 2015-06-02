//UVA-10862     Connect the Cable Wires 
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
#define LIM         2010
#define UNVISITED   -1
#define loop(i,a,b) for(i=a;i<b;i++)
#define X first
#define Y second
using namespace std;
typedef pair<int,int> ii;

int f[LIM];
  
void fib(){
  f[1] = f[2] = 1;
  for (int i = 2; i < LIM; i++)
      f[i] = f[i-1] + f[i-2];
}

int main(){
  fib();
  int n;
  while(scanf("%d",&n)==1 && n>0){
    printf("%d\n",f[2*n]);
  }
  return 0;
}