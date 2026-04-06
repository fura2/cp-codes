#include "template.hpp"

template <class R>
class matrix {
    vector<vector<R>> a;

  public:
    matrix(int n) : a(n, vector<R>(n)) {}
    matrix(int m, int n) : a(m, vector<R>(n)) {}

    matrix &operator+=(const matrix &A) {
        assert(h() == A.h() && w() == A.w());
        int m = h(), n = w();
        rep(i, m) rep(j, n)(*this)[i][j] += A[i][j];
        return *this;
    }
    matrix &operator-=(const matrix &A) {
        assert(h() == A.h() && w() == A.w());
        int m = h(), n = w();
        rep(i, m) rep(j, n)(*this)[i][j] -= A[i][j];
        return *this;
    }
    matrix &operator*=(const matrix &A) {
        assert(w() == A.h());
        int m = h(), n = w(), l = A.w();
        matrix B(m, l);
        rep(i, m) rep(j, l) rep(k, n) B[i][j] += (*this)[i][k] * A[k][j];
        swap(*this, B);
        return *this;
    }
    matrix operator+(const matrix &A) const { return matrix(*this) += A; }
    matrix operator-(const matrix &A) const { return matrix(*this) -= A; }
    matrix operator*(const matrix &A) const { return matrix(*this) *= A; }
    const vector<R> &operator[](int i) const { return a[i]; }
    vector<R> &operator[](int i) { return a[i]; }

    vector<R> operator*(const vector<R> &v) const {
        assert(w() == int(v.size()));
        int m = h(), n = w();
        vector<R> res(m);
        rep(i, m) rep(j, n) res[i] += (*this)[i][j] * v[j];
        return res;
    }

    int h() const { return a.size(); }
    int w() const { return a.empty() ? 0 : a[0].size(); }

    static matrix identity(int n) {
        matrix I(n);
        rep(i, n) I[i][i] = R{1};
        return I;
    }
};

vector<double> &operator+=(vector<double> &x, const vector<double> &y) {
    int n = x.size();
    rep(i, n) x[i] += y[i];
    return x;
}
vector<double> &operator-=(vector<double> &x, const vector<double> &y) {
    int n = x.size();
    rep(i, n) x[i] -= y[i];
    return x;
}
vector<double> operator+(const vector<double> &x, const vector<double> &y) {
    auto res = x;
    res += y;
    return res;
}
vector<double> operator-(const vector<double> &x, const vector<double> &y) {
    auto res = x;
    res -= y;
    return res;
}
vector<double> operator*(const double &c, const vector<double> &x) {
    int n = x.size();
    auto res = x;
    rep(i, n) res[i] *= c;
    return res;
}

vector<int> KuhnMunkres(vector<vector<double>> A) {
    const double EPS = 1e-8;
    const double COST_INF = 1e15;

    int n = A.size();
    vector match(2, vector<int>(n, -1));
    vector lbl(2, vector(n, 0.0));

    auto slack = [&](int u, int v) -> double { return lbl[0][u] + lbl[1][v] + A[u][v]; };

    vector<bool> S(n), T(n);
    vector<int> pre(n), u_min(n);
    rep(root, n) {
        rep(u, n) S[u] = false;
        rep(v, n) T[v] = false, pre[v] = -1, u_min[v] = root;
        S[root] = true;

        while (1) {
            double d = COST_INF;
            rep(v, n) if (!T[v]) d = min(d, slack(u_min[v], v));
            rep(u, n) if (S[u]) lbl[0][u] -= d;
            rep(v, n) if (T[v]) lbl[1][v] += d;

            int x, y;
            rep(v, n) if (!T[v] && abs(slack(u_min[v], v)) < EPS) {
                y = v;
                break;
            }
            x = match[1][y];
            pre[y] = u_min[y];

            if (x == -1) {
                while (y != -1) {
                    int w = pre[y];
                    int z = match[0][w];
                    match[1][y] = w;
                    match[0][w] = y;
                    y = z;
                }
                break;
            }

            S[x] = T[y] = true;
            rep(v, n) if (slack(x, v) < slack(u_min[v], v)) u_min[v] = x;
        }
    }

    return match[0];
}

struct Point {
    int x, y;

    Point() = default;
    Point(int x, int y) : x(x), y(y) {}
};

ostream &operator<<(std::ostream &os, const Point &p) {
    os << "(" << p.x << ", " << p.y << ")";
    return os;
}

const int dx[] = {0, -1, 0, 1}, dy[] = {1, 0, -1, 0};

const int H_MAX = 1000; // upper bound of temperature
const int MEASURE_COUNT_MAX = 10000;
const int SIGMA_THRESHOLD1 = 6 * 6;
const int SIGMA_THRESHOLD2 = SIGMA_THRESHOLD1;
// const int SIGMA_THRESHOLD3 = 20 * 20;
const int SIGMA_THRESHOLD3 = SIGMA_THRESHOLD1;

mt19937 rng(0);

int n, m, sigma;
vector<Point> P;        // exit cells
vector<vector<bool>> B; // the field of size n x n. true: exit cell, false: empty cell

int ask(int i, int x, int y) {
    cout << i << " " << x << " " << y << endl;
    int res;
    cin >> res;
    return res;
}

vector<Point> compute_measurement_points() {
    vector<Point> Deltas;

    Deltas.emplace_back(0, 0);

    // strategy for small σ
    if (sigma <= SIGMA_THRESHOLD1) {
    }
    // strategy for medium σ
    else if (sigma <= SIGMA_THRESHOLD2) {
        auto B = ::B;
        int cnt_max = -1, r_max = 0, c_max = 0;
        rep(d, 1, 7) {
            rep(r, -d, d + 1) rep(c, -d, d + 1) if (abs(r) + abs(c) == d) {
                rep(x, n) rep(y, n) B[x][y] = ::B[x][y];
                rep(j, m) {
                    B[(P[j].x + r + n) % n][(P[j].y + c + n) % n] = true;
                }
                int cnt = 0;
                rep(x, n) rep(y, n) if (B[x][y]) cnt++;
                if (chmax(cnt_max, cnt)) {
                    r_max = r;
                    c_max = c;
                }
            }
        }
        assert(!(r_max == 0 && c_max == 0));
        Deltas.emplace_back(r_max, c_max);
    }
    // strategy for large σ
    else if (sigma <= SIGMA_THRESHOLD3) {
        auto B = ::B;
        int cnt_max = -1, r_max = 0, c_max = 0;
        rep(d, 1, 7) {
            rep(r, -d, d + 1) rep(c, -d, d + 1) if (abs(r) + abs(c) == d) {
                rep(x, n) rep(y, n) B[x][y] = ::B[x][y];
                rep(j, m) {
                    B[(P[j].x + r + n) % n][(P[j].y + c + n) % n] = true;
                    B[(P[j].x - r + n) % n][(P[j].y - c + n) % n] = true;
                }
                int cnt = 0;
                rep(x, n) rep(y, n) if (B[x][y]) cnt++;
                if (chmax(cnt_max, cnt)) {
                    r_max = r;
                    c_max = c;
                }
            }
        }
        assert(!(r_max == 0 && c_max == 0));
        Deltas.emplace_back(r_max, c_max);
        Deltas.emplace_back(-r_max, -c_max);
    }
    // strategy for very large σ
    else {
        auto B = ::B;
        int cnt_max = -1, r_max = 0, c_max = 0;
        rep(d, 1, 7) {
            rep(r, -d, d + 1) rep(c, -d, d + 1) if (abs(r) + abs(c) == d) {
                rep(x, n) rep(y, n) B[x][y] = ::B[x][y];
                rep(j, m) {
                    B[(P[j].x + r + n) % n][(P[j].y + c + n) % n] = true;
                    B[(P[j].x - c + n) % n][(P[j].y + r + n) % n] = true;
                    B[(P[j].x - r + n) % n][(P[j].y - c + n) % n] = true;
                    B[(P[j].x + c + n) % n][(P[j].y - r + n) % n] = true;
                }
                int cnt = 0;
                rep(x, n) rep(y, n) if (B[x][y]) cnt++;
                if (chmax(cnt_max, cnt)) {
                    r_max = r;
                    c_max = c;
                }
            }
        }
        assert(!(r_max == 0 && c_max == 0));
        Deltas.emplace_back(r_max, c_max);
        Deltas.emplace_back(-c_max, r_max);
        Deltas.emplace_back(-r_max, -c_max);
        Deltas.emplace_back(c_max, -r_max);
    }
    return Deltas;
}

void solve_laplace(vector<vector<int>> &H) {
    assert(int(H.size()) == n && int(H[0].size()) == n);

    int N = 0;
    vector<vector<int>> Idx(n, vector(n, -1)); // coordinate -> undetermined cell index
    rep(i, n) rep(j, n) if (H[i][j] == -1) {
        Idx[i][j] = N;
        N++;
    }

    matrix<double> L(N, N); // Laplacian matrix
    vector<double> b(N);
    rep(i, n) rep(j, n) if (H[i][j] == -1) {
        L[Idx[i][j]][Idx[i][j]] = -4;
        rep(k, 4) {
            int i2 = (i + dx[k] + n) % n;
            int j2 = (j + dy[k] + n) % n;
            if (H[i2][j2] == -1) {
                L[Idx[i][j]][Idx[i2][j2]] = 1;
            } else {
                b[Idx[i][j]] += H[i2][j2];
            }
        }
    }

    int n_iter = 200;
    double dt = 0.2;
    vector<double> x(N), x_pre(N);
    rep(t, n_iter) {
        // copy(all(x), x_pre.begin());
        x += dt * (L * x + b);
        // double diff = 0, cost = 0;
        // rep(i, m) {
        //     diff += (x[i] - x_pre[i]) * (x[i] - x_pre[i]);
        // }
        // rep(i, n) rep(j, n) {
        //     double val = (H[i][j] == -1 ? x[g[i][j]] : 1.0 * H[i][j]);
        //     rep(k, 2) {
        //         int i2 = (i + dx[k] + n) % n, j2 = (j + dy[k] + n) % n;
        //         double val2 = (H[i2][j2] == -1 ? x[g[i2][j2]] : 1.0 * H[i2][j2]);
        //         cost += (val - val2) * (val - val2);
        //     }
        // }
        // if (t == n_iter - 1 || t % 10 == 0) {
        //     show(t, diff, cost);
        // }
    }
    rep(i, n) rep(j, n) if (H[i][j] == -1) H[i][j] = round(x[Idx[i][j]]);
}

vector<vector<int>> compute_temperatures(const vector<Point> &Deltas) {
    int n_meas = Deltas.size();
    vector<vector<int>> H_values(m, vector<int>(n_meas));

    // strategy for small σ
    if (sigma <= SIGMA_THRESHOLD1) {
        assert(n_meas == 1);
        int h_min = 10;
        int c = 10;
        if (sigma <= 1 * 1) {
            c = 3;
        } else if (sigma <= 2 * 2) {
            c = 5;
        } else if (sigma <= 3 * 3) {
            c = 9;
        }
        rep(j, m) H_values[j][0] = min(h_min + c * (j + 1), H_MAX);
    }
    // strategy for medium σ
    else if (sigma <= SIGMA_THRESHOLD2) {
        assert(n_meas == 2);
        int h_min = 10, h_max = H_MAX - 10;
        int m2 = sqrt(m);
        while (m2 * m2 < m) {
            m2++;
        }
        rep(i, m2) rep(j, m2) {
            int idx = i * m2 + j;
            if (idx < m) {
                H_values[idx][0] = h_min + round(i * (h_max - h_min) / sqrt(m));
                H_values[idx][1] = h_min + round(j * (h_max - h_min) / sqrt(m));
            }
        }
    }
    // strategy for large σ
    else if (sigma <= SIGMA_THRESHOLD3) {
        assert(n_meas == 3);
        int h_min = 10, h_max = H_MAX - 10;
        int m3 = cbrt(m);
        while (m3 * m3 * m3 < m) {
            m3++;
        }
        rep(i, m3) rep(j, m3) rep(k, m3) {
            int idx = i * m3 * m3 + j * m3 + k;
            if (idx < m) {
                H_values[idx][0] = h_min + round(i * (h_max - h_min) / cbrt(m));
                H_values[idx][1] = h_min + round(j * (h_max - h_min) / cbrt(m));
                H_values[idx][2] = h_min + round(k * (h_max - h_min) / cbrt(m));
            }
        }
    }
    // strategy for very large σ
    else {
        assert(n_meas == 5);
        int h_min = 10, h_max = H_MAX - 10;
        int m5 = pow(m, 1.0 / 5);
        while (m5 * m5 * m5 * m5 * m5 < m) {
            m5++;
        }
        rep(i, m5) rep(j, m5) rep(k, m5) rep(u, m5) rep(v, m5) {
            int idx = i * m5 * m5 * m5 * m5 + j * m5 * m5 * m5 + k * m5 * m5 + u * m5 + v;
            if (idx < m) {
                H_values[idx][0] = h_min + round(i * (h_max - h_min) / pow(m, 1.0 / 5));
                H_values[idx][1] = h_min + round(j * (h_max - h_min) / pow(m, 1.0 / 5));
                H_values[idx][2] = h_min + round(k * (h_max - h_min) / pow(m, 1.0 / 5));
                H_values[idx][3] = h_min + round(u * (h_max - h_min) / pow(m, 1.0 / 5));
                H_values[idx][4] = h_min + round(v * (h_max - h_min) / pow(m, 1.0 / 5));
            }
        }
    }

    vector H(n, vector(n, 0));
    vector cnt(n, vector(n, 0));
    rep(k, n_meas) {
        rep(j, m) {
            int x = (P[j].x + Deltas[k].x + n) % n;
            int y = (P[j].y + Deltas[k].y + n) % n;
            H[x][y] += H_values[j][k];
            cnt[x][y]++;
        }
    }
    rep(x, n) rep(y, n) {
        if (cnt[x][y] > 0)
            H[x][y] = round(1.0 * H[x][y] / cnt[x][y]);
        else
            H[x][y] = -1;
    }

    // 上で色々やったけど結局ランダムに温度を決めるほうがマシだった
    if (n_meas >= 2) {
        int h_min = 10, h_max = H_MAX - 10;
        lint d_max = -1e15;
        auto H_max = H;
        rep(10000) {
            rep(x, n) rep(y, n) if (H[x][y] != -1) H[x][y] = h_min + rng() % (h_max - h_min + 1);
            lint d = 1e15;
            rep(j1, m) rep(j2, j1 + 1, m) {
                lint sum = 0;
                rep(k, n_meas) {
                    int x1 = (P[j1].x + Deltas[k].x + n) % n;
                    int y1 = (P[j1].y + Deltas[k].y + n) % n;
                    int x2 = (P[j2].x + Deltas[k].x + n) % n;
                    int y2 = (P[j2].y + Deltas[k].y + n) % n;
                    sum += abs(H[x1][y1] - H[x2][y2]);
                }
                chmin(d, sum);
            }
            if (chmax(d_max, d)) {
                H_max = H;
            }
        }
        H = H_max;
    }

    solve_laplace(H);

    return H;
}

vector<int> measure(const vector<Point> &Deltas, const vector<vector<int>> &H) {
    // CDF of the normal distribution with mean mu and variance sigma^2
    auto f = [](const double &x, const double &mu, const double &sigma) -> double {
        return 0.5 * (1 + erf((x - mu) / (sqrt(2) * sigma)));
    };

    // Dists[h] = probability distribution of measured value of the cell with temperature h
    vector Dists(H_MAX + 1, vector(H_MAX + 1, 0.0));
    rep(h, H_MAX + 1) {
        Dists[h][0] = f(0.5, h, sigma);
        rep(v, 1, H_MAX) {
            Dists[h][v] = f(v + 0.5, h, sigma) - f(v - 0.5, h, sigma);
        }
        Dists[h][H_MAX] = 1 - f(H_MAX - 0.5, h, sigma);
    }

    int n_meas = Deltas.size();
    int n_iter = 100 / n_meas;
    if (sigma <= SIGMA_THRESHOLD1) {
        if (sigma <= 1 * 1) {
            chmin(n_iter, 4);
        } else if (sigma <= 2 * 2) {
            chmin(n_iter, 20);
        } else if (sigma <= 3 * 3) {
            chmin(n_iter, 40);
        } else if (sigma <= 4 * 4) {
            chmin(n_iter, 60);
        }
    }

    // measured values
    vector Meas(m, vector(n_meas, vector<int>(n_iter)));
    rep(i, m) rep(k, n_meas) {
        rep(l, n_iter) {
            int res = ask(i, Deltas[k].x, Deltas[k].y);
            Meas[i][k][l] = res;
        }
    }

    // i: ワームホールの番号 (0, 1, ..., m-1)
    // j: 出口セルの番号 (0, 1, ..., m-1)
    // k: 各ワームホールに対する計測地点の番号 (0, 1, ..., n_meas-1)
    // l: 各 i, k に対して, 何回目の計測かを表す番号 (0, 1, ..., n_iter-1)
    // X_{i,k,l}: ワームホール i に対する地点 k の l 回目の計測結果を表す確率変数
    // x_{i,k,l}: 実際に得られた計測結果
    // X_i = (X_{i,k,l})_{k,l}
    // x_i = (x_{i,k,l})_{k,l}
    // Y: {0, 1, ..., m-1} 上の一様分布にしたがう確率変数
    // - 各ワームホール i がどの出口セルに対応するかを表す
    // - P(Y = j) = 1 / m
    // Pr[i][j] = P(Y=j | X_i=x_i)
    //          = 計測結果 x_i が得られたときの, ワームホール i が出口セル j につながっている条件付き確率
    // Bayesの定理より
    //  P(Y=j | X_i=x_i) = P(X_i=x_i | Y=j) * P(Y=j) / P(X_i=x_i)
    //                   = P(X_i=x_i | Y=j) * P(Y=j) / Σ_{j'} P(X_i=x_i | Y=j')
    vector Pr(m, vector<double>(m));
    rep(i, m) {
        vector<double> Q(m); // Q[j] = P(X_i=x_i | Y=j)
        rep(j, m) {
            Q[j] = 1;
            rep(k, n_meas) {
                int x = (P[j].x + Deltas[k].x + n) % n;
                int y = (P[j].y + Deltas[k].y + n) % n;
                rep(l, n_iter) {
                    Q[j] *= Dists[H[x][y]][Meas[i][k][l]];
                }
            }
            Pr[i][j] = Q[j] * (1.0 / m);
        }
        sort(all(Q));
        double q_sum = accumulate(all(Q), 0.0);
        rep(j, m) {
            Pr[i][j] /= q_sum;
        }
    }

    vector C(m, vector<double>(m));
    rep(i, m) rep(j, m) C[i][j] = -log(Pr[i][j]);
    vector<int> match = KuhnMunkres(C);
    return match;
}

int main() {
    // input
    cin >> n >> m >> sigma;
    P.resize(m);
    B.assign(n, vector<bool>(n, false));
    for (auto &p : P) {
        cin >> p.x >> p.y;
        B[p.x][p.y] = true;
    }
    show(n, m, sigma);

    vector<Point> Deltas = compute_measurement_points();
    show(Deltas);

    vector<vector<int>> H = compute_temperatures(Deltas);

    // set temperature
    rep(x, n) rep(y, n) {
        cout << H[x][y] << " \n"[y < n - 1 ? 0 : 1];
    }
    cout << flush;

    vector<int> ans = measure(Deltas, H);

    // answer
    cout << "-1 -1 -1\n";
    rep(i, m) cout << ans[i] << "\n";
    cout << flush;

    return 0;
}
