//UVa-621          Secret Research
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

int main(){
  int n,l;
  char tmp[LIM],cad[LIM];
  gets(tmp);
  sscanf(tmp,"%d",&n);
  while(n--){
    gets(cad);
    l=(int)strlen(cad);
    if(l>2 && cad[l-2]=='3' && cad[l-1]=='5') printf("-\n");
    else if(l>2 && cad[l-1]=='4' && cad[0]=='9') printf("*\n");
    else if(l>3 && cad[0]=='1' && cad[1]=='9' && cad[2]=='0') printf("?\n");
    else if((l==1 && cad[0]=='1') || (l==1 && cad[0]=='4') 
              || (l==2 && cad[0]=='7' && cad[1]=='8'))
      printf("+\n");
  }
}