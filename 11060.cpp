//UVa-11060          Beverages
//Pending
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
#define LIM         109
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
typedef vector<i > vi;
typedef vector<ii > vii;
typedef map<int,string> mis;
typedef map<string,int> msi;

mis bev;
msi bev2;
vi AdjList[LIM];

int main(){
  int n,m,i,j,casos=1;;
  char name[LIM], n2[LIM];
  while(scanf("%d",&n)==1){
    SET(AdjList,0,sizeof AdjList);
    bev.clear();
    bev2.clear();
    loop(i,0,n){
      scanf("%s",name);
      bev[i]=name;
      bev2[name]=i;
    }
    scanf("%d",&m);
    loop(i,0,m){
      scanf("%s %s",name,n2);
      AdjList[bev2[n2]].pb(bev2[name]);
    }


    printf("Case #%d: Dilbert should drink beverages in this order:",casos++);

    printf(".\n\n");
  }
  return 0;
}