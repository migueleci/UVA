//UVa-1235      Anti Brute Force Lock
//#include <bits/stdc++.h>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <math.h>
#include <cstdlib>
#define LIM         510
#define MAX         1000000
#define INF         1000000
#define loop(i,a,b) for(i=a;i<b;i++)
#define SET(a,b)    memset(a,b,sizeof a)
#define pb          push_back
#define x           first
#define y           second
using namespace std;
typedef pair<double,double> dd;
typedef pair<int,int> ii;
typedef pair<int ,ii  > iii;
typedef vector<int> vi;
typedef vector<dd > vdd;
typedef vector<iii> viii;

viii EdgeList;
char key[LIM][10];
char tmp[MAX];
char *tok;

class UnionFind {
private:
  vi p, rank, setSize;
  int numSets;
public:
  UnionFind(int N) {
    setSize.assign(N, 1); numSets = N; rank.assign(N, 0);
    p.assign(N, 0); for (int i = 0; i < N; i++) p[i] = i; }
  int findSet(int i) { return (p[i] == i) ? i : (p[i] = findSet(p[i])); }
  bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }
  void unionSet(int i, int j) { 
    if (!isSameSet(i, j)) { numSets--; 
    int x = findSet(i), y = findSet(j);
    if (rank[x] > rank[y]) { p[y] = x; setSize[x] += setSize[y]; }
    else                   { p[x] = y; setSize[y] += setSize[x];
                             if (rank[x] == rank[y]) rank[y]++; } } }
  int numDisjointSets() { return numSets; }
  int sizeOfSet(int i) { return setSize[findSet(i)]; }
};

int dist(int a, int b){
  int t=0,i,x,y;
  loop(i,0,4){
    x=key[a][i]-'0';
    y=key[b][i]-'0';
    t+=min(abs(x-y),abs(10-abs(x-y)));
    //printf("%d %d %d\n",x,y,t );
  } 
  return t;
}


int main(){
  int t,n,i,d,j,mmin;
  gets(tmp);
  sscanf(tmp,"%d",&t);
  while(t--){
    EdgeList.clear();
    SET(key,0);
    n=0;i=0; mmin=INF;
    gets(tmp);
    tok=strtok(tmp," ");
    while(tok!=NULL){
      if(n==0) n=atoi(tok);
      else { loop(j,0,4) key[i][j]=tok[j]; i++;}
      tok=strtok(NULL," ");
    }

    key[n][0]='0'; key[n][1]='0'; key[n][2]='0'; key[n][3]='0';
    loop(i,0,n) mmin=min(mmin,dist(n,i));

    loop(i,0,n-1) loop(j,i+1,n){
      d=dist(i,j);
      //printf("%s %s %d\n",key[i], key[j], d);
      EdgeList.pb(iii(d,ii(i,j)));
    }
    sort(EdgeList.begin(),EdgeList.end());
    int mst_cost=mmin;
    UnionFind UF(n);
    loop(i,0,EdgeList.size()){
      iii front=EdgeList[i];
      if(!UF.isSameSet(front.y.x,front.y.y)){
        mst_cost+=front.x;
        //printf("mst=%d %d %d\n",front.x,front.y.x,front.y.y);
        UF.unionSet(front.y.x,front.y.y);
        //if(front.y.x==0) loop(i,1,n) printf("%d %d\n", 0,i);;
      }
    }
    printf("%d\n",mst_cost);
  }
  return 0;
}