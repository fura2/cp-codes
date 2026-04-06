#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (n); i++)
#define all(v) (v).begin(), (v).end()
#define show(x) { std::cout << #x << " = " << x << endl; }

void yes(bool b) {
    std::cout << (b ? "Yes" : "No") << "\n";
}

template<class T, class U>
std::ostream& operator<<(std::ostream& os, const std::pair<T, U>& p) {
    os << "(" << p.first << ", " << p.second << ")";
    return os;
}

template<class T>
std::ostream& operator<<(std::ostream& os, const std::set<T>& s) {
    os << "{";
    bool first = true;
    for (const auto& e : s) {
        if (!first) os << ", ";
        first = false;
        std::cout << e;
    }
    os << "}";
    return os;
}

template<class T>
std::ostream& operator<<(std::ostream& os, const std::unordered_set<T>& s) {
    os << "{";
    bool first = true;
    for (const auto& e : s) {
        if (!first) os << ", ";
        first = false;
        std::cout << e;
    }
    os << "}";
    return os;
}

template<class T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>& v) {
    os << "[";
    bool first = true;
    for (const auto& e : v) {
        if (!first) os << ", ";
        first = false;
        std::cout << e;
    }
    os << "]";
    return os;
}

using namespace std;

int n;
string s, ans;

void dfs(int i, int cnt) {
    if (i == n) {
        return;
    }
    if (s[i] == '(') {
        ans.push_back(s[i]);
        dfs(i + 1, cnt + 1);
    }
    else if (s[i] == ')') {
        if (cnt == 0) {
            ans.push_back(s[i]);
            dfs(i + 1, cnt);
        }
        else {
            while (ans.back() != '(') {
                ans.pop_back();
            }
            ans.pop_back();
            dfs(i + 1, cnt - 1);
        }
    }
    else {
        ans.push_back(s[i]);
        dfs(i + 1, cnt);
    }
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);

    cin >> n >> s;
    dfs(0, 0);
    cout << ans << endl;

    return 0;
}
