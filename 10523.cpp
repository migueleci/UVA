//#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;

int main(){
    int n,a;
    while (scanf("%d %d",&n,&a)==2) {
        long long int ans;
        ans=a+pow(a,n+1)*(n*a-n-1);
        ans/=(1-a)*(1-a);
        printf("%lld\n",ans);
    }
    return 0;
}