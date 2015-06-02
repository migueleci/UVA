//UVa-10034    Freckles 
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
typedef vector<int> vi;
typedef vector<dd > vdd;
typedef vector<pair<double ,ii  > > vdii;

vdii EdgeList;
vdd nodes;

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

int main(){
  int nc,f,i,j;
  double a,b,dist;
  scanf("%d",&nc);
  while(nc--){
    nodes.clear();
    EdgeList.clear();
    scanf("%d",&f);
    loop(i,0,f) {
      scanf("%lf %lf",&a,&b);
      nodes.pb(dd(a,b));
    }
    loop(i,0,f-1) {
      loop(j,i+1,f) {
        dist=sqrt((nodes[i].x-nodes[j].x)*(nodes[i].x-nodes[j].x)+(nodes[i].y-nodes[j].y)*(nodes[i].y-nodes[j].y));
        EdgeList.pb(make_pair(dist,ii(i,j)));
        //EdgeList.pb(make_pair(dist,ii(j,i)));
      }
    }
    sort(EdgeList.begin(),EdgeList.end());
    double mst_cost=0;
    UnionFind UF(f);
    loop(i,0,EdgeList.size()){
      pair<double ,ii  > front=EdgeList[i];
      if(!UF.isSameSet(front.second.first,front.second.second)){
        mst_cost+=front.first;
        UF.unionSet(front.second.first,front.second.second);
      }
    }
    printf("%0.2lf\n",mst_cost);
    if(nc>0) puts("");
  }
  return 0;
}