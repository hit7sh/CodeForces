// Author :: <Hitesh_Saini>
#include<bits/stdc++.h>

#define __speed() ios_base::sync_with_stdio(false), cin.tie(nullptr);
#define dbg(x) cout << "[" << __LINE__ << ": "<< #x << " = " << x << " ]\n"

#define Yes(x) print((x) ? "Yes" : "No")
#define tt 	int t; for (cin >> t; t--; )


#define all(x) x.begin(), x.end()



using namespace std;
using vi = vector<int>;



template <typename... T> void print(T... args) { ((cout << args << " "), ...), cout << endl; }

template <typename T> istream& operator>>(istream& in, vector<T>& v) { for (T& x:v) in >> x; return in; }
template <typename T> ostream& operator<<(ostream& ot, vector<T>& v) { for (T& x:v) ot << x << ' '; return ot; }





void solve() {
	int n, k;
	cin >> n >> k;
	vi A(k);
	iota(all(A), 1);
	reverse(A.begin()+2*k-n-1, A.end());
	print(A);
}






int main() {
    __speed() tt solve();

    return 0;
}
