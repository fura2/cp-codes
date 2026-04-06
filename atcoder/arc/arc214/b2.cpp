// 別解 (Binary Trie)

#ifndef TEMPLATE_HPP
#define TEMPLATE_HPP

#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>

#define impl_overload4(a, b, c, d, e, ...) e
#define impl_overload5(a, b, c, d, e, f, ...) f
#define impl_overload6(a, b, c, d, e, f, g, ...) g
#define impl_overload7(a, b, c, d, e, f, g, h, ...) h

// clang-format off
#define impl_rep4(i, a, b, c) for (int i = (a); i < (b); i += (c))
#define impl_rep3(i, a, b) impl_rep4(i, a, b, 1)
#define impl_rep2(i, n) impl_rep3(i, 0, n)
#define impl_rep1(n) for (int _ = 0; _ < (n); ++_)
#define rep(...) impl_overload4(__VA_ARGS__, impl_rep4, impl_rep3, impl_rep2, impl_rep1)(__VA_ARGS__)

#define impl_rrep4(i, a, b, c) for (int i = (b) - 1; i >= (a); i -= (c))
#define impl_rrep3(i, a, b) impl_rrep4(i, a, b, 1)
#define impl_rrep2(i, n) impl_rrep3(i, 0, n)
#define rrep(...) impl_overload4(__VA_ARGS__, impl_rrep4, impl_rrep3, impl_rrep2)(__VA_ARGS__)
// clang-format on

#define all(v) std::begin(v), std::end(v)

template<typename T>
constexpr int bit(T x, unsigned int k) {
    return (x >> k) & 1;
}

template<typename T>
constexpr bool chmax(T& a, const T& b) {
    return a < b ? a = b, true : false;
}
template<typename T>
constexpr bool chmin(T& a, const T& b) {
    return a > b ? a = b, true : false;
}

void yesno(bool b) {
    std::cout << (b ? "Yes" : "No") << "\n";
}
void yes() {
    yesno(true);
}
void no() {
    yesno(false);
}

struct Setup {
    Setup() {
        std::ios::sync_with_stdio(false);
        std::cin.tie(nullptr);
        std::cout << std::fixed << std::setprecision(11);
    }
} setup;

#ifdef LOCAL
#include "template_local.hpp"
#else
#define show(...) ((void)0)
#endif

using uint = unsigned int;
using lint = long long;
using ulint = unsigned long long;

using namespace std;

#endif // TEMPLATE_HPP

template<class T>
struct edge {
    int to;
    T wt;
    edge(int to, const T& wt): to(to), wt(wt) {}
};
template<class T>
using weighted_graph = vector<vector<edge<T>>>;

template<class T>
void add_undirected_edge(weighted_graph<T>& G, int u, int v, const T& wt) {
    G[u].emplace_back(v, wt);
    G[v].emplace_back(u, wt);
}

template<class T>
void add_directed_edge(weighted_graph<T>& G, int u, int v, const T& wt) {
    G[u].emplace_back(v, wt);
}

class BinaryTrie {
    struct Node {
        Node* ch[2] = {nullptr, nullptr};
        int sz = 1;
    };

    Node root;

  public:
    BinaryTrie() = default;

    void add(lint x) {
        Node* p = &this->root;
        rrep (i, 60) {
            p->sz++;
            auto& nxt = p->ch[bit(x, i)];
            if (!nxt) nxt = new Node();
            p = nxt;
        }
    }

    // find max{x xor c | x in S}, where S is the set of added elements
    lint query(lint c) const {
        auto p = &this->root;
        lint x = 0;
        rrep (i, 60) {
            int b = bit(c, i);
            if (p->ch[b ^ 1] && p->ch[b ^ 1]->sz > 0) {
                p = p->ch[b ^ 1];
                x = 2 * x + (b ^ 1);
            }
            else {
                assert(p->ch[b] && p->ch[b]->sz > 0);
                p = p->ch[b];
                x = 2 * x + b;
            }
        }
        return x ^ c;
    }
};

void solve() {
    int n, m;
    cin >> n >> m;
    weighted_graph<int> G(n);
    rep (i, m) {
        int u, v, c;
        cin >> u >> v >> c;
        u--;
        v--;
        add_undirected_edge(G, u, v, c);
    }

    vector<int> d(n, -1);
    d[0] = 0;
    queue<int> Q;
    Q.emplace(0);
    while (!Q.empty()) {
        int u = Q.front();
        Q.pop();
        for (auto e: G[u]) {
            int v = e.to;
            if (d[v] != -1) continue;
            d[v] = d[u] ^ e.wt;
            Q.emplace(v);
        }
    }

    BinaryTrie B;
    rep (u, n) B.add(d[u]);

    int res = 0;
    rep (i, n + 1) res ^= i;
    rep (u, n) res ^= d[u];

    set<int> ans;
    rep (x, n + 1) {
        if (B.query(x) <= n) {
            if (n % 2 == 0) {
                ans.emplace(res);
            }
            else {
                ans.emplace(res ^ x);
            }
        }
    }
    cout << (ans.size() == 1 ? *ans.begin() : -1) << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}
