#include <bits/stdc++.h>

using namespace std;

template<class T>
vector<T> longest_increasing_subsequence(const vector<T>& a) {
    vector<T> lis;
    for (const auto& x: a) {
        auto it = lower_bound(lis.begin(), lis.end(), x);
        if (it != lis.end())
            *it = x;
        else
            lis.emplace_back(x);
    }
    return lis;
}

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].first >> a[i].second;
    }

    sort(a.begin(), a.end(), [](const auto& p, const auto& q) {
        if (p.first != q.first) return p.first < q.first;
        return p.second > q.second;
    });

    vector<int> b(n);
    for (int i = 0; i < n; i++) {
        b[i] = a[i].second;
    }
    cout << longest_increasing_subsequence(b).size() << endl;

    return 0;
}
