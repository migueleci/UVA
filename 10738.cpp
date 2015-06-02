//UVA-10738     Riemann vs Mertens
//#include <bits/stdc++.h>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <iostream>
#include <map>
#include <queue>
#include <math.h>
#define INF         1e9
#define LIM         1001000
#define UNVISITED   -1
#define loop(i,a,b) for(i=a;i<b;i++)
#define X first
#define Y second
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef map<int, int> mii;

//int numDiffPF[LIM];
int solve[LIM];
int acum[LIM];

ll _sieve_size=LIM;
bitset<10000010> bs;   // 10^7 should be enough for most cases
vi primes;   // compact list of primes in form of vector<int>

void sieve(ll upperbound) {          // create list of primes in [0..upperbound]
  _sieve_size = upperbound + 1;                   // add 1 to include upperbound
  bs.set();                                                 // set all bits to 1
  bs[0] = bs[1] = 0;                                     // except index 0 and 1
  for (ll i = 2; i <= _sieve_size; i++) if (bs[i]) {
    // cross out multiples of i starting from i * i!
    for (ll j = i * i; j <= _sieve_size; j += i) bs[j] = 0;
    primes.push_back((int)i);  // also add this vector containing list of primes
} }                                           // call this method in main method

ll numPF(ll N) {
  ll PF_idx = 0, PF = primes[PF_idx], ans = 0;
  while (N != 1 && (PF * PF <= N)) {
    while (N % PF == 0) { N /= PF; ans++; }
    PF = primes[++PF_idx];
  }
  if (N != 1) ans++;
  return ans;
}

ll numDiffPF(ll N) {
  ll PF_idx = 0, PF = primes[PF_idx], ans = 0;
  while (N != 1 && (PF * PF <= N)) {
    if (N % PF == 0) ans++;
    while (N % PF == 0) N /= PF;
    PF = primes[++PF_idx];
  }
  if (N != 1) ans++;
  return ans;
}

void prec(){
	sieve(LIM);
	ll i,nPF;
	memset(solve,0,sizeof solve);
	memset(acum,0,sizeof acum);
	solve[1]=acum[1]=1;
	loop(i,2,LIM){
		nPF=numDiffPF(i);
		if(nPF!=numPF(i)) solve[i]=0;
		else solve[i]=nPF%2==1?-1:1;
		acum[i]=solve[i]+acum[i-1]; 
	}
}

int main(){
	int n,i;
	prec();
	//loop(i,1,21) printf("%8d %8d %8d\n",i, solve[i], acum[i]);
  while(scanf("%d",&n)==1 && n>0){
    printf("%8d%8d%8d\n",n, solve[n], acum[n]);
  }
  return 0;
}