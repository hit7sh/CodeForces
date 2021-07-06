// Author :: <Hitesh_Saini>
#include<bits/stdc++.h>
 
#define __speed() ios_base::sync_with_stdio(false), cin.tie(nullptr);

#ifndef ONLINE_JUDGE
#define dbg(x) cout << "(" << __LINE__ << ": "<< #x << " = " << x << ")\n"
#else
#define dbg(x) x
#endif

#define Yes(x) print((x) ? "Yes" : "No")
#define tt  int t; for (cin >> t; t--; )
 
#define f0(i, n)  for (i = 0; i < (int)(n); i++)
#define f1(i, n)  for (i = 1; i <=(int)(n); i++)
 
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define sz(x) (int)(x.size())
 
#define EB emplace_back
#define PB push_back

#define LB lower_bound
#define UB upper_bound

// #define endl "\n"
#define S second
#define F first

using namespace std;
using mii = map<int, int>;
using pii = pair<int, int>;
 
using ll = int64_t;
using vi = vector<int>;
 
using vvi = vector<vi>;
using vl = vector<ll>;
 
const pair<int, int> DD[] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
const int mod = 1e9 + 7, mxN = 2e5 + 5, INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
 

template <typename... T> void print(T... args) { ((cout << args << " "), ...), cout << endl; }

template <typename T1, typename T2> istream& operator>>(istream& in, pair<T1, T2>& p) { in >> p.F >> p.S; return in; }
template <typename T1, typename T2> ostream& operator<<(ostream& ot, pair<T1, T2>& p) { ot << p.F << ' ' << p.S; return ot; }

template <typename T1, typename T2> bool cmax(T1& a, T2 b) { if (b > a) { a = b; return true; } return false; }
template <typename T1, typename T2> bool cmin(T1& a, T2 b) { if (b < a) { a = b; return true; } return false; }

template <typename T> istream& operator>>(istream& in, vector<T>& v) { for (T& x:v) in >> x; return in; }
template <typename T> ostream& operator<<(ostream& ot, vector<T>& v) { for (T& x:v) ot << x << ' '; return ot;}


void solve() {
  int N, K;
  cin >> N >> K;
  int dis[N + 1];
  vi par(N + 1);
  memset(dis, 0x3f, sizeof dis);
  queue<int> q;
  dis[0] = 0; par[0] = -1; q.push(0);

  while (!q.empty()) {
    int c = q.front(); q.pop(); // c -> num selected
    int can = min(c, K);
    int cant = K - can;
    for (; can >= 0 && c + cant <= N; can--, cant++) {
      int to = c - can + cant;
      if (dis[to] == INF) {
          dis[to] = dis[c]+1;
          par[to] = c;
          q.push(to);
      }
    }
  }

  if (dis[N] == INF) cout << "-1 " << endl;
  else {
    vector<int> path;
      for (int c = N; c != -1; c = par[c])
          path.push_back(c);
      reverse(path.begin(), path.end());
      int l = sz(path);
      // print(path);
      vi state(N + 1);
      int ans = 0;

      for (int i = 0; i < l - 1; i++) {
        int c = path[i];
        int can = min(c, K);
        int cant = K - can;
        for (; can >= 0 && c + cant <= N; can--, cant++) {
          int to = c - can + cant;
          vi res;
          if (to == path[i + 1]) {
          // print(c, to, can, cant);
            for (int j = 1; j <= N; j++) {
              if (can > 0 && state[j] == 1) {
                can--;
                state[j] = 0;
                res.EB(j);
              } else if (cant > 0 && state[j] == 0) {
                cant--;
                state[j] = 1;
                res.EB(j);
              }
            }
            print('?', res);
            cout << flush;
            int x;
            cin >> x;
            ans ^= x;
            break;
          }
        }
      }
  print('!', ans);cout << flush;
  }
} 






main() { 
  cout << fixed << setprecision(12);  

  __speed() solve();
  // int t, i; for (cin >> t, i = 1; i <= t; i++) cout << "Case #" << i << ": ", solve();
}
