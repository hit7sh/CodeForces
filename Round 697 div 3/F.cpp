// Author :: <Hitesh_Saini>
#include<bits/stdc++.h>

#define __speed() ios_base::sync_with_stdio(false), cin.tie(nullptr);
#define dbg(x) cout << "[" << __LINE__ << ": "<< #x << " = " << x << " ]\n"

#define Yes(x) print((x) ? "Yes" : "No")
#define tt 	int t; for (cin >> t; t--; )

#define f0(i, n)  for (i = 0; i < (int)(n); i++)




using namespace std;


template <typename... T> void print(T... args) { ((cout << args << " "), ...), cout << endl; }

template <typename T> istream& operator>>(istream& in, vector<T>& v) { for (T& x:v) in >> x; return in; }


void solve() {
	int n, m, k, i, j;
	cin >> n;
	vector<string> A(n), B(n);
	cin >> A >> B;

	f0(i, n) {
		if (A[i][0] != B[i][0])
			f0(j, n)
				A[i][j] ^= 1;
	}

	f0(j, n)
		if (A[0][j] != B[0][j])
			f0(i, n)
				A[i][j] ^= 1;

	bool ok = 1;

	f0(i, n)
		f0(j, n)
			if (A[i][j] != B[i][j])
				ok = 0;
        
	Yes(ok);
}









int main() {

    __speed() tt solve();

    return 0;
}
