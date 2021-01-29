	// Author :: <Hitesh_Saini>
	#include<bits/stdc++.h>

	#define __speed() ios_base::sync_with_stdio(false), cin.tie(nullptr);
	#define dbg(x) cout << "[" << __LINE__ << ": "<< #x << " = " << x << " ]\n"

	#define Yes(x) print((x) ? "Yes" : "No")
	#define tt 	int t; for (cin >> t; t--; )

	#define f0(i, n)  for (i = 0; i < (int)(n); i++)
	#define f1(i, n)  for (i = 1; i <=(int)(n); i++)




	using namespace std;
	using mii = map<int, int>;
	using pii = pair<int, int>;

	using ll = long long;
	using vi = vector<int>;



	template <typename... T> void print(T... args) { ((cout << args << " "), ...), cout << endl; }

	template <typename T> istream& operator>>(istream& in, vector<T>& v) { for (T& x:v) in >> x; return in; }



bool has(int n, int d) {
	
	while(n) {
		if (n%10 == d)
			return true;
		n/=10;
	}
	return false;
}



void solve() {
	int i, j, q, d;
	cin >> q >> d;
	vi A(q);
	cin >> A;

	for (int x:A) {
		bool ok = has(x, d);
		f1(i, 1000) {
			x -= d;
			if (x < 0)
				break;
			if (x > 0 && has(x, d)) {
				
				ok = 1;
				break;
			}
		}
		Yes(ok);
	}
}






	int main() {

	    __speed() tt solve();

	    return 0;
	}
