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
 
 
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define ll long long
#define max(a,b) ((a) > (b) ? (a) : (b))
#define min(a,b) ((a) < (b) ? (a) : (b))
 
#define getI(a) scanf("%d",&a)
#define getII(a, b) scanf("%d%d",&a,&b)
#define getIII(a, b, c) scanf("%d%d%d",&a,&b,&c)
#define getL(a) scanf("%lld",&a)
#define getLL(a, b) scanf("%lld%lld",&a,&b)
#define getLLL(a, b, c) scanf("%lld%lld%lld",&a,&b,&c)
#define BEND(c) (c).begin(),(c).end()
#define BEND2(c) (c).rbegin(),(c).rend()
#define fi first
#define se second
#define pi 3.1415926535897932384626
#define getS(a) scanf("%s",a)
#define pfb(a) printf("%.10lf\n",a);
#define pfi(a) printf("%d",a);
#define pfii(a, b) printf("%d%d",a,b);
#define pfl(a) printf("%lld",a);
#define pfll(a, b) printf("%lld%lld",a,b);
#define pfd(a) printf("%.15lf \n",a);
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);
#define endl "\n"
 
#define MOD  ( int)(1e18 + 3 )
#define MAXN (ll) ((1000010))
#define K 25
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
 
vector<ll> fact;
vector<ll> fact2;
void finit(int n);
ll exp(ll taban, ll us, ll md);
ll ebob(ll a, ll b);
ll ekok(ll a, ll b);
ll comb(ll a, ll b);
 
 
 
 
 
 
void finit(int n){
	fact.resize(n + 5);
	fact2.resize(n + 5);
	fact[0] = fact2[0] = 1;
	for (int i = 1; i <= n; i++){
		fact[i] = (fact[i - 1] * i) % MOD;
		fact2[i] = exp(fact[i], MOD - 2, MOD);
	}
}
ll exp(ll taban, ll us, ll md) {
	ll carpan = taban % md;
	if (carpan == 0) return 0;
	ll temp = us;
	ll ans = 1;
	while (temp){
		if (temp % 2) ans = (ans*carpan) % md;
		temp /= 2;
		carpan = (carpan*carpan) % md;
	}
	return ans;
}
 
ll ebob(ll a, ll b){
	if (!a)return b;
	return ebob(b%a, a);
}
 
ll ekok(ll x, ll y){
	return (x*y) / ebob(x, y);
}
 
ll comb(ll x, ll y){
	if (x < y) return 0;
	return fact[x] * ((fact2[x - y] * fact2[y]) % MOD) % MOD;
}
 
 
 
ll t = 1, n, m;
//k, z, x, d, res = 0;
double ans = 0;
 
vi v[MAXN];
int vis[MAXN];
int pw[MAXN];
int c =0;
 
set<int> ss;
 
 
 
void solve(){
	cin >> n >> m;
	pw[0] = 1;
	for (int i = 1; i < 600003; i++)pw[i] = (pw[i - 1] * 3) % MOD;
 
	string s;
	int cur = 0;
	for (int i = 0; i < n; i++){
		cur = 0;
		cin >> s;
		int size = s.size();
		for (int j = 0; j < size; j++){
			cur = (cur * 3 + (s[j] - 'a')) % MOD;
			
			
		}
		ss.insert(cur);
	}
 
	//for (auto el : ss)cout << el << " ";
	for (int i = 0; i < m; i++){
		cur = 0;
		cin >> s;
		int size = s.size();
		int ctr = 0;
		for (int j = 0; j < size; j++){
			cur = (cur * 3 + (s[j] - 'a')) % MOD;
			
		}
		int cur2 = 0;
		for (int j = 0; j < size; j++){
			cur2 = ( cur -  (pw[j] * (s[size  - j - 1]  - 'a' )  )  ) % MOD;
			if (cur2 < 0)cur2 += MOD;
			for (int t = 0; t < 3; t++){
				if (s[size - 1 - j] - 'a' != t )
					if (ss.count((cur2 + t * pw[j]) % MOD))ctr = 1;
			}
 
			if (ctr) break;
		}
		if (ctr)cout << "YES\n";
		else cout << "NO\n";
		
 
	}
 
 
}
 
 
 
 
 
 
 
 
 
signed main(){
 
	IOS;
	
	
	//cin >> t;
 
	while (t--){
		solve();
		
	}
	
 
 
	getchar(); getchar();
 
	return 0;
 
}