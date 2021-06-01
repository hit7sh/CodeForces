 
void solve() {
    ll n, i;
    cin >> n;
    vl A(n);
    cin >> A;
    print(6 * (n / 2));
    for (i = 0; i < n / 2; i++) {
        ll j = n - i - 1 + 1;
        print(1, i + 1, j);
        print(2, i + 1, j);
        print(2, i + 1, j);
        print(1, i + 1, j);
        print(2, i + 1, j);
        print(2, i + 1, j);
    }
}
 
