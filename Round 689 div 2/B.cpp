// Author :: <Hitesh_Saini>
#include<bits/stdc++.h>
#define f1(i, n) for(i = 1; i<= n; i++)


using namespace std;
using ll = long long;



void solve(){//D
 	ll i, j, n, m, r=0;
 	char A[505][505]={};
 	int d[505][505]={};
	cin >> n >> m;

	f1(i, n) f1(j, m) cin >> A[i][j], d[i][j] = A[i][j] = A[i][j]=='*';

	for(i=n-1;i;--i) f1(j, m-1)
			if(A[i][j] && A[i+1][j])
				d[i][j] += min(d[i+1][j-1], d[i+1][j+1]);
	
	f1(i, n)
		f1(j, m)
			r += d[i][j];

	cout << r << '\n';
}

int main(){
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin); 
		freopen("output.txt", "w", stdout);
	#endif
    int t;for(cin>>t; t--; ) solve();
    return 0;
}
