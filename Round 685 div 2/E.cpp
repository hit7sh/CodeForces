// Author :: <Hitesh_Saini>
#include<bits/stdc++.h>

#define __speed() ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);

// #define endl "\n"   <-- endl updates the STDOUT file so dont modify it when solving interactive problems,
//                         otherwise after every cout you gotta use fflush(stdout);

using namespace std;
using vi = vector<int>;

void solve(){//A
	int n, and12, and13, and23, i;
	cin >> n;
	vi xv(n+1);
	for(i=2;i<=n;i++){
		cout << "XOR 1 " << i << endl;
		cin >> xv[i];
	}
	cout << "AND 1 2" << endl;
	cin >> and12;
	cout << "AND 1 3" << endl;
	cin >> and13;
	cout << "AND 2 3" << endl;
	cin >> and23;

	int a = xv[2] + 2*(and12);        //A[1]+A[2]=(A[1]^A[2])+2*(A[1]&A[2])
	int b = (xv[3]) + 2*(and13);      //A[1]+A[3]
	int c = (xv[2]^xv[3]) +2*(and23); //A[2]+A[3]
	int f = (a+b-c)/2;                // First element of array
  
	cout << "! " << (a+b-c)/2 << ' '; 
	for(i=2;i<=n;i++)
		cout << (xv[i]^f) << ' ';
	cout << endl;
}

signed main(){
    __speed() solve();
    return 0;
}
