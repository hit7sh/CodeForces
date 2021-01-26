// Author :: <Hitesh_Saini>
#include<bits/stdc++.h>

#define __speed() ios_base::sync_with_stdio(false), cin.tie(nullptr);
#define tt 	int t; for (cin >> t; t--; )

#define f0(i, n)  for (i = 0; i < (int)(n); i++)



using namespace std;

using ll = long long;
using vi = vector<int>;




template <typename... T> void print(T... args) { ((cout << args << " "), ...), cout << endl; }

template <typename T> istream& operator>>(istream& in, vector<T>& v) { for (T& x:v) in >> x; return in; }
template <typename T> ostream& operator<<(ostream& ot, vector<T>& v) { for (T& x:v) ot << x << ' '; return ot; }






void solve() {
	int a, b, k, i, j;
	cin >> a >> b >> k;
	vi B(k), G(k);
	cin >> B >> G;
	vi fb(a+1), fg(b+1);

	f0(i, k)
		fb[B[i]]++, fg[G[i]]++;
    
	ll ans = 0;
	f0(i, k) {
		
		ans += k-(fb[B[i]]+fg[G[i]]-1);
	}
	print(ans/2);
}









int main() {

    __speed() tt solve();

    return 0;
}
