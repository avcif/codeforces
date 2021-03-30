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
//#define int ll
#define findone(x) __builtin_popcountll(x)
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
 
 
 
 
 
 
 
 
ll tt=1 , n , m , x , k , res= 0  ;
 ll p[19][1<<19];
 
 int g[19][19];
int a[19];
void solve() {
	cin >> n >> m >> k;
   ll ans= -INF;
    
    for(int i= 0 ; i < n ; i++) cin >> a[i];
    for(int i= 0 ; i < k ; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        g[u - 1][v - 1] = w;
    }
   
    for(int i= 0 ; i < n ; i++) p[i][1 << i] = a[i];
    ll cur=0;
    for(int x =1 ;x <= (1 <<n) ; x++) {
        if (findone(x) < m){
             //cout << x<<endl;
            for(int i = 0; i < n; i++)
            if ( (x >> i) & 1 ) {
                for(int k = 0; k < n; k++)
                    if (! ((x >> k) & 1) ){
                        cur = x | (1 << k );
                        p[k][cur] = max(p[k][cur], p[i][x] +  1LL*a[k] +  1LL*g[i][k]);
                    }
            }
        }
    }
    
    for(int x = 1; x < (1 << n); x++)
    if (findone(x) == m){
        for(int i= 0 ; i < n ; i++) {
            ans = max(ans , p[i][x]);
            //cout <<p[i][x]<<endl;
        }
    }
    cout<<ans;
	
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