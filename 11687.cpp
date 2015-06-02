//UVa-11687        Digits
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
typedef vector<int> vi;
typedef map<string,string> ss;

ss lang;

int main(){
  char cad[LIM],tmp[LIM];
  int i;
  gets(cad);
  while(cad[0]!='E'){
    i=0;
    sprintf(tmp,"%s",cad);
    while(true){
      i++;
      sprintf(cad,"%d",(int)strlen(cad));
      if(strcmp(cad,tmp)==0) break;
      sprintf(tmp,"%s",cad);
    }
    printf("%d\n",i);
    gets(cad);
  }
  return 0;
}