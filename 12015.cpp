//UVa-12015         Google is Feeling Lucky
//Accepted
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

vector<string> ans;

int main(){
  int n,l,i,idx,max,casos=1;
  char tmp[LIM],cad[LIM];
  scanf("%d",&n);
  while(n--){
    max=0; ans.clear();
    printf("Case #%d:\n",casos++);
    loop(i,0,10){
      scanf("%s %d",cad,&idx);
      if(idx>max) {
        max=idx; ans.clear();
        ans.pb(cad);
      } else if(idx==max) ans.pb(cad);
    }
    loop(i,0,(int)ans.size()) printf("%s\n",ans[i].c_str());
  }
}