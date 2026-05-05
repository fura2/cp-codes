#include "template/template.hpp"

int main() {
  string s = input();
  int n = s.size();

  int ans = 0;
  int pre = -1, num = -2, len = 0;
  rep (i, n) {
    if (i == n - 1 || s[i + 1] != s[i]) {
      if (num + 1 == s[i] - '0') {
        ans += min(i - pre, len);
      }
      num = s[i] - '0';
      len = i - pre;
      pre = i;
    }
  }
  output(ans);

  return 0;
}
