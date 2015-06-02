//UVa-12403           Save Setu
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
  int n,acount=0,num;
  char cad[20];
  scanf("%d",&n);
  while(n--){
    scanf("%s",cad);
    if(strcmp(cad,"donate")==0){
      scanf("%d",&num);
      acount+=num;
    } else if(strcmp(cad,"report")==0) printf("%d\n",acount);
  }
  return 0;
}