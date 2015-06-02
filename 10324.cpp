//UVa-10324             Zeros and Ones
//#include <bits/stdc++.h>
#include <algorithm>
#include <cstdio>
#include <string>
#include <cstring>
#include <map>
#include <vector>
#include <math.h>
#define LIM         1005000
#define loop(i,a,b) for(i=a;i<b;i++)
#define SET(a,b)    memset(a,b,sizeof a)
#define pb          push_back
using namespace std;

int main(){
  char cad[LIM];
  int s,f,q,i,casos=1,j,act;
  int acum[LIM];
  while(scanf("%s %d",cad,&q)==2 && cad!=NULL){
    acum[0]=cad[0]-'0';
    loop(i,1,(int)strlen(cad)) acum[i]=acum[i-1]+(cad[i]-'0');
    printf("Case: %d:\n",casos++);
    loop(i,0,q){
      scanf("%d %d",&s,&f);
      act=fabs(acum[f]-acum[s]);
      if(act==f-s || act==0) printf("Yes\n");
      else printf("No\n");
    }
  }
  return 0;
}