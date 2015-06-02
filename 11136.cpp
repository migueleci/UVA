//UVa-11136       Hoax or what
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

int main(){
  int d,i,n,cant,j,ans;
  pq bills;
  minHeap dbills;
  while(scanf("%d",&d)==1 && d>0){
    while(!bills.empty()) bills.pop();
    while(!dbills.empty()) dbills.pop();
    ans=0;
    loop(i,0,d){
      scanf("%d",&n);
      loop(j,0,n){
        scanf("%d",&cant);
        bills.push(cant);
        dbills.push(cant);
      }
      //printf("max=%d min=%d\n",bills.top(),dbills.top() );
      ans+=bills.top()-dbills.top();
      bills.pop();
      dbills.pop();
    }
    printf("%d\n",ans);
  }
  return 0;
}