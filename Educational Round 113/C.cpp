#include <bits/stdc++.h>
using namespace std;

// ============================
using ll = int64_t;
const int mxN = 2e5 + 5;
const int MOD = 998244353;
struct mi {
  ll v; explicit operator ll() const { return v; }
  mi() { v = 0; }
  mi(ll _v) { 
    v = (-MOD < _v && _v < MOD) ? _v : _v % MOD;
    if (v < 0) v += MOD;
  }
  friend bool operator==(const mi& a, const mi& b) { 
    return a.v == b.v; }
  friend bool operator!=(const mi& a, const mi& b) { 
    return !(a == b); }
  friend bool operator<(const mi& a, const mi& b) { 
    return a.v < b.v; }
   
  mi& operator+=(const mi& m) { 
    if ((v += m.v) >= MOD) v -= MOD; 
    return *this; }
  mi& operator-=(const mi& m) { 
    if ((v -= m.v) < 0) v += MOD; 
    return *this; }
  mi& operator*=(const mi& m) { 
    v = v*m.v%MOD; return *this; }
  mi& operator/=(const mi& m) { return (*this) *= inv(m); }
  friend mi pow(mi a, ll p) {
    mi ans = 1; assert(p >= 0);
    for (; p; p /= 2, a *= a) if (p&1) ans *= a;
    return ans;
  }
  friend mi inv(const mi& a) { //assert(a.v != 0); 
    return pow(a,MOD-2); }
    
  mi operator-() const { return mi(-v); }
  mi& operator++() { return *this += 1; }
  mi& operator--() { return *this -= 1; }
    mi operator++(int) { mi temp; temp.v = v++; return temp; }
    mi operator--(int) { mi temp; temp.v = v--; return temp; }
  friend mi operator+(mi a, const mi& b) { return a += b; }
  friend mi operator-(mi a, const mi& b) { return a -= b; }
  friend mi operator*(mi a, const mi& b) { return a *= b; }
  friend mi operator/(mi a, const mi& b) { return a /= b; }
    friend ostream& operator<<(ostream& os, const mi& m) {
        os << m.v; return os;
    }
    friend istream& operator>>(istream& is, mi& m) {
        ll x; is >> x;
        m.v = x;
        return is;
    }
};
//=================================

vector<mi> fact(mxN);

void init() {
  fact[0] = 1;
  for (int i = 1; i < mxN; i++)
    fact[i] = mi(i) * fact[i - 1];
}

mi C(int n, int r) {
  return fact[n] / fact[r] / fact[n - r];
}

int main() {
  init();
  int t;
  for (cin >> t; t; t--) {
    int n;
    cin >> n;
    vector<int> A(n);
    for (int& x : A) cin >> x;
    sort(A.begin(), A.end());

    if (A[n - 1] - 2 >= A[n - 2]) cout << "0\n";
    else if (A[n - 1] == A[n - 2]) cout << fact[n] << '\n';
    else {
      int smax = A[0], cnt = 0;
      for (int x : A) if (x ^ A[n - 1]) smax = x;
      for (int x : A) cnt += x == smax;

      mi ans = fact[n], r = 0;
      for (int i = 0; i < n; i++) {
        if (n - i - 1 < cnt) break;
        r += C(n - 1 - cnt, i) * fact[i] * fact[n - i - 1];
      }
      ans -= r;
      cout << ans << '\n';
    }
  }
  return 0;
}
