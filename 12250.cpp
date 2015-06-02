//UVa-12250      Language Detection
//#include <bits/stdc++.h>
#include <algorithm>
#include <cstdio>
#include <string>
#include <cstring>
#include <map>
#include <vector>
#include <math.h>
#define LIM         110
#define loop(i,a,b) for(i=a;i<b;i++)
#define SET(a,b)    memset(a,b,sizeof a)
#define pb          push_back
using namespace std;
typedef vector<int> vi;
typedef map<string,string> ss;

ss lang;

int main(){
  char cad[20];
  int casos=1;
  lang.clear();
  lang["HELLO"]="ENGLISH";
  lang["HOLA"]="SPANISH";
  lang["HALLO"]="GERMAN";
  lang["BONJOUR"]="FRENCH";
  lang["CIAO"]="ITALIAN";
  lang["ZDRAVSTVUJTE"]="RUSSIAN";
  gets(cad);
  while(cad[0]!='#'){
    printf("Case %d: ",casos++);
    if(lang.find(cad)!=lang.end()) printf("%s\n",lang[cad].c_str());
    else printf("UNKNOWN\n");
    gets(cad);
  }
  return 0;
}