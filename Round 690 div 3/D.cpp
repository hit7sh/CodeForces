// Author :: <Hitesh_Saini>
#include<bits/stdc++.h>

#define __speed() ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#define dbg(x) cout << "--- " << #x << " = " << x << " ---\n";
#define findmax(v) *max_element(v.begin(), v.end())
#define _sum(a) accumulate(a.begin(), a.end(), 0)
#define tt int t;for(cin>>t; t--; )
#define gtc int t, tc=1;for(cin >> t;tc<=t;tc++)cout << "case #" << tc << ": ",
#define f0(i, n) for(i = 0; i < (int)(n); i++)
#define f1(i, n) for(i = 1; i<= (int)(n); i++)
#define all(x) x.begin(), x.end()
#define pq priority_queue
#define EB emplace_back
#define PB push_back
#define endl "\n"
#define S second
#define ar array
#define int ll
#define F first

using namespace std;
// using mii = map<int, int>;
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<ll>;
const int mod = 1e9+7,mxN = 1e6+5;

template<typename... Args>void print(Args... args){((cout << args << " "), ...);
cout << endl;}


int A[mxN], n, i, j;

void solve(){//A
	cin >> n;
	f0(i, n)
		cin >> A[i];
	vi pre(n+1);
	f0(i, n)
		pre[i+1] = pre[i] + A[i];
	int f=0, ans=0;
	int fans=INT_MAX;
	int ii;

	for(int k=1;k<=n;k++)
	{	
		i = pre[k];
		int cs=0, prev=0;f=0;
		ans = 0;
		f1(j, n){
			cs = pre[j]-pre[prev];
			if(cs>i)
				break;
			if(cs == i){
				ans += j-prev-1, prev = j;
				if(j==n)
					f=1;
			}
		}
		if(f)
			fans = min(fans, ans);
			
	}
	print(fans);
}

int32_t main(){
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif
    __speed();

    tt solve();
    return 0;
}
