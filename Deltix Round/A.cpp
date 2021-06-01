 
void solve() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    vi A(n);
 
    for (ll i = 0; i < n; i++) {
        A[i] = s[i] ^ 48;
    }
 
    int c0 = count(all(A), 0), put = 1;
    // print(A);
 
    for (int j = 0; j < k; j++) {
        if (c0 == 0) break;
        vi idx;
        for (int i = 0; i < n; i++)
        if (A[i] == 0) {
            int c = 0;
            if (i - 1 >= 0 && A[i - 1] == 1) c++;
            if (i + 1 < n && A[i + 1] == 1) c++;
            if (c == 1) idx.EB(i), c0--;
        }
        for (int& x : idx) A[x] = 1;
        if (sz(idx) == 0) break;
    }
    for (int i = 0; i < n; i++) cout << !!A[i];
        cout << endl;
}
 
