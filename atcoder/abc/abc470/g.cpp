#include "template/template.hpp"

// #define MULTI_TESTCASE
#include "algebra/monoid_impl.hpp"
#include "template/main.hpp"

using LintAddMonoidWithWidth =
    MonoidImpl<pair<lint, lint>,
               [](const auto& a, const auto& b) {
                 return pair{a.first + b.first, a.second + b.second};
               },
               []() { return pair{0LL, 0LL}; }>;

using LintFindLastMonoid =
    MonoidImpl<optional<lint>,
               [](const auto& a, const auto& b) {
                 if (!b.has_value()) return a;
                 return b;
               },
               []() -> optional<lint> { return nullopt; }>;

LintAddMonoidWithWidth action(const LintAddMonoidWithWidth& x,
                              const LintFindLastMonoid& m) {
  if (m.unwrap().has_value()) {
    return pair{x.unwrap().second * m.unwrap().value(), x.unwrap().second};
  }
  return x;
}

template <typename X, typename M, auto f>
class LazySegmentTree {
 public:
  LazySegmentTree(int n): e{X::identity()}, id{M::identity()} {
    this->n = bit_ceil<unsigned int>(n);
    x.assign(2 * this->n, e);
    m.assign(2 * this->n, id);
  }

  LazySegmentTree(int n, const X& v): e{X::identity()}, id{M::identity()} {
    this->n = bit_ceil<unsigned int>(n);
    x.assign(2 * this->n, e);
    m.assign(2 * this->n, id);
    rep (i, v.size()) x[this->n + i] = v;
    for (int i = n - 1; i >= 1; i--) x[i] = x[2 * i] * x[2 * i + 1];
  }

  LazySegmentTree(const vector<X>& v): e{X::identity()}, id{M::identity()} {
    n = bit_ceil(v.size());
    x.assign(2 * n, e);
    m.assign(2 * n, id);
    rep (i, v.size()) x[n + i] = v[i];
    for (int i = n - 1; i >= 1; i--) x[i] = x[2 * i] * x[2 * i + 1];
  }

  void apply(int l, int r, const M& m) {
    apply(1, 0, n, l, r, m);
  }

  X fold(int l, int r) {
    return fold(1, 0, n, l, r);
  }

  X fold() const {
    return x[1];
  }

 private:
  int n;
  vector<X> x;
  vector<M> m;
  const X e;
  const M id;

  // 不変条件: この関数の実行後はつねに m[u] == id
  void apply(int u, int a, int b, int l, int r, const M& m_) {
    propagate(u);
    if (b <= l || r <= a) return;
    if (l <= a && b <= r) {
      m[u] = m_;
      propagate(u);
      return;
    }
    int c = (a + b) / 2;
    apply(2 * u, a, c, l, r, m_);
    apply(2 * u + 1, c, b, l, r, m_);
    x[u] = x[2 * u] * x[2 * u + 1];
  }

  X fold(int u, int a, int b, int l, int r) {
    propagate(u);
    if (b <= l || r <= a) return e;
    if (l <= a && b <= r) return x[u];
    int c = (a + b) / 2;
    return fold(2 * u, a, c, l, r) * fold(2 * u + 1, c, b, l, r);
  }

  void propagate(int u) {
    // if (m[u] == id) return;
    if (m[u].unwrap() == id.unwrap()) return;  // あとで直す
    x[u] = f(x[u], m[u]);
    if (u < n) {
      m[2 * u] = m[2 * u] * m[u];
      m[2 * u + 1] = m[2 * u + 1] * m[u];
    }
    m[u] = id;
  }
};

void testcase() {
  auto n = input<lint>();
  auto a = input<vector<int>>(n);

  vector pos(n + 1, vector<int>());
  rep (i, n) pos[a[i]].emplace_back(i);
  rep (k, n + 1) pos[k].emplace_back(n);  // sentinel

  vector<lint> f(n + 2);
  // // naive
  // vector<int> xs(n);
  // rep (i, n) xs[i] = i;
  // rep (k, n + 1) {
  //   rep (i, n) f[k] += n - xs[i];

  //   int pre = 0;
  //   for (int i: pos[k]) {
  //     rep (j, pre, i) chmax(xs[j], i);
  //     pre = i + 1;
  //   }
  //   show(xs);
  // }
  vector<LintAddMonoidWithWidth> data(n);
  rep (i, n) data[i].unwrap() = {i, 1};
  LazySegmentTree<LintAddMonoidWithWidth, LintFindLastMonoid, action> S(data);
  rep (k, n + 1) {
    f[k] = n * n - S.fold().unwrap().first;

    int pre = 0;
    for (int i: pos[k]) {
      if (S.fold(pre, pre + 1).unwrap().first < i) {
        int lo = pre, hi = i;
        while (hi - lo > 1) {
          int mi = (lo + hi) / 2;
          (S.fold(mi, mi + 1).unwrap().first >= i ? hi : lo) = mi;
        }
        S.apply(pre, hi, {i});
      }
      pre = i + 1;
    }
  }

  lint ans = 0;
  rep (k, n + 1) ans += k * (f[k] - f[k + 1]);
  output(ans);
}
