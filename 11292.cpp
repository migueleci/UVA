//UVa-11292 Dragon of Loowater
//#include <bits/stdc++.h>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
#define LIM         100000
#define loop(i,a,b) for(i=a;i<b;i++)
#define SET(a,b)    memset(a,b,sizeof a)
#define pb          push_back
using namespace std;
typedef vector<int> vi;

vi heads, knights;

int main(){
  int h,k,i,j,hh,kk,total;
  while(scanf("%d %d",&h,&k)==2 && h+k>0){
    heads.clear(); knights.clear();
    loop(i,0,h){ scanf("%d",&j); heads.pb(j);}
    loop(i,0,k){ scanf("%d",&j); knights.pb(j);}
    if(h>k) printf("Loowater is doomed!\n");
    else{
      sort(heads.begin(),heads.end());
      sort(knights.begin(),knights.end());
      hh=kk=total=0;
      loop(i,0,h && heads[hh]>knights[i]); kk=i;
      loop(i,0,h && total>=0){
        while(knights[kk]<heads[i] && kk<k) kk++;
        if(kk<k) total+=knights[kk++];
        else total=-1;
      }
      if(total>0) printf("%d\n", total);
      else printf("Loowater is doomed!\n");
    }
  }
  return 0;
}