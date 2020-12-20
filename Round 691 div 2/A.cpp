// Author :: <Hitesh_Saini>
#include<bits/stdc++.h>

#define __speed() ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#define dbg(x) cout << "--- " << #x << " = " << x << " ---\n";
#define findmax(v) *max_element(v.begin(), v.end())
#define _sum(a) accumulate(a.begin(), a.end(), 0)
#define tt int t;for(cin>>t; t--; )
#define f0(i, n) for(i = 0; i < (int)(n); i++)
#define f1(i, n) for(i = 1; i<= (int)(n); i++)
#define all(x) x.begin(), x.end()
#define pq priority_queue
#define EB emplace_back
#define PB push_back
#define endl "\n"
#define S second
#define F first

using namespace std;
using mii = map<int, int>;
using pii = pair<int, int>;
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<ll>;
const int mod = 1e9+7,mxN = 1e6+5;

template<typename... Args>void print(Args... args){((cout << args << " "), ...); cout << endl;}

void solve(){//A
	int n, i, j;
	cin >> n;
	string a, b;
	cin >> a >> b;
	int re=0, bl=0;
	f0(i, n)
		re += a[i]>b[i], bl+=a[i]<b[i];
	if(re>bl)
		print("RED");
	else if(bl>re)
		print("BLUE");
	else
		print("EQUAL");
}

int32_t main(){
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif
    __speed() tt solve();

    return 0;
}
