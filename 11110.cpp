//#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <queue>
#define loop(i,a,b) for(i=a;i<b;i++)
#define LIM 110
using namespace std;

int dr[]={ 0, 0,-1, 1};
int dc[]={-1, 1, 0, 0};
int R, C;
int eq[LIM][LIM];

char tmp[2000];
char* pch, pch2;

void floodfill(int r, int c, int c1, int c2){
    int i;
    if(r<0 || r>=R || c<0 || c>=C || eq[r][c]!=c1) return;
    eq[r][c]=c2;
    loop(i,0,4) floodfill(r+dr[i],c+dc[i],c1,c2);
}

int main(){
    int n,i,j,k,t,f,c,num,len;
    bool w;
    gets(tmp);
    sscanf(tmp,"%d",&n);
    while(n>0){
        memset(eq,0,sizeof eq);
        R=C=n; num=1;
        loop(i,0,n-1){
            gets(tmp);
            pch=strtok(tmp," ");
            while (pch!= NULL) {
                f=atoi(pch);
                pch=strtok(NULL," ");
                c=atoi(pch);
                pch=strtok(NULL," ");
                //printf("pos=%d %d\n",f,c);
                eq[f-1][c-1]=num;
            }
            num++;
        }
        w=true;
        loop(k,0,n && w){
            t=0;
            loop(i,0,R && t<2) loop(j,0,C && t<2) if(eq[i][j]==k) floodfill(i,j,k,-1),t++;
            if(t>1) w=false;
        }
        if(w) puts("good");
        else puts("wrong");
        gets(tmp);
        sscanf(tmp,"%d",&n);
    }
    return 0;
}