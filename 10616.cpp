//UVa-10616      Divisible Group Sums
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
#define LIM         210
#define UNVISITED   -1
#define loop(i,a,b) for(i=a;i<b;i++)
#define X first
#define Y second
using namespace std;
typedef pair<int,int> ii;

int N,Q,V[LIM],memo[LIM][LIM],D,M;

int value(int id, int w) {
  if (id == N || w == 0) return 0;
  if (memo[id][w] != -1) return memo[id][w];
  if (V[id] > w)         return memo[id][w] = value(id + 1, w);
  return memo[id][w] = max(value(id + 1, w), V[id] + value(id + 1, w - V[id]));
}

int main(){
  int i,setn=1,ans;
  while(scanf("%d %d",&N,&Q)==2 && (N!=0 || Q!=0)){
    memset(memo, -1, sizeof memo);
    loop(i,0,N){
      scanf("%d",&V[i]);
    } 
    ans=0;
    printf("SET %d:\n",setn++);
    loop(i,0,Q){
      scanf("%d %d",&D,&M);
      ans=value(0,M);
      printf("QUERY %d: %d\n",i+1,ans);
    } 
  }
  return 0;
}