// Author :: <Hitesh_Saini>
#include<bits/stdc++.h>

#define __speed() ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#define dbg(x) cout << "[" << __LINE__ << ": "<< #x << " = " << x << " ]\n";
#define tt int t;for(cin>>t; t--; )


using namespace std;

template<typename... Args>inline void print(Args... args){((cout << args << " "), ...); cout << endl;}

void solve(){//b
	string s;
	cin >> s;
	int ans =0;
	for(int i=1;i<s.size();i++){
		if(s[i]==s[i-1]||s[i]==s[i-2])
			ans ++, s[i]='#';
	}
	print(ans);
}

signed main(){
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif
    __speed() tt solve();
    return 0;
}
