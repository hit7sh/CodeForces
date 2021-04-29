#include "bits/stdc++.h"
using namespace std;

const int N = 1e5 + 5;
const int INF = 1e9;
using ll = int64_t;
const ll LINF = 1e14;


struct my_node
{
	ll mn = LINF;			// <-----
	// use more variables if you want more information
	// these default values should be identity_element
	my_node(){}
	my_node(ll val){
		mn = val;			
	}
	void merge(const my_node &l,const my_node &r){ // store the thing you wanna query
		
		mn = min(l.mn, r.mn);			// <-----

		// if we wanted the maximum, then we would do
		// like v = max(l.v,r.v)
	}
};

// example: add on a range: identity transformation = 0
// old += new

// if old is identity which is 0, then 0 + new which new

struct my_update
{
	ll v = 0; // 4			// <-----
	// use more variables if you want more information
	// these default values should be identity_transformation
	my_update(){}
	my_update(ll val){
		v = val; // 5
	}
	// combine the current my_update with the other my_update (see keynotes)
	void combine(my_update &other,const ll &tl,const ll &tr){
		v += other.v; // 6
											// <-----
		// you can be sure that the "other" is newer than current
		
	}
	// store the correct information in the node x
	void apply(my_node &x,const ll &tl,const ll &tr){
		
		// no change in freq
		x.mn += v;			// <-----
		
	}
};

template<typename node,typename update>
struct segtree
{
	int len;
	vector<node> t;
	vector<update> u;
	vector<bool> lazy;
	node identity_element;
	update identity_transformation;
	segtree(int l){
		len = l;
		t.resize(4 * len);
		u.resize(4 * len);
		lazy.resize(4 * len);
		identity_element = node();
		identity_transformation = update();
	}	
	
	void pushdown(const ll &v, const ll &tl, const ll &tr){
		if(!lazy[v]) return;
		ll tm = (tl + tr) >> 1;
		apply(v<<1,tl,tm,u[v]);
		apply(v<<1|1,tm+1,tr,u[v]);
		u[v] = identity_transformation;
		lazy[v] = 0;
	}
	
	void apply(const ll &v, const ll &tl, const ll &tr, update upd){
		if(tl != tr){
			lazy[v] = 1;
			u[v].combine(upd,tl,tr);
		}
		upd.apply(t[v],tl,tr);
	}
	
	template<typename T>
	void init(const T &arr,const ll &v, const ll &tl, const ll &tr){
		if(tl == tr){
			t[v] = arr[tl];
			return;
		}
		ll tm = (tl + tr) >> 1;
		init(arr,v<<1,tl,tm);
		init(arr,v<<1|1,tm+1,tr);
		t[v].merge(t[v<<1],t[v<<1|1]);
	}
	
	node query(const ll &v,const ll &tl,const ll &tr,const ll &l,const ll &r){
		if(l > tr || r < tl){
			return identity_element;
		}
		if(tl >= l && tr <= r){
			return t[v];
		}
		pushdown(v,tl,tr);
		ll tm = (tl + tr) >> 1;
		node a = query(v<<1,tl,tm,l,r),b = query(v<<1|1,tm+1,tr,l,r),ans;
		ans.merge(a,b);
		return ans;
	}
	
	// rupd = range update
	void rupd(const ll &v,const ll &tl,const ll &tr,const ll &l,const ll &r,const update &upd){
		if(l > tr || r < tl){
			return;
		}
		if(tl >= l && tr <= r){
			apply(v,tl,tr,upd);
			return;
		}
		pushdown(v,tl,tr);
		ll tm = (tl + tr) >> 1;
		rupd(v<<1,tl,tm,l,r,upd);
		rupd(v<<1|1,tm+1,tr,l,r,upd);
		t[v].merge(t[v<<1],t[v<<1|1]);
	}
	
	public:
	template<typename T>
	void init(const T &arr){
		init(arr,1,0,len-1);
	}
	node query(const ll &l,const ll &r){
		return query(1,0,len-1,l,r);
	}
	void rupd(const ll &l,const ll &r,const update &upd){
		rupd(1,0,len-1,l,r,upd);
	}
};

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;			
	
	for (cin >> t; t; t--) {
		int n, i;
		cin >> n;
vector<segtree<my_node, my_update>> T(2, segtree<my_node, my_update>(n));
		vector<ll> A(n);
		T[0].init(A), T[1].init(A);
		for (ll& x : A) cin >> x;
		ll sum = 0; 

		for (i = n - 1; i >= 0; i--) {
			sum = A[i] - sum;
			T[i & 1].rupd(i, i, sum);
			T[~i & 1].rupd(i, i, LINF);
		}


		function<bool()> check = [&]() {
			if (T[0].query(0, 0).mn != 0) return false;
			return (T[0].query(0, n - 1).mn >= 0 && T[1].query(0, n - 1).mn >= 0);
		};
		function<void(ll, ll)> update = [&](ll pos, ll v) {
			T[pos&1].rupd(0, pos, v);
			T[~pos&1].rupd(0, pos, -v);
		};
		bool ok = check(); 
		for (i = 0; i + 1 < n; i++) {
			ll v = A[i + 1] - A[i];

			update(i, v);
			update(i + 1, -v);
			ok |= check();


			update(i, -v);
			update(i + 1, v);
		}
		puts(ok ? "YES" : "NO");
	}
	return 0;
}
