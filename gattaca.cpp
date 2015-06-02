//UVa-11512    GATTACA
//#include <bits/stdc++.h>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <queue>
#include <math.h>
#define INF         1000000000
#define LIM         1010
#define SZ          1010
#define UNVISITED   -1
#define loop(i,a,b) for(i=a;i<b;i++)
#define SET(a,b)    memset(a,b,sizeof a)
#define pb          push_back
#define x           first
#define y           second
using namespace std;
typedef pair<double,double> dd;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<dd > vdd;
typedef vector<pair<double ,ii  > > vdii;
typedef map<string,int> mci;

int gap,len,pos[SZ],tmp[SZ],sa[SZ],lcp[SZ], tsz;
char t[SZ], resp[SZ];

bool gapcmp(int i, int j){
  if(pos[i]!=pos[j]) return pos[i]<pos[j];
  i+=gap, j+=gap;
  return (i<len && j<len)? pos[i]<pos[j] : i>j;
}

void suffixArray(){
  int i,j,k=0;
  if(tsz<=1){ sa[0]=lcp[0]=0; return; }
  loop(i,0,tsz) sa[i]=i,pos[i]=t[i];
  len=tsz, gap=1, tmp[tsz-1]=tmp[0]=1;
  while(tmp[tsz-1]<tsz){
    sort(sa,sa+tsz,gapcmp);
    loop(i,1,tsz) tmp[i]=tmp[i-1]+ gapcmp(sa[i-1],sa[i]);
    loop(i,0,tsz) pos[sa[i]]=tmp[i];
    gap<<=1;
  }
  // Optional for LCP:
  loop(i,0,tsz) if (pos[i]!=tsz){
    j=sa[pos[i]];
    while(t[i+k] == t[j+k]) ++k;
    lcp[pos[i]-1] = k;
    if(k)--k;
  }
}

int main(){
  int n,i;
  gets(t);
  sscanf(t,"%d",&n);
  while(n--){
    SET(sa,0);
    SET(lcp,0);
    SET(tmp,0);
    SET(pos,0);
    gets(t); 
    strcat(t,"]");
    tsz=strlen(t);
    suffixArray();
    //printf("i\tSA[i]\tLCP[i]\tSuffix\n");
    //loop(i,0,tsz)
    //  printf("%2d\t%2d\t%2d\t%s\n", i, sa[i], lcp[i],t+sa[i]);
    int maxLCP=0, idx, ans=1;
    loop(i,0,tsz-1) if(lcp[i]>maxLCP) maxLCP=lcp[i], idx=i;
    i=idx;
    while(lcp[i]>=maxLCP && i<tsz-1) ans++, i++;
    SET(resp,0);
    strncpy(resp, t + sa[idx], maxLCP);
    if(maxLCP>0) printf("%s %d\n",resp,ans);
    else printf("No repetitions found!\n");
  }
  return 0;
}