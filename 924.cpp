//#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <queue>
#define loop(i,a,b) for(i=a;i<b;i++)
#define LIM 2550
using namespace std;

int resp[LIM];
vector<int> mat[LIM];
int S, lev;
vector<int> fnd;

void bfs_it(int s){
    int tam,i,j,ob; lev=1;
    fnd.push_back(s);
    queue<int> pend, visited; pend.push(s);
    while (!pend.empty()) {
        tam=pend.size();
        loop(j,0,tam){
            ob=pend.front();
            loop(i,0,mat[ob].size()){
                if(find(fnd.begin(),fnd.end(),mat[ob][i])==fnd.end()){
                    fnd.push_back(mat[ob][i]);
                    pend.push(mat[ob][i]);
                }
            }
            pend.pop();
        }
        resp[lev++]=pend.size();
    }
}

int main(){
    int i,j,n,casos,aux;
    scanf("%d",&S);
    loop(i,0,S) {
        scanf("%d",&n);
        loop(j,0,n) {
            scanf("%d",&aux);
            mat[i].push_back(aux);
        }
    }
    int maxn,maxl;
    scanf("%d",&casos);
    loop(i,0,casos){
        memset(resp,0,sizeof resp);
        maxn=maxl=0;
        fnd.clear();
        scanf("%d",&n);
        bfs_it(n);
        loop(j,1,lev+1) if(resp[j]>maxn) maxn=resp[j],maxl=j;
        if(maxn==0) printf("0\n");
        else printf("%d %d\n",maxn,maxl);
    }
    return 0;
}