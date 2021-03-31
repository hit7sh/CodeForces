// Author :: <Hitesh_Saini>
#include<bits/stdc++.h>
 
#define __speed() ios_base::sync_with_stdio(false), cin.tie(nullptr);
#define dbg(x) cout << "(" << __LINE__ << ": "<< #x << " = " << x << ")\n"
 
#define Yes(x) print((x) ? "Yes" : "No")
#define tt 	int t; for (cin >> t; t--; )
 
#define f0(i, n)  for (i = 0; i < (int)(n); i++)
#define f1(i, n)  for (i = 1; i <=(int)(n); i++)
 
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define sz(x) (int)(x.size())
 
#define EB emplace_back
#define PB push_back

#define endl "\n"
#define S second
#define F first

 
using namespace std;
using mii = map<int, int>;
using pii = pair<int, int>;
 
using ll = int64_t;
using vi = vector<int>;
 
using vvi = vector<vi>;
using vl = vector<ll>;
 
const int mod = 1e9+7, mxN = 5e6+5, INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
 
 
template <typename... T> void print(T... args) { ((cout << args << " "), ...), cout << endl; }
 
template <typename T1, typename T2> istream& operator>>(istream& in, pair<T1, T2>& p) { in >> p.F >> p.S; return in; }
template <typename T1, typename T2> ostream& operator<<(ostream& ot, pair<T1, T2>& p) { ot << p.F << ' ' << p.S; return ot; }

template <typename T1, typename T2> bool cmax(T1& a, T2 b) { if (b > a) { a = b; return true;} return false; }
template <typename T1, typename T2> bool cmin(T1& a, T2 b) { if (b < a) { a = b; return true;} return false; }
 
template <typename T> istream& operator>>(istream& in, vector<T>& v) { for (T& x:v) in >> x; return in; }
template <typename T> ostream& operator<<(ostream& ot, vector<T>& v) { for (T& x:v) ot << x << ' '; return ot; }


map<int, int> mp;
pii rev(int h, int m) {
	swap(h, m);
	string hh, mm;
	bool bad = 0;
	string sh = to_string(h), sm = to_string(m);
	if (h < 10)
		sh = '0' + sh;
	if (m < 10)
		sm = '0' + sm;
	reverse(all(sh));
	reverse(all(sm));
	for (char& x : sh) {
		if (!mp.count(x - '0')) {
			bad = 1;
			break;
		}
		hh += mp[x - '0'] + '0';
	}
	for (char& x : sm) {
		if (!mp.count(x - '0')) {
			bad = 1;
			break;
		}
		mm += mp[x - '0'] + '0';
	}
	if (bad) return {-1, -1};
	return make_pair(stoi(hh), stoi(mm));
}

void solve() {
	int h, m, hh, mm, i, j;
	cin >> h >> m;
	string s;
	cin >> s;
	string h1;
	f0(i, 10)
		if (s[i] == ':')
			break;
		else
			h1 += s[i];
	hh = stoi(h1);
	mm = stoi(s.substr(i+1));
	// print(hh, mm);
	for (i = hh; i < h; i++) {
		j = 0;
		if (i == hh)
			j = mm	;
		for (; j < m; j++) {
			auto [rh, rm] = rev(i, j);
			if (rh == -1)
				continue;
			else {
				if (rh >= 0 && rm >= 0 && rh < h && rm < m) {
					// print(rh, rm);
					if (i < 10)
					cout << 0;
					cout << i << ':';
					if (j < 10)
					cout << 0;
					cout << j << endl;
					return;
				}
			}
		}
	}
	for (i = 0; i <= hh; i++) {
		for (j = 0; j < m; j++) {
			auto [rh, rm] = rev(i, j);
			if (rh == -1)
				continue;
			else {
				if (rh >= 0 && rm >= 0 && rh < h && rm < m) {
					if (i < 10)
					cout << 0;
					cout << i << ':';
					if (j < 10)
					cout << 0;
					cout << j << endl;
					return;
				}
			}
		}
	}	
}




 
	

main() {
	mp[0] = 0;
	mp[1] = 1;
	mp[5] = 2;
	mp[2] = 5;
	mp[8] = 8;
	__speed() tt solve();						
}
