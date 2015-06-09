//UVa-12854            Automated Checking Machine
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
  int p1,p2,p3,p4,p5,t1,t2,t3,t4,t5;
  while(scanf("%d %d %d %d %d",&p1,&p2,&p3,&p4,&p5)==5){
    scanf("%d %d %d %d %d",&t1,&t2,&t3,&t4,&t5);
    t1+=p1; t2+=p2; t3+=p3; t4+=p4; t5+=p5;
    if(t1==0 || t1==2 || t2==0 || t2==2|| t3==0 || t3==2|| t4==0 || t4==2|| t5==0 || t5==2)
      printf("N\n");
    else printf("Y\n");
  }
  return 0;
}