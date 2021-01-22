// Author :: <Hitesh_Saini>
#include<bits/stdc++.h>

#define __speed() ios_base::sync_with_stdio(false), cin.tie(nullptr);
#define dbg(x) cout << "[" << __LINE__ << ": "<< #x << " = " << x << " ]\n"

#define Yes(x) print((x) ? "Yes" : "No")
#define tt 	int t; for (cin >> t; t--; )

#define f0(i, n)  for (i = 0; i < (int)(n); i++)
#define f1(i, n)  for (i = 1; i <=(int)(n); i++)


using namespace std;

template <typename... T> void print(T... args) { ((cout << args << " "), ...), cout << endl; }





void solve() {
	int n, i;
	string b, a="";
	cin >> n >> b;
	int cs = b[0] - '0' + 1, prev = 1;
	a += prev^48;
	f1(i, n-1) {
		if (b[i] - '0' + 1 != cs)
			prev = 1, cs = b[i] - '0' + 1;
		else
			prev = 0, cs = b[i]^48;
		a += prev^48;
	}
    print(a);
}















int main() {

    __speed() tt solve();

    return 0;
}
