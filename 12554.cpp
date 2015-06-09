//UVa-12554           A Special "Happy Birthday" Song!!!
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
#define LIM         105
#define EPS         1e-9
#define loop(i,a,b) for(i=a;i<b;i++)
#define SET(a,b)    memset(a,b,sizeof a)
#define pb          push_back
#define x           first
#define y           second
using namespace std;

vector<string> names;

int main(){
  int n,i;
  char cad[LIM];
  string song[]={ "Happy", "birthday", "to", "you", "Happy", "birthday", 
                  "to", "you", "Happy", "birthday", "to", "Rujia", "Happy", 
                  "birthday", "to", "you"};
  names.clear();
  scanf("%d",&n);
  loop(i,0,n){
    scanf("%s",cad);
    names.pb(cad);
  }
  i=0;
  while(true){
    printf("%s: %s\n",names[i%n].c_str(),song[i%16].c_str());
    i++;
    if(i%16==0 && i>n) break;
  }
}