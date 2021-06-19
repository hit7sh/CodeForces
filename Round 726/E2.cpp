void solve() {
  int N, K; cin >> N >> K;
    string S; cin >> S;
 
    vi Z = zFun(S);
    string T; T += S[0];
    for (int i = 1; i < N; i++) {
        if (i + Z[i] >= N) break;
        if (S[i+Z[i]] > S[Z[i]]) break;
        T += S[i];
    }
    int n = sz(T);
    for (int i = 0; i < K; i++) 
      cout << T[i % n];
}
 
