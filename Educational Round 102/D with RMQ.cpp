// Author :: <Hitesh_Saini>
#include<bits/stdc++.h>

#define __speed() ios_base::sync_with_stdio(false), cin.tie(nullptr);
#define tt 	int t; for (cin >> t; t--; )

#define f0(i, n)  for (i = 0; i < (int)(n); i++)


using namespace std;
using vi = vector<int>;

template <typename... T> void print(T... args) { ((cout << args << " "), ...), cout << endl; }



template<typename T, bool maximum_mode = false>
struct RMQ {                // based on 0 indexing, passed array is 0 indexed
    int n = 0;
    vector<T> values;
    vector<vector<int>> range_low;
 
    RMQ(const vector<T> &_values = {}) {
        if (!_values.empty())
            build(_values);
    }
 
    static int largest_bit(int x) {
        return x == 0 ? -1 : 31 - __builtin_clz(x);
    }
 
    // Note: when `values[a] == values[b]`, returns b.
    int better_index(int a, int b) const {
        return (maximum_mode ? values[b] < values[a] : values[a] < values[b]) ? a : b;
    }
 
    void build(const vector<T> &_values) {
        values = _values;
        n = int(values.size());
        int levels = largest_bit(n) + 1;
        range_low.resize(levels);
 
        for (int k = 0; k < levels; k++)
            range_low[k].resize(n - (1 << k) + 1);
 
        for (int i = 0; i < n; i++)
            range_low[0][i] = i;
 
        for (int k = 1; k < levels; k++)
            for (int i = 0; i <= n - (1 << k); i++)
                range_low[k][i] = better_index(range_low[k - 1][i], range_low[k - 1][i + (1 << (k - 1))]);
    }
 
    // Note: breaks ties by choosing the largest index.
    int query_index(int a, int b) const {
        assert(0 <= a && a < b && b <= n);
        int level = largest_bit(b - a);
        return better_index(range_low[level][a], range_low[level][b - (1 << level)]);
    }
 
    T qry(int a, int b) const { // qry[a, b] inclusive
    	b++;
        if (a == b)
            return values[a];
        return values[query_index(a, b)];
    }
};
 



void solve() {
	int i, q, l, r=0, n;
	cin >> n >> q;
	vi A(n);
  
	f0(i, n) {
		char x;
		cin >> x;
		r += (x == '+')? +1 : -1;
    A[i] = r;
	}
  
	RMQ<int> rmn; rmn.build(A);
	RMQ<int, true> rmx; rmx.build(A);
	
	while(q--) {
		cin >> l >> r;
		--l, --r;

		int _min = 0, _max = 0, dif = A[r] - (l-1>=0?A[l-1]:0);
		if (l - 1 >= 0)_min = min(_min, rmn.qry(0, l - 1));
		if (r + 1 < n)_min = min(_min, rmn.qry(r + 1, n-1) - dif);
 
		if (l - 1 >= 0)_max = max(_max, rmx.qry(0, l - 1));
		if (r + 1 < n)_max = max(_max, rmx.qry(r + 1, n-1) - dif);
 
		print(_max - _min + 1);
	}
}





int main() {
    __speed() tt solve();

    return 0;
}
