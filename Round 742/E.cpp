struct node 
{
  ll cnt = 0;
  int len = 0, pref = 0, suf = 0, first, last;
  node(int v = -1, int l = 0) {
    first = last = v;
    cnt = len = pref = suf = l;
  }
  // use more variables if you want more information
  // these default values should be identity_element
 
  void merge(const node &l,const node &r){ // store the thing you wanna query
    // if (l.len == 0 or r.len == 0) return;
    cnt = l.cnt, len = l.len, pref = l.pref, suf = l.suf, first = l.first, last = l.last;
    if (l.last <= r.first)
      cnt += l.suf * 1LL * r.pref;
 
    if (l.pref == l.len && l.last <= r.first)
      pref += r.pref;
 
    if (r.suf == r.len && l.last <= r.first)
      suf += r.len;
    else suf = r.suf;
 
    cnt += r.cnt;
    len += r.len;
    last = r.last;
  }
};
 
// example: add on a range: identity transformation = 0
// old += new
 
// if old is identity which is 0, then 0 + new which new
 
struct update 
{
  int v = 0; // 4      // <-----
  // use more variables if you want more information
  // these default values should be identity_transformation
  update(){}
  update(int val){
    v = val; // 5
  }
  // combine the current update with the other update (see keynotes)
  void combine(update &other,const ll &tl,const ll &tr){
    v = other.v; // 6
                      // <-----
    // you can be sure that the "other" is newer than current
    
  }
  // store the correct information in the node x
  void apply(node &x,const ll &tl,const ll &tr){
    
    // no change in freq
    x = node(v, (tr - tl + 1));
  }
};
 
template<typename T_node, typename T_update>
struct segtree
{
  int len;
  vector<T_node> t;
  vector<T_update> u;
  vector<bool> lazy;
  T_node identity_element;
  T_update identity_transformation;
  segtree(int l){
    len = l;
    t.resize(4 * len);
    u.resize(4 * len);
    lazy.resize(4 * len);
    identity_element = T_node();
    identity_transformation = T_update();
  } 
  
  void pushdown(const ll &v, const ll &tl, const ll &tr) {
    if(!lazy[v]) return;
    ll tm = (tl + tr) >> 1;
    apply(v<<1,tl,tm,u[v]);
    apply(v<<1|1,tm+1,tr,u[v]);
    u[v] = identity_transformation;
    lazy[v] = 0;
  }
  
  void apply(const ll &v, const ll &tl, const ll &tr, T_update upd) {
    if(tl != tr){
      lazy[v] = 1;
      u[v].combine(upd,tl,tr);
    }
    upd.apply(t[v],tl,tr);
  }
  
  template<typename T>
  void init(const T &arr,const ll &v, const ll &tl, const ll &tr) {
    if(tl == tr) { 
      t[v] = arr[tl];
      return;
    }
    ll tm = (tl + tr) >> 1;
    init(arr,v<<1,tl,tm);
    init(arr,v<<1|1,tm+1,tr);
    t[v].merge(t[v<<1],t[v<<1|1]);
  }
  
  T_node query(const ll &v,const ll &tl,const ll &tr,const ll &l,const ll &r) {
    if(l > tr || r < tl){
      return identity_element;
    }
    if(tl >= l && tr <= r){
      return t[v];
    }
    pushdown(v,tl,tr);
    ll tm = (tl + tr) >> 1;
    T_node a = query(v<<1,tl,tm,l,r),b = query(v<<1|1,tm+1,tr,l,r),ans;
    ans.merge(a,b);
    return ans;
  }
  
  // rupd = range T_update
  void rupd(const ll &v,const ll &tl,const ll &tr,const ll &l,const ll &r,const T_update &upd) {
    if(l > tr || r < tl){
      return;
    }
    if(tl >= l && tr <= r){
      apply(v,tl,tr,upd);
      return;
    }
    pushdown(v,tl,tr);
    ll tm = (tl + tr) >> 1;
    rupd(v<<1,tl,tm,l,r,upd);
    rupd(v<<1|1,tm+1,tr,l,r,upd);
    t[v].merge(t[v<<1],t[v<<1|1]);
  }
  
  public:
  template<typename T>
  void init(const T &arr){
    init(arr,1,0,len-1);
  }
  T_node query(const ll &l,const ll &r){
    return query(1,0,len-1,l,r);
  }
  void rupd(const ll &l,const ll &r,const T_update &upd){
    rupd(1,0,len-1,l,r,upd);
  }
};
 
 
void solve() {
  int n, q, x;
  cin >> n >> q;
  segtree<node, update> T(n);
 
  f0(i, n) {
    cin >> x;
    T.rupd(i, i, update(x));
  }
 
  // dbg(T.query(0, 1).cnt);
 
  while (q--) {
    int t, x, y;
    cin >> t >> x >> y;
    if (t == 1) {
      x--;
      T.rupd(x, x, y);
    } else {
      x--, y--;
      print(T.query(x, y).cnt);
    }
  }
}
