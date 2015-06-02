//UVa-929      Number Maze
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

char tmp[LIM],n;
char num[LIM];
vi AdjList[LIM];
stack<int> par;
stack<int> node;

void expression(int s){
  int i,j;
  par.push(s);
  while(!par.empty()){
    loop(i,s,n){
      if(tmp[i]=='(') par.push(i);
      else if(tmp[i]==')') {
        if(i-par.top()==1) 
      }
    } 
  }
}

int main(){
  int s=0,val;
  while(gets(tmp)){
    //puts(tmp);
    s=0; n=strlen(tmp);
    while(tmp[s]!='(' && s<n) s++;
    memcpy(num, tmp, min(s,n));  
    val=atoi(num);
    if(s>=n) gets(tmp); s=0; n=strlen(tmp);
    while(tmp[s]!='(' && s<n) s++;
    printf("%d %d\n",val,s);
    expression(s);
  }
  return 0;
}