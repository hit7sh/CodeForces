// Author :: <Hitesh_Saini>
#include<bits/stdc++.h>

#define __speed() ios_base::sync_with_stdio(false), cin.tie(nullptr);
#define tt 	int t; for (cin >> t; t--; )


using namespace std;
using ll = long long;



template <typename... T> void print(T... args) { ((cout << args << " "), ...), cout << endl; }


void solve() {
	ll i, j, n, m, k;
	cin >> n >> k;
	m = k;
	if (k < n)
		k = (n/k)*k;
	if (k < n)
		k += m;
	print((k/n)+(k%n!=0));
}


int main() {
    __speed() tt solve();

    return 0;
}
