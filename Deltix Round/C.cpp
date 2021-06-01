void solve() {
    int n, cur = 0;
    cin >> n;
    vi A(n);
    vector<int> has;
    cin >> A;
    has.EB(A[0]);
    cout << A[0] << endl;
    cur = A[0];
 
    for (int i = 1; i < n; i++) {
        string s = "";
        if (A[i] == 1) {
            has.EB(A[i]);
            for (int& x : has)
                s += to_string(x) + ".";
            s.pop_back();
            print(s);
 
            cur = A[i];
            // dbg(cur);
        } else {
            cur = A[i];
            while (!has.empty() && cur - has.back() != 1) has.pop_back();
            if (sz(has)) has.pop_back();
            has.EB(A[i]);
            for (int& x : has)
                s += to_string(x) + '.';
            s.pop_back();
            print(s);
        }
        // cout << endl;
    }
}
