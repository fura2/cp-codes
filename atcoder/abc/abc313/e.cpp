// 1 でない数字が連続している箇所があるなら, 操作によってその部分は消えないので No.
// 1 でない数字が連続していないなら有限回の操作で一桁になる.

// 操作回数を求める.
// 1 を x 個並べたものを 1_x と書く.
// s = 1_x a 1_y b 1_z c 1_w (a, b, c >= 2) を例にして説明する.
// s に操作を施すと 1_{x+a-1} a 1_{y+b-1} b 1_{z+c-1} c 1_{w-1} となる.
// すなわち, 連続する 1 の塊それぞれについて
// - 末尾のものは 1 が一つ減る.
// - それ以外のものは 1 が ((次に来る 1 でない値) - 1) 個増える.
// 末尾が 1 でないときは
// - 末尾の値が消える.
// - 連続する 1 の塊については同上.
// (非 1 + 連続する 1) を消すまでを一まとまりと考えると, 操作の過程は次のようになる.
//   1_x a 1_y b 1_z c 1_w
//   --(w+1 times)--> 1_{x+(a-1)(w+1)} a 1_{y+(b-1)(w+1)} b 1_{z+(c-1)(w+1)}
//                  = 1_{x+(a-1)(w+1)} a 1_{y+(b-1)(w+1)} b 1_s  (s := z+(c-1)(w+1))
//   --(w+1+s+1 times)--> 1_{x+(a-1)(w+1+s+1)} a 1_{y+(b-1)(w+1+s+1)}
//                      = 1_{x+(a-1)(w+1+s+1)} a 1_t  (t := y+(b-1)(w+1+s+1))
//   --(w+1+s+1+t+1 times)--> 1_{x+(a-1)(w+1+s+1+t+1)}
//                          = 1_u  (u := x+(a-1)(w+1+s+1+t+1))
//   --(w+1+s+1+t+1+u-1 times)--> 1
// s の先頭が非 1 のときも同様にできる.

#include "template.hpp"

class mint {
    static const int MOD = 998244353;
    int x;

  public:
    mint() : x(0) {}
    mint(long long y) {
        x = y % MOD;
        if (x < 0)
            x += MOD;
    }

    mint &operator+=(const mint &m) {
        x += m.x;
        if (x >= MOD)
            x -= MOD;
        return *this;
    }
    mint &operator-=(const mint &m) {
        x -= m.x;
        if (x < 0)
            x += MOD;
        return *this;
    }
    mint &operator*=(const mint &m) {
        x = (long long)x * m.x % MOD;
        return *this;
    }
    mint &operator/=(const mint &m) { return *this *= inverse(m); }
    mint operator+(const mint &m) const { return mint(*this) += m; }
    mint operator-(const mint &m) const { return mint(*this) -= m; }
    mint operator*(const mint &m) const { return mint(*this) *= m; }
    mint operator/(const mint &m) const { return mint(*this) /= m; }
    mint operator-() const { return -x; }

    friend mint inverse(const mint &m) {
        int a = m.x, b = MOD, u = 1, v = 0;
        while (b > 0) {
            int t = a / b;
            a -= t * b;
            swap(a, b);
            u -= t * v;
            swap(u, v);
        }
        return u;
    }

    friend istream &operator>>(istream &is, mint &m) {
        long long t;
        is >> t;
        m = t;
        return is;
    }
    friend ostream &operator<<(ostream &os, const mint &m) { return os << m.x; }
    int to_int() const { return x; }
};

mint operator+(long long x, const mint &m) { return mint(x) + m; }
mint operator-(long long x, const mint &m) { return mint(x) - m; }
mint operator*(long long x, const mint &m) { return mint(x) * m; }
mint operator/(long long x, const mint &m) { return mint(x) / m; }

vector<pair<char, mint>> run_length_encoding(const string &s) {
    vector<pair<char, mint>> res;
    int n = s.length(), pre = 0;
    rep(i, n) if (i == n - 1 || s[i] != s[i + 1])
        res.emplace_back(s[i], i - pre + 1),
        pre = i + 1;
    return res;
}

int main() {
    // // 実験用コード
    // auto f = [](string s) -> string {
    //     string res;
    //     int n = size(s);
    //     rep(i, n - 1) rep(s[i + 1] - '0') res += s[i];
    //     return res;
    // };
    // set<string> OK;
    // rep(i, 20000) {
    //     string s = to_string(i);
    //     if (count(all(s), '0') > 0)
    //         continue;
    //     bool ok = false;
    //     rep(t, 10000) {
    //         if (size(s) == 1 || OK.count(s) > 0) {
    //             ok = true;
    //             break;
    //         }
    //         if (size(s) > 10000)
    //             break;
    //         s = f(s);
    //     }
    //     if (ok)
    //         OK.emplace(to_string(i));
    // }
    // show(OK);

    int n;
    string s;
    cin >> n >> s;
    rep(i, n - 1) if (s[i] != '1' && s[i + 1] != '1') {
        cout << -1 << endl;
        return 0;
    }

    auto rle = run_length_encoding(s);
    if (rle.back().first != '1')
        rle.emplace_back('1', 0);

    mint ans = 0;
    while (rle.size() >= 3) {
        int m = rle.size();
        assert(rle[m - 1].first == '1');
        assert(rle[m - 2].first != '1');
        assert(rle[m - 3].first == '1');
        ans += rle[m - 1].second + 1;
        rle[m - 3].second += (rle[m - 2].first - '0' - 1) * ans;
        rle.pop_back();
        rle.pop_back();
    }
    if (rle.size() == 1) {
        ans += rle[0].second - 1;
    } else {
        ans += rle[1].second;
    }
    cout << ans << endl;

    return 0;
}
