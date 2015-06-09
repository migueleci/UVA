//UVa-12820        Cool Word
//#include <bits/stdc++.h>
#include <algorithm>
#include <cstdio>
#include <string>
#include <cstring>
#include <map>
#include <set>
#include <vector>
#include <math.h>
#define LIM         35
#define EPS         1e-9
#define loop(i,a,b) for(i=a;i<b;i++)
#define SET(a,b)    memset(a,b,sizeof a)
#define pb          push_back
#define x           first
#define y           second
using namespace std;
typedef map<char,int> mci;

mci let;
mci::iterator it;
char word[LIM];
int tim[LIM];

int main(){
  int nc=1,n,ans,j;
  while(scanf("%d",&n)==1){
    ans=0;
    while(n--){
      let.clear();
      scanf("%s",word);
      loop(j,0,(int)strlen(word)){
        if(let.find(word[j])==let.end()) let[word[j]]=1;
        else let[word[j]]=let[word[j]]+1;
      }
      SET(tim,0);
      for(it=let.begin();it!=let.end();it++){
        //  printf("%c %d\n", it->first,it->second);
        if(tim[it->second]==0) tim[it->second]=1;
        else break;
      }
      //printf("%d\n", (int)let.size());
      if(it==let.end() && let.size()>1) ans++;
    }
    printf("Case %d: %d\n",nc++,ans);
  }
  return 0;
}