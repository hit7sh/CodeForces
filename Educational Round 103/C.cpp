// Author :: <Hitesh_Saini>
#include<bits/stdc++.h>
 
#define __speed() ios_base::sync_with_stdio(false), cin.tie(nullptr);
#define dbg(x) cout << "(" << __LINE__ << ": "<< #x << " = " << x << ")\n"
 
#define Yes(x) print((x) ? "Yes" : "No")
#define tt 	int t; for (cin >> t; t--; )

#define cmax(x, y) x = max(x, y)
#define cmin(x, y) x = min(x, y)
 

 
 
using namespace std;

using ll = int64_t;
using vl = vector<ll>;

 
template <typename... T> void print(T... args) { ((cout << args << " "), ...), cout << endl; }
template <typename T> istream& operator>>(istream& in, vector<T>& v) { for (T& x:v) in >> x; return in; }
 



 
void solve() {
	int n, i;
	cin >> n;
	vl A(n), B(n), C(n);
	cin >> C >> A >> B;
	ll cnt = 0, ans = 0;

	for (i = 1; i < n; i++) {
		if (A[i] == B[i])
			cnt = 2;
		else {
			if (cnt == 0)
				cnt = abs(A[i] - B[i]) + 2;
			else
				cnt = max(abs(A[i]-B[i]) + 2, cnt+2+C[i-1]-1-abs(A[i]-B[i]));
		}
		cmax(ans, cnt + C[i] -1);
	}
	print(ans);
}
 


int main() {
	__speed() tt solve();
}
