// Author :: <Hitesh_Saini>
#include<bits/stdc++.h>
 
#define __speed() ios_base::sync_with_stdio(false), cin.tie(nullptr);
 
#define f0(i, n)  for (i = 0; i < (int)(n); i++)
#define f1(i, n)  for (i = 1; i <=(int)(n); i++)

#define endl "\n"


using namespace std;
 
using ll = int64_t;
using vi = vector<int>;
 

const int BLOCK = 550, N = 3e5 + 5;
int A[N], freq[N], ffreq[N], currMax = 0;

struct Query {
	int L, R, idx;
	bool operator<(Query other) const {
		if (L / BLOCK != other.L / BLOCK)
			return L / BLOCK < other.L / BLOCK;
		return R < other.R;
	}
} Q[N];

void add(int pos) {
	int preF = freq[A[pos]];
	freq[A[pos]]++;
	int currF = freq[A[pos]];
	
	ffreq[preF]--;
	ffreq[currF]++;
	
	if(currF > currMax)
		currMax = currF;
}

void remove(int pos) {
	int preF = freq[A[pos]];
	freq[A[pos]]--;
	int currF = freq[A[pos]];
	
	ffreq[preF]--;
	ffreq[currF]++;
	
	if (ffreq[currMax] == 0)
		currMax--;
}

void solve() {
	int n, q, i;
	cin >> n >> q;
	vi ans(q);
	f0(i, n) cin >> A[i];

	f0(i, q) cin >> Q[i].L >> Q[i].R, Q[i].idx = i, Q[i].L--, Q[i].R--;

	sort(Q, Q + q);

	int pL = 0, pR = -1;
	f0(i, q) {
		int L = Q[i].L;
		int R = Q[i].R;
		
		while(pL > L)
		pL-- , add(pL);
		
		while(pR < R)
		pR++ , add(pR);
		
		while(pL < L)
		remove(pL) , pL++;
		
		while(pR > R)
		remove(pR) , pR--;
		
		int total = Q[i].R - Q[i].L + 1;
		int rem = total - currMax;
		int half = (total+1)/2;
		
		if(currMax <= half)
			ans[Q[i].idx] = 1;
		else
			ans[Q[i].idx] = total - 2*rem;
	}
	f0(i, q)
		cout << ans[i] << ' ';
}
 




signed main() { 

	 __speed() solve();
	 // int t, i; for (cin >> t, i = 1; i <= t; i++) cout << "Case #" << i << ": ", solve();
}
