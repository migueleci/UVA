//UVa-12897            Decoding Baby Boos
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
typedef map<char,char> mcc;
typedef pair<char,char> cc;
typedef vector<cc> vcc;

char cad[LIM];
mcc changes;
mcc def;

int main(){
  int nc,r,i;
  char c1[2],c2[2];
  char tmp;
  scanf("%d",&nc);
  while(nc--){
    changes.clear();
    def.clear();
    scanf("%s %d",cad,&r);
    //printf("%s %d\n",cad,r);
    while(r--){
      scanf("%s %s",c1,c2);
      if(def.find(c2[0])==def.end()){
        def[c2[0]]=c1[0];
        changes[c1[0]]=c2[0];
      } 
      if(changes.find(c2[0])!=changes.end()){
        def[changes[c2[0]]]=c1[0];
        changes[c1[0]]=changes[c2[0]];
        changes.erase(c2[0]);
      }
    }
    //loop(i,0,changes.size()) if(def.find(changes[i].x)==def.end()) def[changes[i].x]=changes[i].y;
    loop(i,0,(int)strlen(cad)) if(def.find(cad[i])!=def.end()) cad[i]=def[cad[i]];
    printf("%s\n",cad);
  }
  return 0;
}