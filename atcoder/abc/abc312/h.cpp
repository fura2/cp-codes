#include "template.hpp"

class rolling_hash {
    static const long long base = 10007, mod1 = 1e9 + 7, mod2 = 1e9 + 9;
    inline static vector<long long> pow1 = { 1 }, pow2 = { 1 };
    int len;
    vector<long long> h1, h2;

    static void allocate(int len) {
        if (ssize(pow1) <= len) {
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
    rolling_hash() {}
    rolling_hash(const string& s):len(s.length()), h1(len + 1), h2(len + 1) {
        rep(i, len) {
            h1[i + 1] = (h1[i] * base + s[i]) % mod1;
            h2[i + 1] = (h2[i] * base + s[i]) % mod2;
        }
    }
    template<class T>
    rolling_hash(const vector<T>& a):len(a.size()), h1(len + 1), h2(len + 1) {
        rep(i, len) {
            h1[i + 1] = (h1[i] * base + a[i]) % mod1; if (h1[i + 1] < 0) h1[i + 1] += mod1;
            h2[i + 1] = (h2[i] * base + a[i]) % mod2; if (h2[i + 1] < 0) h2[i + 1] += mod2;
        }
    }
    hash_type get_hash(int l, int r)const {
        assert(0 <= l && l <= r && r <= len);
        allocate(r - l);
        auto res1 = (h1[r] - h1[l] * pow1[r - l]) % mod1; if (res1 < 0) res1 += mod1;
        auto res2 = (h2[r] - h2[l] * pow2[r - l]) % mod2; if (res2 < 0) res2 += mod2;
        return { res1, res2, r - l };
    }
    static hash_type get_hash(const string& s) {
        long long res1 = 0, res2 = 0;
        rep(i, ssize(s)) {
            res1 = (res1 * base + s[i]) % mod1;
            res2 = (res2 * base + s[i]) % mod2;
        }
        return { res1, res2, s.length() };
    }
    template<class T>
    static hash_type get_hash(const vector<T>& a) {
        long long res1 = 0, res2 = 0;
        rep(i, a.size()) {
            res1 = (res1 * base + a[i]) % mod1;
            res2 = (res2 * base + a[i]) % mod2;
        }
        return { res1, res2, a.size() };
    }
    friend hash_type operator*(const hash_type&, const hash_type&);
};

rolling_hash::hash_type operator*(const rolling_hash::hash_type& H1, const rolling_hash::hash_type& H2) {
    long long h11, h12, h21, h22;
    int len1, len2;
    tie(h11, h12, len1) = H1;
    tie(h21, h22, len2) = H2;

    rolling_hash::allocate(len2);
    long long res1 = (h11 * rolling_hash::pow1[len2] + h21) % rolling_hash::mod1;
    long long res2 = (h12 * rolling_hash::pow2[len2] + h22) % rolling_hash::mod2;
    return { res1, res2, len1 + len2 };
}

int period(const string& s) {
    int n = s.size();
    rep(d, 1, n) if (n % d == 0) {
        bool ok = true;
        rep(i, d, n) if (s[i] != s[i % d]) {
            ok = false;
            break;
        }
        if (ok) return d;
    }
    return n;
}

int main() {
    int n; cin >> n;
    vector<string> S(n);
    rep(i, n) cin >> S[i];

    // 長さ a の文字列 s と長さ b の文字列 t に対して, s * b == t * a となっていたなら,
    // s, t は共通の周期 g = gcd(a, b) を持ち, s[0:g] == t[0:g] が成り立つ.
    // 各 S_i の最小周期 P_i を求めて, S_i を P_i の何回かの繰り返しと見ると,
    // S_i[0:P_i] が等しいグループの中でのみ干渉が起きうる.
    vector<int> P(n);
    rep(i, n) P[i] = period(S[i]);

    map<rolling_hash::hash_type, vector<pair<int, int>>> group;
    rep(i, n) {
        auto r = rolling_hash::get_hash(S[i].substr(0, P[i]));
        group[r].emplace_back(i, S[i].size() / P[i]);
    }

    vector<int> ans(n);
    vector<lint> cnt(200001, 1);
    set<lint> used;
    for (const auto& [key, v] : group) {
        for (auto [i, len] : v) {
            lint x = len * cnt[len];
            while (used.count(x) > 0) { // 調和級数による計算量評価で, ループ回数は全体で O(L log L)
                x += len;
                cnt[len]++;
            }
            used.insert(x);
            ans[i] = cnt[len];
        }

        for (auto [i, len] : v) cnt[len] = 1;
        used.clear();
    }

    rep(i, n) cout << ans[i] << " \n"[i < n - 1 ? 0 : 1];

    return 0;
}
