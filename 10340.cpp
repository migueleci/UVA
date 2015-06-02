//UVa-10340 All in All
//#include <bits/stdc++.h>
#include <algorithm>
#include <cstdio>
#include <cstring>
#define LIM         100000
#define loop(i,a,b) for(i=a;i<b;i++)
#define SET(a,b)    memset(a,b,sizeof a)
using namespace std;

int n, m;
char tmp[LIM],T[LIM],P[LIM];
char* tok;

bool substr(){
  bool ans=false;
  int i=0,j=0;
  while(i<n){
    while(T[i]!=P[j] && i<n) i++;
    while(T[i]==P[j] && i<n && j<m) i++,j++;
  } 
  if (j==m) ans=true;
  return ans;
}

int main(){
  int i,j;
  while(gets(tmp)){
    n=m=0;
    tok=strtok(tmp," ");
    while(tok!=NULL){
      if(m==0){
        m=strlen(tok);
        loop(i,0,m) P[i]=tok[i];
      }else{
        n=strlen(tok);
        loop(i,0,n) T[i]=tok[i];
      }
      tok=strtok(NULL," ");
    }
    if(substr()) printf("Yes\n");
    else printf("No\n");
    SET(T,0);
    SET(P,0);
  }
  return 0;
}