// Author :: <Hitesh_Saini>
#include<bits/stdc++.h>

#define __speed() ios_base::sync_with_stdio(false), cin.tie(nullptr);
#define dbg(x) cout << "[" << __LINE__ << ": "<< #x << " = " << x << " ]\n"

#define Yes(x) print((x) ? "Yes" : "No")
#define tt 	int t; for (cin >> t; t--; )

#define f0(i, n)  for (i = 0; i < (int)(n); i++)
#define f1(i, n)  for (i = 1; i <=(int)(n); i++)

#define cmax(x, y) x = max(x, y)
#define cmin(x, y) x = min(x, y)

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define sz(x) (int)(x.size())

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

const int mod = 1e9+7, mxN = 2e5+5, INF = 0x3f3f3f3f;



template <typename... T> void print(T... args) { ((cout << args << " "), ...), cout << endl; }



vi primes;

void solve() {
	int n, i;
	cin >> n;
	ll a = *lower_bound(all(primes), 1+n);
	print( a *1LL* *lower_bound(all(primes), a+n));
}





void pre() {
	int i, j, n, till = 1;
	n = 2e5+5;
	vector<bool> prime(n + 1, 1);
	for(i=2;i*i<=n;i++)
        if(prime[i])
            for(j=i*i;j<=n;j+=i)
                prime[j]=0;
    for (i = 2; i < n; i++)
    	if(prime[i])
    		primes.EB(i);
}





int main() {

	pre();

    __speed() tt solve();

    return 0;
}
