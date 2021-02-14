// Author :: <Hitesh_Saini>
#include<bits/stdc++.h>

#define __speed() ios_base::sync_with_stdio(false), cin.tie(nullptr);
#define tt 	int t; for (cin >> t; t--; )

using namespace std;
using ll = long long;
using vi = vector<int>;


template <typename... T> void print(T... args) { ((cout << args << " "), ...), cout << endl; }
template <typename T> ostream& operator<<(ostream& ot, vector<T>& v) { for (T& x:v) ot << x << ' '; return ot; }






void solve() {	
	int n, q, k;
	cin >> n >> q >> k;
	vi A(n);
	cin >> A;
	while (q--) {
		int l, r;
		cin >> l >> r;
		--l, --r;
		ll left = k - A[r] + A[r] - A[l] - 1 - (r-l-1);
		ll right = A[l] - 1 + A[r] - A[l] - 1 - (r-l-1);
		
		ll ans = left + right;
		print(ans);
	}
}


int main() {
  tt solve();
  }
