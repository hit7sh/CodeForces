const int H = 20;
int jump[H][300005];

void solve() {
  int q;
  cin >> q;
  vl A(q + 1), C(q + 1);
  for (int i = 0; i < H; i++)
    jump[i][0] = -1;
  cin >> A[0] >> C[0];

  for (int i = 0; i < H; i++) jump[i][0] = 0; 

  for (int i = 1; i <= q; i++) {
    int t, p;
    cin >> t;
    if (t == 1) {
      cin >> p >> A[i] >> C[i];
      jump[0][i] = p;
      for (int j = 1; j < H; j++) 
        jump[j][i] = jump[j - 1][jump[j - 1][i]];
      // j-th ancestor of i = (j - 1)th ancestor of (j - 1)th ancestor of i
    } else {
      ll from, w;
      cin >> from >> w;
      ll amt = 0, money = 0;

      while (w > 0) {
        int z = from;
        for (int j = H - 1; j >= 0; j--) {
          if (~jump[j][z] && A[jump[j][z]]) z = jump[j][z];
        }

        ll quan = min(w, A[z]);
        amt += quan;
        money += C[z] * quan;
        // print(z, i);
        w -= quan;
        A[z] -= quan;
        if (z == from) break;
      }
      print(amt, money);
    }
  }
} 
