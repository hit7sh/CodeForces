// Author :: <Hitesh_Saini>
#include<bits/stdc++.h>

#define __speed() ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#define tt int t;for(cin>>t; t--; )
#define gtc int t, tc=1;for(cin >> t;tc<=t;tc++)cout << "case #" << tc << ": ",
#define f0(i, n) for(i = 0; i < (int)(n); i++)
#define f1(i, n) for(i = 1; i<= (int)(n); i++)
#define all(x) x.begin(), x.end()
#define pq priority_queue
#define EB emplace_back
#define PB push_back
#define endl "\n"

using namespace std;
using vi = vector<int>;

template<typename... Args>void print(Args... args){((cout << args << " "), ...);
cout << endl;}

char A[2001][2001];
void solve(){//A
	int n, i, j;
	cin >> n;
	
	int mnr[10]={}, mxr[10]={}, mnc[10]={}, mxc[10]={};
	f0(i, 10)
		mnr[i]=mnc[i]=INT_MAX;
	f1(i, n)cin >> A[i]+1;
	f1(i, n){
		f1(j, n){
			int d = A[i][j]^48;
			mnr[d] = min(mnr[d], i), mxr[d] = max(mxr[d], i);
			mnc[d] = min(mnc[d], j), mxc[d] = max(mxc[d], j);
		}
	}
	vi ans(10);
	f1(i, n)f1(j, n){
		int d=A[i][j]^48;
		ans[d] = max(ans[d], max(n-j, j-1)*max(mxr[d]-i, i-mnr[d]));
		ans[d] = max(ans[d], max(n-i, i-1)*max(mxc[d]-j, j-mnc[d]));
	}
	f0(i, 10)
		cout << ans[i] << ' ';
	cout << endl;
}

int32_t main(){
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif
    __speed() tt solve();
    return 0;
}
