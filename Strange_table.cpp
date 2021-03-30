#pragma GCC optimize ("O3") 
 
#include <bits/stdc++.h>
using namespace std;
#include <iostream>
#include <fstream>
 
#define TRACE(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); cerr << endl;}
 
void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
	cerr << "[" << *it << " = " << a << "]";
	err(++it, args...);
}
#define MAXN ((ll)1e6+5)
#define MOD ((ll)1e9 + 7)
#define INF ((ll)1e18+3)
#define ll long long
#define pb push_back
#define _ << " " <<
#define all(x) x.begin(), x.end()
#define endl "\n"
#define pii pair<ll,ll>
#define mid ((l+r)/2)
//#define int long long
 
ll tt =0  , n , m ,x , a, b; 
 
void solve(){
 
	cin >> n >> m >> x;
	if( n * m == x){ cout << x<<endl;return;}
	x--;
	ll a = x / n ;
	ll b= x % n ;
	ll res= b * m + a + 1 ;
	cout << res<<endl;
 
 
 
}
signed main()
{
	
	cin>>tt;
	while(tt--){
		solve();
	}
 
}