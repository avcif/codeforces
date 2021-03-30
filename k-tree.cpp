#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
 
#include<bits/stdc++.h>
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <queue>
#include <set>
#include <string>
#include <stdbool.h>
#include<ctime>
 
#include <cstring>
 
#define pub push_back
 
 
 
#define ll long long
#define max(a,b) ((a) > (b) ? (a) : (b))
#define min(a,b) ((a) < (b) ? (a) : (b))
 
 
#define BEND(c) (c).begin(),(c).end()
#define BEND2(c) (c).rbegin(),(c).rend()
#define fi first
#define se second
#define pi 3.1415926535897932384626
 
#define pfd(a) printf("%.15lf \n",a);
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);
#define endl "\n"
 
#define MOD  ( int)( 1e9 +7)
#define MAXN (ll) ((1000010))
 
#define  ALPHABET_SIZE  26
//#define N (int)(1e5+10)
#define sag (sol|1)
#define sol (root<<1)
#define ort (bas+son)/2
#define INF (ll )1e18
#define int ll
using namespace std;
 
 
 
 
 
 
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<vector<int>> vvi;
typedef vector<vector<pair<int, int>>> vvpi;
typedef vector<long long> vl;
typedef vector<pair<int, int>> vpi;
typedef vector<pair<long long, long long>> vpl;
typedef pair<int, int> pii;
typedef pair <ll, ll> pll;
typedef vector<vi> graph;
 
 
 
 
 
 
 
 
ll tt=1 , n , m , x , k , res= 0 , ans =0 ;
int p[MAXN];
 
ll fac[MAXN];
ll fast(ll a,ll b , ll mod )
{
	ll res=1;
	while(b)
	{
		if(b&1LL)
		{
			res*=a;
			res%=mod;
		}
		b>>=1LL;
		a*=a;
		a%=mod;
	}
	return (res + mod)%mod;
}
 
void pre()
{
	fac[0] = 1;
	for (ll i = 1; i < 2e5; ++i)
		fac[i] = (fac[i-1] * i) ;
}
 
int C(int a, int b)
{
	if (a < b) return 0;
	if (a == b) return 1;
	int val = fac[a];
	cout << val<<endl;;
	val = (val * fast(fac[b], MOD-2 , MOD)) % MOD;
	val = (val * fast(fac[a-b], MOD-2 , MOD)) % MOD;
	
	return val;
}
 
void solve() {
    int t;
	cin >> n >> k >> t;
	vector<int> d(107), d2(107);
	d[0] = d2[0] = 1;
	for(int i = 0 ; i < 107 ; i++) {
		for (int j = 1; j <= k; j++) {
			if (i + j >= 107) break;
			d[i+j] = (d[i+j] + d[i]) % MOD;
		}
	}
	for(int i = 0 ; i < 107 ; i++) {
		for (int j = 1; j < t; j++) {
			if (i + j >= 107) break;
			d2[i+j] = (d2[i+j] + d2[i]) % MOD;
		}
	}
	cout << ((d[n]-d2[n])%MOD+MOD)%MOD;
}
 
 
 
 
 
 
 
 
signed main(){
 
	IOS;
 
 
	//cin >> tt;
 
	while (tt--){
		solve();
 
	}
 
 
 
	//getchar(); getchar();
 
	return 0;
 
}