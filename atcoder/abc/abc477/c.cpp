#include "template/template.hpp"

// #define MULTI_TESTCASE
#include "algebra/collection/add_group.hpp"
#include "data_structure/fenwick_tree.hpp"
#include "template/main.hpp"

class rolling_hash {
  static const long long base = 10007, mod1 = 1e9 + 7, mod2 = 1e9 + 9;
  inline static vector<long long> pow1 = {1}, pow2 = {1};
  int len;
  vector<long long> h1, h2;

  static void allocate(int len) {
    if (pow1.size() <= len) {
      int k = pow1.size();
      pow1.resize(len + 1);
      pow2.resize(len + 1);
      for (; k <= len; k++) {
        pow1[k] = pow1[k - 1] * base % mod1;
        pow2[k] = pow2[k - 1] * base % mod2;
      }
    }
  }

 public:
  using hash_type = tuple<long long, long long, int>;
  rolling_hash() {
  }
  rolling_hash(const string& s): len(s.length()), h1(len + 1), h2(len + 1) {
    rep (i, len) {
      h1[i + 1] = (h1[i] * base + s[i]) % mod1;
      h2[i + 1] = (h2[i] * base + s[i]) % mod2;
    }
  }
  template <class T>
  rolling_hash(const vector<T>& a): len(a.size()), h1(len + 1), h2(len + 1) {
    rep (i, len) {
      h1[i + 1] = (h1[i] * base + a[i]) % mod1;
      if (h1[i + 1] < 0) h1[i + 1] += mod1;
      h2[i + 1] = (h2[i] * base + a[i]) % mod2;
      if (h2[i + 1] < 0) h2[i + 1] += mod2;
    }
  }
  hash_type get_hash(int l, int r) const {
    assert(0 <= l && l <= r && r <= len);
    allocate(r - l);
    auto res1 = (h1[r] - h1[l] * pow1[r - l]) % mod1;
    if (res1 < 0) res1 += mod1;
    auto res2 = (h2[r] - h2[l] * pow2[r - l]) % mod2;
    if (res2 < 0) res2 += mod2;
    return {res1, res2, r - l};
  }
  static hash_type get_hash(const string& s) {
    long long res1 = 0, res2 = 0;
    rep (i, s.length()) {
      res1 = (res1 * base + s[i]) % mod1;
      res2 = (res2 * base + s[i]) % mod2;
    }
    return {res1, res2, s.length()};
  }
  template <class T>
  static hash_type get_hash(const vector<T>& a) {
    long long res1 = 0, res2 = 0;
    rep (i, a.size()) {
      res1 = (res1 * base + a[i]) % mod1;
      res2 = (res2 * base + a[i]) % mod2;
    }
    return {res1, res2, a.size()};
  }
  friend hash_type operator*(const hash_type&, const hash_type&);
};

rolling_hash::hash_type operator*(const rolling_hash::hash_type& H1,
                                  const rolling_hash::hash_type& H2) {
  long long h11, h12, h21, h22;
  int len1, len2;
  tie(h11, h12, len1) = H1;
  tie(h21, h22, len2) = H2;

  rolling_hash::allocate(len2);
  long long res1 = (h11 * rolling_hash::pow1[len2] + h21) % rolling_hash::mod1;
  long long res2 = (h12 * rolling_hash::pow2[len2] + h22) % rolling_hash::mod2;
  return {res1, res2, len1 + len2};
}

void testcase() {
  auto q = input<int>();
  auto s = input<string>(), t = input<string>();

  rolling_hash Rs(s), Rt(t);
  vector<int> b(s.size());
  rep (i, s.size()) {
    if (s.size() - i >= t.size() &&
        Rs.get_hash(i, i + t.size()) == Rt.get_hash(0, t.size())) {
      b[i] = 1;
    }
  }
  FenwickTree<IntAddGroup> F(b);
  rep (_, q) {
    auto l = input<int>() - 1, r = input<int>();
    yesno(r - l >= t.size() && F.fold(l, r - t.size() + 1).unwrap() > 0);
  }
}
