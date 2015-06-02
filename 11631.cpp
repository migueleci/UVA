//UVa-11631      Dark roads
//#include <bits/stdc++.h>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <math.h>
#define LIM         210
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

int main(){int n,m,i,x,y,z;
  while(scanf("%d %d",&m,&n)==2 && n+m>0){
    EdgeList.clear();
    loop(i,0,n){
      scanf("%d %d %d",&x,&y,&z);
      EdgeList.pb(iii(z,ii(x,y)));
    }
    sort(EdgeList.begin(),EdgeList.end());
    int mst_cost=0,mst_cost_total=0;;
    UnionFind UF(m);
    loop(i,0,EdgeList.size()){
      iii front=EdgeList[i];
      mst_cost_total+=front.x;
      if(!UF.isSameSet(front.y.x,front.y.y)){
        mst_cost+=front.x;
        UF.unionSet(front.y.x,front.y.y);
      }
    }
    printf("%d\n",mst_cost_total-mst_cost);
  }
  return 0;
}