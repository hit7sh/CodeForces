 
void solve() {
	int n;
    std::cin >> n;
    std::vector<int> s(n);
    for (int i = 0; i < n; i++) {
        std::cin >> s[i];
    }
    int64_t ans = 0;
    vector<int64_t> peko(n);
    for (int i = 0; i < n; i++) {
        ll need = max(0ll, s[i] - 1 - peko[i]);
        ans += need;
        peko[i] += need;
        
        for (int j = i + 2; j <= min(n - 1, i + s[i]); j++) {
            peko[j]++;
        }
        if (i + 1 < n) {
            peko[i + 1] += peko[i] - (s[i] - 1); // remaining 
        }
    }
    print(ans);
}
 
