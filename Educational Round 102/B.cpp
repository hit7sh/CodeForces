// Author :: <Hitesh_Saini>
#include<bits/stdc++.h>

#define __speed() ios_base::sync_with_stdio(false), cin.tie(nullptr);
#define dbg(x) cout << "[" << __LINE__ << ": "<< #x << " = " << x << " ]\n"

#define Yes(x) print((x) ? "Yes" : "No")
#define tt 	int t; for (cin >> t; t--; )


#define sz(x) (int)(x.size())




using namespace std;


template <typename... T> void print(T... args) { ((cout << args << " "), ...), cout << endl; }



string mul(int n, string s) {
	string t="";
	while(n--)
		t += s;
	return t;
}

void solve() {
	string s, t;
	cin >> s >> t;
	if (sz(t) > sz(s))
		swap(s, t);

	int l1 = sz(s), l2 = sz(t), l = lcm(l1, l2);
  
	if (mul(l/l2, t) == mul(l/l1, s))
		print(mul(l/l2, t));
	else
		print(-1);
}



int main() {

    __speed() tt solve();

    return 0;
}
