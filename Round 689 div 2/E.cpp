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

ll K, L, R, T, X, Y;
bool solve(){//A
	cin >> K >> L >> R >> T >> X >> Y;
	if (T <= (K - L) / X)
        return 1;
 
    if (L + Y > R)
        return 0;
 
    if (Y < X) {
        if (K + Y <= R)
            K += Y;
 
        K -= X;
 
        if (K < L)
            return T <= 0;
 
        return T <= (K - L) / (X - Y) + 1;
    }

 
    if (R - Y >= L + X - 1)
        return 1;
 
    for (int64_t iter = 0; iter <= X; iter++) {
        int64_t take = (K - L) / X;
 
        if (T <= take)
            return 1;
 
        if (iter > 0 && take == 0)
            return 0;
 
        T -= take;
        K -= take * X;

        K += Y;
 
        if (K > R)
            return 0;
    }
 
    return 1;
}

int32_t main(){
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif
    __speed();
    print(solve()?"Yes":"No");
    return 0;
}
