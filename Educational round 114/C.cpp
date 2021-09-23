#include<bits/stdc++.h>
using namespace std;

using ll = int64_t;

int main() {
cin.tie(0)->sync_with_stdio(0), cin.exceptions(cin.failbit);
  ll n;
  cin >> n;
  vector<ll> A(n);
  for (ll& x : A) cin >> x;
  sort(A.begin(), A.end());
  ll m;
  cin >> m;
  ll x, y;
  vector<ll> pref(n + 1);
  for (int i = 0; i < n; i++) pref[i + 1] = A[i] + pref[i];
  while (m--) {
    cin >> x >> y;
    // A[n - 1] >= x
    // A[0] + .. A[n - 2] >= y
    auto it = lower_bound(A.begin(), A.end(), x);
    ll prev = -1, nxt = -1;
    if (it != A.end()) nxt = *it;
    if (it != A.begin()) it--, prev = *it;
    ll ans = LLONG_MAX;
    // either take previous fighter or next
    if (~prev) ans = x - prev + max(0LL, y - (pref[n] - prev));
    if (~nxt) ans = min(ans, max(0LL, y - (pref[n] - nxt)));
    cout << ans << '\n';
  }

  return 0;
}
