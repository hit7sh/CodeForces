// Author :: <Hitesh_Saini>
#include<bits/stdc++.h>
 
#define __speed() ios_base::sync_with_stdio(false), cin.tie(nullptr);
#define dbg(x) cout << "(" << __LINE__ << ": "<< #x << " = " << x << ")\n"
 
#define Yes(x) print((x) ? "Yes" : "No")
#define tt 	int t; for (cin >> t; t--; )
 
using namespace std;
using vi = vector<int>;
 
template <typename... T> void print(T... args) { ((cout << args << " "), ...), cout << endl; }
template <typename T> istream& operator>>(istream& in, vector<T>& v) { for (T& x:v) in >> x; return in; }


 


 
void solve() {
	int n, i, k, j;
	cin >> n >> k;
	vi A(n);
	cin >> A;

	for (i = 1; i <= k; i++) {
		j = 0;
		while (j < n-1) {
			if (A[j] < A[j+1])
				break;
			j++;
		}
		if (j == n-1) {
			print(-1);
			return;
		}
		A[j]++;
	}
	print(j+1);
}

 


int main() {
	__speed() tt solve();
}
