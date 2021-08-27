#include<bits/stdc++.h>
using namespace std;
 
 
int main() {
    int t;
    for (cin >> t; t; t--) {
        int n;
        string s;
        cin >> n >> s;
        int pos = -1;
        for (int i = 0; i < n; i++) {
            if (s[i] == '0') {
                pos = i;
                break;
            }
        }
        if (pos == -1) {
            cout << 1 << ' ' << n - 1 << ' ' << 2 << ' ' << n << '\n';
        } else if (pos < n / 2) {
            cout << pos + 1 << ' ' << n << ' ' << pos + 2 << ' ' << n << '\n';
        } else {
            cout << 1 << ' ' << pos + 1 << ' ' << 1 << ' ' << pos << '\n';
        }
    }
    return 0;
}
