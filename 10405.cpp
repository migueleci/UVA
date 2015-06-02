//UVa-10405      Longest Common Subsequence 
//#include <bits/stdc++.h>
#include <algorithm>
#include <cstdio>
#include <cstring>
#define INF         1e9
#define LEN         1010
#define loop(i,a,b) for(i=a;i<b;i++)
using namespace std;

int main() {
  char A[LEN], B[LEN];
  int n, m;
  int i, j, table[LEN][LEN];
  while(gets(A)){
    gets(B);
    n = (int)strlen(A);
    m = (int)strlen(B);

    memset(table, 0, sizeof table);

    loop(i,1,n+1)
      loop(j,1,m+1) {
        // match = 2 points, mismatch = -1 point
        table[i][j] = table[i - 1][j - 1] + (A[i - 1] == B[j - 1] ? 1 : -INF); // cost for match or mismatches
        // insert/delete = -1 point
        table[i][j] = max(table[i][j], table[i - 1][j]); // delete
        table[i][j] = max(table[i][j], table[i][j - 1]); // insert
      }
    
    printf("%d\n",table[n][m]);
        
  }
  return 0;
}
