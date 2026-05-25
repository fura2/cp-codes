#include "template/template.hpp"

template <class G>
class Fenwick_tree {
  vector<G> a;

 public:
  Fenwick_tree(int n = 0) { build(n); }
  Fenwick_tree(const vector<G>& a) { build(a); }
  void build(int n) { a.assign(n, G{}); }
  void build(const vector<G>& a) {
    this->a = a;
    for (int i = 1; i <= a.size(); i++)
      if (i + (i & -i) <= a.size())
        (this->a)[i + (i & -i) - 1] += (this->a)[i - 1];
  }
  void add(int i, const G& val) {
    for (i++; i <= a.size(); i += i & -i) a[i - 1] += val;
  }
  G sum(int l, int r) const {
    if (l == 0) {
      G res{};
      for (; r > 0; r -= r & -r) res += a[r - 1];
      return res;
    }
    return sum(0, r) - sum(0, l);
  }
  int lower_bound(G val) const {
    if (!(G{} < val)) return 0;
    int x = 0, k;
    for (k = 1; k <= a.size(); k <<= 1);
    for (k >>= 1; k > 0; k >>= 1)
      if (x + k <= a.size() && a[x + k - 1] < val) val -= a[x + k - 1], x += k;
    return x;
  }
  int upper_bound(G val) const {
    if (val < G{}) return 0;
    int x = 0, k;
    for (k = 1; k <= a.size(); k <<= 1);
    for (k >>= 1; k > 0; k >>= 1)
      if (x + k <= a.size() && !(val < a[x + k - 1]))
        val -= a[x + k - 1], x += k;
    return x;
  }
};

int main() {
  int n = input();
  int q = input();
  vector<int> a(n);
  Fenwick_tree<int> F(q + 1);
  F.add(0, n);
  rep (_, q) {
    int t = input();
    int x = input();
    if (t == 1) {
      x--;
      F.add(a[x], -1);
      a[x]++;
      F.add(a[x], 1);
    }
    else {
      int mn = F.lower_bound(1);
      output(F.sum(min(x + mn, q), q));
    }
  }
  return 0;
}
