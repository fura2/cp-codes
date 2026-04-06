#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (n); i++)
#define show(v) { cout << "["; bool _b = true; for (const auto& e : v) { cout << (_b ? "" : ", ") << e; _b = false; } cout << "]" << endl; }

using namespace std;

class Eratosthenes_sieve {
    vector<bool> er;
    vector<int> p;
public:
    Eratosthenes_sieve(int n):er(n + 1, true) {
        if (n >= 0) er[0] = false;
        if (n >= 1) er[1] = false;
        for (int i = 2; i * i <= n; i++) if (er[i]) for (int j = i * i; j <= n; j += i) er[j] = false;
        rep(i, n + 1) if (er[i]) p.emplace_back(i);
    }

    vector<int> primes()const { return p; }

    bool is_prime(int a)const {
        assert(a <= (int)er.size() - 1);
        return a >= 0 && er[a];
    }
};

int64_t n;
vector<int> P;

const int N = 10, M = 1e5;
int64_t memo[N][M];

int64_t dfs(int idx, int64_t x) {
    int64_t dummy = -1;
    int64_t& res = (idx < N && n / x < M ? memo[idx][n / x] : dummy);
    if (res != -1) return res;

    if (idx == 0) {
        return res = 64 - __builtin_clzll(n / x);
    }

    res = 0;
    do {
        res += dfs(idx - 1, x);
        x *= P[idx];
    } while (x <= n);
    return res;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);

    int p; cin >> n >> p;

    Eratosthenes_sieve E(p);
    P = E.primes();

    memset(memo, -1, sizeof(memo));
    cout << dfs(P.size() - 1, 1) << endl;

    return 0;
}
