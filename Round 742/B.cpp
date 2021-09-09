vi xr(mxN);
void solve() {
  int M, X;
  cin >> M >> X;
  if (X == M or X == 0) {
    int to = xr[M - 1];
    if (to == X) print(M);
    else if ((to ^ X) == M) print(M + 2);
    else print(M + 1);
  } else {
    int to = xr[M - 1] ^ X;
    if (xr[M - 1] == X) print(M);
    else if (to == M) print(M + 2);
    else print(M + 1);
  }
}
 
