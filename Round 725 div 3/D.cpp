#include<bits/stdc++.h>
using namespace std;
 
int count(int n) {
    int c = 0;
    for (int i = 2; i * i <= n; i++)
        while (n % i == 0)
            c++, n /= i;
    if (n > 1)
        c++;
    return c;
}
 
int main() {
    int t;
    for (cin >> t; t; t--) {
        int a, b, k;
        cin >> a >> b >> k;
        if (a > b) swap(a, b);
 
        if (k == 1 && a == 1 && b != 1) {
            cout << "Yes\n";
            continue;
        }
 
        if ((a == 1 && b == 1) or (a == b && k == 1)) {
            cout << "No\n";
            continue;
        }
        cout << ((k >= 1 + (b % a != 0) && k <= count(a) + count(b)) ? "Yes" : "No") << "\n";
    }
    return 0;
}
