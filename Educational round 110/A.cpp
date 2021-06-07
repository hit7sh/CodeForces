void solve() {
 vi s(4), t;
 cin >> s;
 t = s;
 sort(all(t));
 vi A = {max(s[0], s[1]), max(s[2], s[3])};
 sort(all(A));
 Yes(A[1] == t[3] && A[0] == t[2]);
}
