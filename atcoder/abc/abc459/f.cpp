#include "template/template.hpp"

void solve() {
  int n = input();
  vector<lint> a(n);
  rep (i, n) {
    a[i] = input();
    a[i] += n - i - 1;  // 条件を広義単調増加に言い換え
  }

  vector<pair<lint, int>> S{{a[0], 1}};
  rep (i, 1, n) {
    if (S.back().first <= a[i]) {
      S.emplace_back(a[i], 1);
    }
    else {
      lint total = a[i];
      int num = 1;
      while (S.back().first > total / num) {
        auto [val, cnt] = S.back();
        S.pop_back();
        total += val * cnt;
        num += cnt;
        if (S.empty() || S.back().first <= total / num) {
          if (total % num == 0) {
            S.emplace_back(total / num, num);
          }
          else {
            S.emplace_back(total / num, num - total % num);
            S.emplace_back(total / num + 1, total % num);
          }
          break;
        }
      }
    }
  }

  vector<lint> b;
  for (auto [val, cnt]: S) {
    rep (i, cnt) b.emplace_back(val);
  }
  lint ans = 0;
  rep (i, n - 1) {
    ans += a[i] - b[i];
    a[i + 1] += a[i] - b[i];
    a[i] = b[i];
  }
  output(ans);
}

int main() {
  int t = input();
  rep (_, t) solve();
  return 0;
}
