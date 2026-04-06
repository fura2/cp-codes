#include "template.hpp"

using Real = lint;

int sgn(const Real& x) { return x > 0 ? 1 : x < 0 ? -1 : 0; }

class point {
public:
    Real x, y;
    point() {}
    point(const Real& x, const Real& y):x(x), y(y) {}
    point& operator+=(const point& p) { x += p.x; y += p.y; return *this; }
    point& operator-=(const point& p) { x -= p.x; y -= p.y; return *this; }
    point& operator*=(const Real& c) { x *= c; y *= c; return *this; }
    point& operator/=(const Real& c) { x /= c; y /= c; return *this; }
    point operator+(const point& p)const { return point(*this) += p; }
    point operator-(const point& p)const { return point(*this) -= p; }
    point operator*(const Real& c)const { return point(*this) *= c; }
    point operator/(const Real& c)const { return point(*this) /= c; }
    point operator-()const { return point(-x, -y); }
    bool operator==(const point& p)const { return sgn(x - p.x) == 0 && sgn(y - p.y) == 0; }
    bool operator!=(const point& p)const { return !((*this) == p); }

    friend point operator*(const Real& c, const point& p) { return p * c; }
};

Real cross(const point& p, const point& q) { return p.x * q.y - p.y * q.x; }

enum { CCW = 1, CW = -1, ON = 0 };
int ccw(const point& a, const point& b, const point& c) {
    int d = sgn(cross(b - a, c - a));
    return d > 0 ? CCW : d < 0 ? CW : ON;
}

bool is_on_boundary(const point& q, const vector<point>& P) {
    assert(P.size() >= 2);
    if (q.x < P[0].x || P.back().x <= q.x) return false;
    if (P[0].x == P[1].x && P[0].x == q.x) {
        return P[0].y >= q.y && q.y >= P[1].y;
    }

    int i = upper_bound(all(P), q, [&](const auto& p1, const auto& p2) { return p1.x < p2.x; }) - P.begin();
    return ccw(P[i - 1], P[i], q) == ON;
}

bool is_in_epigraph(const point& q, const vector<point>& P) {
    assert(P.size() >= 2);
    if (q.x <= P[0].x || P.back().x <= q.x) return false;

    int i = upper_bound(all(P), q, [&](const auto& p1, const auto& p2) { return p1.x < p2.x; }) - P.begin();
    return ccw(P[i - 1], P[i], q) == CCW;
}

int main() {
    int n; cin >> n;
    vector<point> P(n);
    rep(i, n) cin >> P[i].x >> P[i].y;

    vector<point> upper, lower; // 上凸包, 下凸包
    {
        int l = 0, r = 0;
        rep(i, 1, n) {
            if (P[r].x < P[i].x || (P[r].x == P[i].x && P[r].y > P[i].y)) {
                r = i;
            }
            if (P[l].x > P[i].x || (P[l].x == P[i].x && P[l].y < P[i].y)) {
                l = i;
            }
        }
        rep(i, n) {
            int j = (r + i) % n;
            upper.emplace_back(P[j]);
            if (j == l) break;
        }
        rep(i, n) {
            int j = (l + i) % n;
            lower.emplace_back(P[j]);
            if (j == r) break;
        }
    }
    for (auto& p : upper) p *= -1;

    int nq; cin >> nq;
    rep(nq) {
        point q; cin >> q.x >> q.y;
        if (is_on_boundary(q, lower) || is_on_boundary(-q, upper)) {
            cout << "ON\n";
        }
        else if (is_in_epigraph(q, lower) && is_in_epigraph(-q, upper)) {
            cout << "IN\n";
        }
        else {
            cout << "OUT\n";
        }
    }

    return 0;
}
