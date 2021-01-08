// Author :: <Hitesh_Saini>
#include<bits/stdc++.h>

#define __speed() ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#define dbg(x) cout << "[" << __LINE__ << ": "<< #x << " = " << x << " ]\n";
#define tt int t; for (cin>>t; t--; )

#define f0(i, n)  for (i = 0; i < (int)(n); i++)
#define sz(x) (int)(x.size())


using namespace std;
using vi = vector<int>;



void solve() {
	int n, i, j;
	cin >> n;
	string s = "989";	
	string s2 = "0123456789";
	if (n<=sz(s)) {
		cout << s.substr(0, n) << endl;
		return;
	}
	cout << s;
	n-= sz(s);
	f0(i, n)
		cout << s2[i%sz(s2)];
	cout<< endl;
}

int main() {
    __speed() tt solve();
    return 0;
}
