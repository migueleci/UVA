//UVa-12896          Mobile SMS
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
typedef pair<int,int> ii;
typedef map<ii, char> miic;

int num[LIM], tim[LIM];
miic let;

int main(){
  int nc,l,i;
  let[ii(1,1)]='.';
  let[ii(1,2)]=',';
  let[ii(1,3)]='?';
  let[ii(1,4)]='"';
  let[ii(2,1)]='a';
  let[ii(2,2)]='b';
  let[ii(2,3)]='c';
  let[ii(3,1)]='d';
  let[ii(3,2)]='e';
  let[ii(3,3)]='f';
  let[ii(4,1)]='g';
  let[ii(4,2)]='h';
  let[ii(4,3)]='i';
  let[ii(5,1)]='j';
  let[ii(5,2)]='k';
  let[ii(5,3)]='l';
  let[ii(6,1)]='m';
  let[ii(6,2)]='n';
  let[ii(6,3)]='o';
  let[ii(7,1)]='p';
  let[ii(7,2)]='q';
  let[ii(7,3)]='r';
  let[ii(7,4)]='s';
  let[ii(8,1)]='t';
  let[ii(8,2)]='u';
  let[ii(8,3)]='v';
  let[ii(9,1)]='w';
  let[ii(9,2)]='x';
  let[ii(9,3)]='y';
  let[ii(9,4)]='z';
  let[ii(0,1)]=' ';
  scanf("%d",&nc);
  while(nc--){
    scanf("%d",&l);
    loop(i,0,l) scanf("%d",&num[i]);
    loop(i,0,l) scanf("%d",&tim[i]);
    loop(i,0,l) printf("%c", let[ii(num[i],tim[i])]);
    puts("");
  }
  return 0;
}