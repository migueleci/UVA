#include <bits/stdc++.h>
#define loop(i,a,b) for(i=a;i<b;i++)
#define LIM 30
using namespace std;

int dx[]={ 0, 0, 1,-1, 1,-1,-1, 1};
int dy[]={-1, 1, 1,-1,-1, 1, 0, 0};

int mat[LIM][LIM];
int S;

void floodfill(int r, int c){
    if (r<0 || r>=S || c<0 || c>=S || mat[r][c]==0) return;
    mat[r][c]=0;
    for (int i=0; i<8; i++) floodfill(r+dx[i], c+dy[i]);
}

int main(){
    int i,j,ans,casos=1;
    while (scanf("%d",&S)==1) {
        memset(mat,-1,sizeof mat);
        ans=0;
        loop(i,0,S) loop(j,0,S) scanf("%1d",&mat[i][j]);
        loop(i,0,S) loop(j,0,S) if(mat[i][j]==1) floodfill(i,j), ans++;
        printf("Image number %d contains %d war eagles.\n",casos++,ans);
    }
    return 0;
}