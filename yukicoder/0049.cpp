#include "template/template.hpp"

// #define MULTI_TESTCASE
#include "template/main.hpp"

vector<int> add(vector<int> a, vector<int> b) {
  int m = a.size(), n = b.size();
  ranges::reverse(a);
  ranges::reverse(b);
  while (m < n) a.emplace_back(0), m++;
  while (n < m) b.emplace_back(0), n++;

  vector<int> c;
  int carry = 0;
  rep (i, n) {
    c.emplace_back((a[i] + b[i] + carry) % 10);
    carry = (a[i] + b[i] + carry) / 10;
  }
  if (carry > 0) c.emplace_back(carry);
  while (c.size() >= 2 && c.back() == 0) c.pop_back();
  ranges::reverse(c);
  return c;
}

vector<int> mul(vector<int> a, int b) {
  int n = a.size();
  ranges::reverse(a);

  vector<int> c;
  int carry = 0;
  rep (i, n) {
    c.emplace_back((a[i] * b + carry) % 10);
    carry = (a[i] * b + carry) / 10;
  }
  if (carry > 0) c.emplace_back(carry);
  while (c.size() >= 2 && c.back() == 0) c.pop_back();
  ranges::reverse(c);
  return c;
}

vector<int> mul(vector<int> a, vector<int> b) {
  vector<int> c;
  rep (i, b.size()) {
    if (!c.empty()) c.emplace_back(0);
    c = add(c, mul(a, b[i]));
  }
  return c;
}

void testcase() {
  auto s = input<string>();
  int n = s.size();

  vector<int> a = {0}, b;
  char op = '*';
  rep (i, n + 1) {
    if (i == n || s[i] == '+' || s[i] == '*') {
      if (op == '+')
        a = mul(a, b);
      else
        a = add(a, b);
      b.clear();
      if (i == n) break;
      op = s[i];
    }
    else {
      b.emplace_back(s[i] - '0');
    }
  }

  string ans;
  for (int d: a) ans += '0' + d;
  output(ans);
}
