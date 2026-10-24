#include "template/template.hpp"

// #define MULTI_TESTCASE
#include "string/run_length_encoding.hpp"
#include "template/main.hpp"

/*
0000: assoc = T, comm = T (zero)
0001: assoc = T, comm = T (AND)
0110: assoc = T, comm = T (XOR)
0111: assoc = T, comm = T (OR)
1001: assoc = T, comm = T (XNOR)
1111: assoc = T, comm = T (one)

0011: assoc = T, comm = F (left)
0101: assoc = T, comm = F (right)

1000: assoc = F, comm = T (NOR)
1110: assoc = F, comm = T (NAND)

0010: assoc = F, comm = F (NOT imply)
0100: assoc = F, comm = F
1010: assoc = F, comm = F (NOT right)
1011: assoc = F, comm = F
1100: assoc = F, comm = F (NOT left)
1101: assoc = F, comm = F (imply)
*/

void solve_zero(string s) {
  lint cnt = ranges::count(s, '1');
  output(vector{cnt == 0 ? -1 : 1, cnt});
}

void solve_one(string s) {
  lint n = s.size();
  lint cnt = n * (n + 1) / 2 - ranges::count(s, '0');
  output(vector{cnt == 0 ? -1 : n, cnt});
}

void solve_and(string s) {
  lint mx = 0, cnt = 0;
  for (auto [c, l]: run_length_encoding(s)) {
    if (c == '1') {
      chmax<lint>(mx, l);
      cnt += l * (l + 1LL) / 2;
    }
  }
  output(vector{cnt == 0 ? -1 : mx, cnt});
}

void solve_or(string s) {
  lint n = s.size();
  lint cnt = 0;
  int p = n;
  rep (i, n) {
    if (s[i] == '1') p = i;
    if (p < n) cnt += p + 1;
  }
  output(vector{cnt == 0 ? -1 : n, cnt});
}

void solve_xor(string s) {
  lint n = s.size();
  lint cnt = 0;
  lint h[2] = {1, 0}, x = 0;
  rep (i, n) {
    x ^= s[i] - '0';
    cnt += h[x ^ 1];
    ++h[x];
  }
  if (cnt == 0) {
    output(vector{-1, 0});
    return;
  }

  int mx;
  vector<int> ones;
  rep (i, n)
    if (s[i] == '1') ones.emplace_back(i);
  if (ones.size() % 2 == 1) {
    mx = n;
  }
  else {
    mx = max<int>(n - ones[0] - 1, ones.back());
  }
  output(vector{mx, cnt});
}

void solve_xnor(string s) {
  lint n = s.size();
  lint cnt = 0;
  lint h[2] = {1, 0}, x = 0;
  rep (i, n) {
    x ^= '1' - s[i];
    cnt += h[x];
    ++h[x];
  }
  if (cnt == 0) {
    output(vector{-1, 0});
    return;
  }

  int mx;
  vector<int> zeros;
  rep (i, n)
    if (s[i] == '0') zeros.emplace_back(i);
  if (zeros.size() % 2 == 0) {
    mx = n;
  }
  else {
    mx = max<int>(n - zeros[0] - 1, zeros.back());
  }
  output(vector{mx, cnt});
}

void solve_left(string s) {
  lint n = s.size();
  lint mx = 0, cnt = 0;
  rep (i, n) {
    if (s[i] == '1') {
      chmax(mx, n - i);
      cnt += n - i;
    }
  }
  output(vector{cnt == 0 ? -1 : mx, cnt});
}

void solve_right(string s) {
  ranges::reverse(s);
  solve_left(s);
}

void solve_good(string s, int a, int b, int c, int d) {
  auto op = [&](char x, char y) {
    if (x == '0' && y == '0') return '0' + a;
    if (x == '0' && y == '1') return '0' + b;
    if (x == '1' && y == '0') return '0' + c;
    if (x == '1' && y == '1') return '0' + d;
    assert(false);
  };

  lint n = s.size();
  lint mx = 0, cnt = 0;
  rep (i, n) {
    // length 1
    if (s[i] == '1') {
      chmax(mx, 1LL);
      cnt++;
    }
    // length 2
    if (i < n - 1 && op(s[i], s[i + 1]) == '1') {
      chmax(mx, 2LL);
      cnt++;
    }
    // length 3
    if (i < n - 2 && (op(op(s[i], s[i + 1]), s[i + 2]) == '1' ||
                      op(s[i], op(s[i + 1], s[i + 2])) == '1')) {
      chmax(mx, 3LL);
      cnt++;
    }
    // length >= 4
    if (i < n - 3) {
      chmax(mx, n - i);
      cnt += n - i - 3;
    }
  }
  output(vector{cnt == 0 ? -1 : mx, cnt});
}

void solve_bad(string s, int a, int b, int c, int d) {
  if (a == 0 && b == 0 && c == 1 && d == 0) {
    ranges::reverse(s);
    solve_bad(s, 0, 1, 0, 0);
    return;
  }

  if (a == 1 && b == 1 && c == 0 && d == 1) {
    ranges::reverse(s);
    solve_bad(s, 1, 0, 1, 1);
    return;
  }

  if (a == 0 && b == 1 && c == 0 && d == 0) {
    // OK <=> 末尾が 1 and != 00...011
    lint n = s.size();
    vector<int> dp(n + 1);  // 左に 0 が何個連続するか
    rep (i, n) {
      if (s[i] == '0')
        dp[i + 1] = dp[i] + 1;
      else
        dp[i + 1] = 0;
    }

    lint cnt = 0;
    rep (i, n) {
      if (s[i] == '1') {
        cnt += i + 1;
        if (i < n - 1 && s[i + 1] == '1') {
          cnt -= dp[i] + 1;
        }
      }
    }
    if (cnt == 0) {
      output(vector{-1, 0});
      return;
    }

    int mx;
    rrep (i, n) {
      if (s[i] == '1') {
        mx = i + 1;
        if (i > 0 && s[i - 1] == '1' && dp[i - 1] == i - 1) mx--;
        break;
      }
    }
    output(vector{cnt == 0 ? -1 : mx, cnt});
    return;
  }

  if (a == 1 && b == 0 && c == 1 && d == 1) {
    // OK <=> != 011...1
    lint n = s.size();
    vector<int> dp(n + 1);  // 右に 1 が何個連続するか
    rrep (i, n) {
      if (s[i] == '0')
        dp[i] = 0;
      else
        dp[i] = dp[i + 1] + 1;
    }

    lint cnt = n * (n + 1) / 2;
    rep (i, n) {
      if (s[i] == '0') {
        cnt -= dp[i + 1] + 1;
      }
    }
    if (cnt == 0) {
      output(vector{-1, 0});
      return;
    }

    int mx = n;
    if (s[0] == '0' && dp[1] == n - 1) mx--;
    output(vector{mx, cnt});
    return;
  }

  assert(false);
}

void testcase() {
  // rep (a, 2) {
  //   rep (b, 2) {
  //     rep (c, 2) {
  //       rep (d, 2) {
  //         int op[2][2] = {{a, b}, {c, d}};

  //         bool assoc = true;
  //         bool comm = true;
  //         rep (x, 2) {
  //           rep (y, 2) {
  //             rep (z, 2) {
  //               if (op[op[x][y]][z] != op[x][op[y][z]]) assoc = false;
  //             }
  //             if (op[x][y] != op[y][x]) comm = false;
  //           }
  //         }
  //         show(a, b, c, d, assoc, comm);

  //         if (assoc) continue;

  //         bool good = true;
  //         rep (x, 2) {
  //           rep (y, 2) {
  //             rep (z, 2) {
  //               rep (w, 2) {
  //                 bool ok = false;
  //                 ok |= op[op[op[x][y]][z]][w];
  //                 ok |= op[op[x][y]][op[z][w]];
  //                 ok |= op[op[x][op[y][z]]][w];
  //                 ok |= op[x][op[op[y][z]][w]];
  //                 ok |= op[x][op[y][op[z][w]]];
  //                 good &= ok;
  //               }
  //             }
  //           }
  //         }
  //         show(good);
  //       }
  //     }
  //   }
  // }

  auto n = input<int>();
  auto s = input<string>();
  solve_zero(s);              // 0000
  solve_and(s);               // 0001
  solve_bad(s, 0, 0, 1, 0);   // 0010
  solve_left(s);              // 0011
  solve_bad(s, 0, 1, 0, 0);   // 0100
  solve_right(s);             // 0101
  solve_xor(s);               // 0110
  solve_or(s);                // 0111
  solve_good(s, 1, 0, 0, 0);  // 1000
  solve_xnor(s);              // 1001
  solve_good(s, 1, 0, 1, 0);  // 1010
  solve_bad(s, 1, 0, 1, 1);   // 1011
  solve_good(s, 1, 1, 0, 0);  // 1100
  solve_bad(s, 1, 1, 0, 1);   // 1101
  solve_good(s, 1, 1, 1, 0);  // 1110
  solve_one(s);               // 1111
}
