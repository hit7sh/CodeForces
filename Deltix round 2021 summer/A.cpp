void solve() {
  int c, d;
  cin >> c >> d;
  if ((c & 1) ^ (d & 1)) print(-1);
  else if (c == d) {
    print(c != 0);
  } else print(2);
}
