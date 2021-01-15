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
	int m, n, d, i, j;
	cin >> n >> d;
	vi A(n);
	cin >> A;
	bool ok = 1;
	for (int x : A)
		if (x>d)
			ok = 0;
	sort(all(A));
	if (ok)
		print("Yes");
	else
	Yes(A[0] + A[1] <= d);

}















int main() {


    __speed() tt solve();

    return 0;
}
