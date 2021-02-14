#include<iostream>
using namespace std;
int64_t r, x, y, z, n, t;
main() {
    for (cin >> t; t--;) {
        cin >> x >> y;
        r = n = 0;
        while (++n, (z = min(x/n-n-1, y-n)) > 0) r += z;
	    cout << r << ' ';
    }
}
