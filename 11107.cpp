  //#include <bits/stdc++.h>
  #include <algorithm>
  #include <cstdio>
  #include <cstring>
  using namespace std;

  typedef pair<int, int> ii;

  #define MAX_N 100100                         // second approach: O(n log n)
  char T[MAX_N],U[MAX_N];                   // the input string, up to 100K characters
  int n, nc;                                        // the length of input string
  int RA[MAX_N], tempRA[MAX_N];        // rank array and temporary rank array
  int SA[MAX_N], tempSA[MAX_N];    // suffix array and temporary suffix array
  int c[MAX_N];                                    // for counting/radix sort

  char P[MAX_N];                  // the pattern string (for string matching)
  int m;                                      // the length of pattern string
  int dist[MAX_N];
  int Phi[MAX_N];                      // for computing longest common prefix
  int PLCP[MAX_N];
  int LCP[MAX_N];  // LCP[i] stores the LCP between previous suffix T+SA[i-1]
                                                // and current suffix T+SA[i]

  bool cmp(int a, int b) { return strcmp(T + a, T + b) < 0; }      // compare

  void countingSort(int k) {                                          // O(n)
    int i, sum, maxi = max(300, n);   // up to 255 ASCII chars or length of n
    memset(c, 0, sizeof c);                          // clear frequency table
    for (i = 0; i < n; i++)       // count the frequency of each integer rank
      c[i + k < n ? RA[i + k] : 0]++;
    for (i = sum = 0; i < maxi; i++) {
      int t = c[i]; c[i] = sum; sum += t;
    }
    for (i = 0; i < n; i++)          // shuffle the suffix array if necessary
      tempSA[c[SA[i]+k < n ? RA[SA[i]+k] : 0]++] = SA[i];
    for (i = 0; i < n; i++)                     // update the suffix array SA
      SA[i] = tempSA[i];
  }

  void constructSA() {         // this version can go up to 100000 characters
    int i, k, r;
    for (i = 0; i < n; i++) RA[i] = T[i];                 // initial rankings
    for (i = 0; i < n; i++) SA[i] = i;     // initial SA: {0, 1, 2, ..., n-1}
    for (k = 1; k < n; k <<= 1) {       // repeat sorting process log n times
      countingSort(k);  // actually radix sort: sort based on the second item
      countingSort(0);          // then (stable) sort based on the first item
      tempRA[SA[0]] = r = 0;             // re-ranking; start from rank r = 0
      for (i = 1; i < n; i++)                    // compare adjacent suffixes
        tempRA[SA[i]] = // if same pair => same rank r; otherwise, increase r
        (RA[SA[i]] == RA[SA[i-1]] && RA[SA[i]+k] == RA[SA[i-1]+k]) ? r : ++r;
      for (i = 0; i < n; i++)                     // update the rank array RA
        RA[i] = tempRA[i];
      if (RA[SA[n-1]] == n-1) break;               // nice optimization trick
  } }

  void computeLCP() {
    int i, L;
    Phi[SA[0]] = -1;                                         // default value
    for (i = 1; i < n; i++)                            // compute Phi in O(n)
      Phi[SA[i]] = SA[i-1];    // remember which suffix is behind this suffix
    for (i = L = 0; i < n; i++) {             // compute Permuted LCP in O(n)
      if (Phi[i] == -1) { PLCP[i] = 0; continue; }            // special case
      while (T[i + L] == T[Phi[i] + L]) L++;       // L increased max n times
      PLCP[i] = L;
      L = max(L-1, 0);                             // L decreased max n times
    }
    for (i = 0; i < n; i++)                            // compute LCP in O(n)
      LCP[i] = PLCP[SA[i]];   // put the permuted LCP to the correct position
  }

  int owner(int idx) { 
    for (int i = 0; i < nc; ++i) if(idx<dist[i]) return i; 
    return 0;
  }

  ii LCS() {                 // returns a pair (the LCS length and its index)

    int i, idx = 0, maxLCP = -1, j;
    int tmpLCP,cant;
    int s=0, f;
    int visit[nc], total;
    bool ant;
    while(s<n){
      while(LCP[s+1]==0 && s+1<n) s++; f=s+1;
      while(LCP[f+1]!=0 && f+1<n) f++; if(f>=n) f--;
      //printf("tamano= %d indices= %d %d\n",n, s,f);
      
      for (i = f; i >s; i--) {
        ant=true;cant=0;
        memset(visit,0,sizeof visit);
        for (j = i; j >=s && ant; j--) {
          if(visit[owner(SA[j])]==0){
            visit[owner(SA[j])]=1; cant++;
          } 
          if(LCP[j]<LCP[i]) ant=false;
        }
        if(cant>nc/2 && LCP[i]>maxLCP) maxLCP = LCP[i], idx = i;
      }
      s=f+1;
    }

    /*
    int i, idx = 0, maxLCP = -1, j;
    int visit[nc], total;
    bool change;
    for (i = nc-1; i < n; i++){                        // O(n), start from i = 1
      memset(visit,0,sizeof visit);
      change=true; total=0;
      for (j = 0; j < nc && change; j++) {
        //printf("- %d ", owner(SA[i-j]));
        if(visit[owner(SA[i-j])]==0){
          visit[owner(SA[i-j])]=-1; total++;
        }
        if(LCP[i-j]==0 || LCP[i-j]<LCP[i]) change=false;
      }
      //printf(" = %d",difall); puts("");
      if (total>nc/2 && LCP[i] > maxLCP)
        maxLCP = LCP[i], idx = i;
    }*/
    return ii(maxLCP, idx);
  }

  int main() {
    char tmp[MAX_N];
    gets(tmp);
    int car;
    sscanf(tmp,"%d",&nc);
    while(nc>0){
      memset(T,0,sizeof T);
      car=33;
      memset(dist,-1,sizeof dist);
      memset(LCP,-1,sizeof LCP);
      memset(SA,-1,sizeof SA);
      for (int i=0;i<nc;i++) {
        memset(tmp,0,sizeof tmp);
        gets(tmp);
        strcat(T,tmp);
        n=strlen(T);
        T[n++]=car;
        if(i==0) dist[i]=strlen(tmp);
        else dist[i]=dist[i-1]+strlen(tmp)+1;
        if(car<64)car++;
        else car=33;
      }
      n=strlen(T);
      if(nc==1) puts(tmp);
      else{
        constructSA();
        computeLCP();
        //printf("i\tSA[i]\tLCP[i]\tOwner\tSuffix\n");
        //for (int i = 0; i < n; i++)
        //  printf("%2d\t%2d\t%2d\t%2d\t%s\n", i, SA[i], LCP[i], owner(SA[i]), T + SA[i]);
        ii ans = LCS();
        //printf("LCS=%d\n",ans.first );
        bool diff,eq,fp=true;
        int visit[nc], total;
        char lcsans[MAX_N],U[MAX_N];
        if(ans.first==-1) printf("?\n");
        int s=0, f, idx;
        while(s<n && ans.first!=-1){
          while(LCP[s+1]==0 && s+1<n) s++; f=s+1;
          while(LCP[f+1]!=0 && f+1<n) f++; if(f>=n) f--;
          //printf("inicio=%d,LCP=%d final=%d,LCP=%d ---- %d\n",s,LCP[s],f,LCP[f],LCP[f+1]);
          bool esta=false;
          for (int i = f; i >=s && !esta; i--){ if(LCP[i] >= ans.first) { esta=true; idx=i;}} 
          if(esta){
            total=0; diff=true;
            memset(visit, 0, sizeof visit); 
            for (int i = idx; i >=s && diff; i--) {            
              if(visit[owner(SA[i])]==0){
                visit[owner(SA[i])]=-1; total++;
              } 
              if(LCP[i]<ans.first) diff=false;
            }
            //printf("respuessta=%d %d %d\n",total, nc/2,total>nc/2);

            if(total>nc/2){
              //puts("ENTROOOO");
              memset(lcsans,0,sizeof lcsans);
              strncpy(lcsans, T + SA[idx], ans.first);
              eq=true;
              if(!fp) for(int mm = 0; mm < ans.first && eq;mm++) eq=U[mm]==lcsans[mm];
              if(fp || !eq){
                printf("%s\n", lcsans);
                strcpy(U,lcsans);
                fp=false;
              }
            }
          }
          s=f+1;
        }
        /*
        for (int i = nc-1; i < n; i++) {
          //printf("LCP  %d %d\n",ans.first,LCP[i+nc-1]);
          if(LCP[i]==ans.first){
            diff=true; total=0;
            memset(visit, 0, sizeof visit); 
            for (int j = 0; j < nc && diff; j++) {
              if(visit[owner(SA[i-j])]==0){
                visit[owner(SA[i-j])]=-1; total++;
              } 
              if(LCP[i-j]==0 || LCP[i-j]<LCP[i]) diff=false;
            }
            if(total>nc/2){
              memset(lcsans,0,sizeof lcsans);
              strncpy(lcsans, T + SA[i], ans.first);
              eq=true;
              if(!fp) for(int mm = 0; mm < ans.first && eq;mm++) eq=U[mm]==lcsans[mm];
              if(fp || !eq){
                printf("%s\n", lcsans);
                strcpy(U,lcsans);
                fp=false;
              }
            }
          }
        }*/
      }
      
      /*printf("%s\n",T);
      for (int i = 0; i < strlen(T); ++i)printf("%d", i%10);
      puts("");
      for (int i = 0; i < nc; ++i) printf("%d\n", dist[i]);*/
      gets(tmp);
      sscanf(tmp,"%d",&nc);
      if(nc>0) puts("");
      memset(U,0,sizeof U);
    }
    return 0;
  }