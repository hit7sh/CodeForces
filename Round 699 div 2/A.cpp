// Author :: <Hitesh_Saini>
#include<bits/stdc++.h>
 
#define __speed() ios_base::sync_with_stdio(false), cin.tie(nullptr);

#define Yes(x) print((x) ? "Yes" : "No")
#define tt 	int t; for (cin >> t; t--; )
 
using namespace std;
 
template <typename... T> void print(T... args) { ((cout << args << " "), ...), cout << endl; }
 


 
void solve() {
	int n, i;
	int l = 0, r = 0, u = 0, d = 0, x, y;
	cin >> x >> y;
	string s;
	cin >> s;
	for (char& x:s)
		if (x=='L')
			l--;
		else if (x=='R')
			r++;
		else if(x=='U')
			u++;	
		else
			d--;

	bool ok = x >= l && x<=r;
	ok &= y >= d && y<= u;
	Yes(ok);
}
 




int main() {
	__speed() tt solve();
}
