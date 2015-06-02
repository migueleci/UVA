//UVa-12775      Gift Dilemma 
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
using namespace std;
typedef pair<double,double> dd;
typedef pair<int,int> ii;
typedef pair<int,ii > iii;
typedef priority_queue<iii, vector<iii>, greater<iii> > pq;
typedef vector<int> vi;
typedef vector<dd > vdd;
typedef vector<ii > vii;
typedef map<string,int> mci;
typedef long long int large;

int x,y;
int d;

int GCD(int a, int b){
  int x;
  while(b>0){ x=a; a=b; b=a%b; }
  return a;
}

void extendedEuclid(large a, large b) {
  if (b == 0) { x = 1; y = 0; d = a; return; }
  extendedEuclid(b, a % b);
  int x1 = y, y1 = x - (a / b) * y;
  x = x1; y = y1;
}

int main(){
  int n,casos=1;
  int a,b,c,p,sg,fg;
  scanf("%d",&n);
  while(n--){
  	scanf("%d %d %d %d",&a,&b,&c,&p);
  	sg=GCD(a,b);
  	printf("gcd=%d\n",sg);
  	fg=GCD(sg,c);
  	extendedEuclid(a,b);
  	printf("gcd=%d\n",fg);
  	printf("x=%d y=%d\n", x,y);
  	printf("Case %d:\n",casos++);
  }
  return 0;
}