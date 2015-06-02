//#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <queue>
#define loop(i,a,b) for(i=a;i<b;i++)
#define pb push_back
#define LIM 40
using namespace std;

int acorn, trees;
char V[LIM];
vector<int> con[LIM];
char tmp[50];
char* tok;
vector<int> nodes;

int dfs(int org){
    int r=1,i;
    V[org]=1;
    for(i=0;i<con[org].size();i++)
        if(V[con[org][i]]==0 && find(nodes.begin(),nodes.end(),con[org][i])!=nodes.end())
            r+=dfs(con[org][i]);
    return r;
}

int main(){
    int n,a,b,i,r;
    char c1,c2;
    gets(tmp);
    sscanf(tmp,"%d",&n);
    while(n--){
        memset(V,0,sizeof V);
        loop(i,0,LIM) con[i].clear();
        nodes.clear();
        acorn=trees=0;
        gets(tmp);
        while(tmp[0]!='*'){
            sscanf(tmp," (%c,%c)",&c1,&c2);
            con[c1-'A'].pb(c2-'A');
            con[c2-'A'].pb(c1-'A');
            gets(tmp);
        }
        gets(tmp);
        tok=strtok(tmp,",");
        while(tok!=NULL){
            nodes.pb(tok[0]-'A');
            tok=strtok(NULL,",");
        }
        for(i=0;i<nodes.size();i++){
            if(V[nodes[i]]!=0) continue;
            r=dfs(nodes[i]);
            if(r>1) trees++;
            else if (r==1) acorn++;
        }
        printf("There are %d tree(s) and %d acorn(s).\n",trees,acorn);
    }
    return 0;
}