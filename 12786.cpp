//UVa-12786          Friendship Networks
//Accepted
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
#define SET(a,b)    memset(a,b,sizeof a)
#define pb          push_back
#define x           first
#define y           second
using namespace std;
typedef pair<double,double> dd;
typedef pair<int,int> ii;
typedef pair<int,ii > iii;
typedef priority_queue<iii, vector<iii>, greater<iii> > pq;
typedef vector<int> vi;
typedef vector<dd > vdd;
typedef vector<ii > vii;
typedef map<string,int> mci;

vector<int> deg;

int main(){
  int n,i,j,val, tim;
  while(scanf("%d",&n)==1){
    deg.clear();
    loop(i,0,n){
      scanf("%d",&val);
      deg.pb(val);
    }
    sort(deg.begin(), deg.end(), greater<int>());
    loop(i,0,n-1 && deg[i]>0){
      loop(j,i+1,n && deg[i]>0 && deg[j]>0){
        //printf("i=%d %d, j=%d %d\n",i,deg[i],j,deg[j] );
        if(deg[j]>0){
          deg[j]--; deg[i]--;
        }
      }
      sort(deg.begin()+i+1, deg.end(), greater<int>());
    }
    loop(i,0,n) if(deg[i]!=0) break;
    if(i==n) printf("1\n");
    else printf("0\n");
  }
  return 0;
}