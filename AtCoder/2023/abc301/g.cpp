#pragma GCC optimize(2)

#include <bits/stdc++.h>

#define fi first
#define se second
#define mkp(x, y) make_pair((x), (y))
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

template<class T>
struct Frac {
    T num;
    T den;
    Frac(T num_, T den_) : num(num_), den(den_) {
        if (den < 0) {
            den = -den;
            num = -num;
        }
    }
    Frac() : Frac(0, 1) {}
    Frac(T num_) : Frac(num_, 1) {}
    void reduce() {
        T g = __gcd(num, den);
        num /= g;
        den /= g;
        if(den < 0) {
            num = -num;
            den = -den;
        }
    }
    explicit operator double() const {
        return 1. * num / den;
    }
    Frac &operator += (const Frac &rhs) {
        num = num * rhs.den + rhs.num * den;
        den *= rhs.den;
        return *this;
    }
    Frac &operator -= (const Frac &rhs) {
        num = num * rhs.den - rhs.num * den;
        den *= rhs.den;
        return *this;
    }
    Frac &operator *= (const Frac &rhs) {
        num *= rhs.num;
        den *= rhs.den;
        return *this;
    }
    Frac &operator /= (const Frac &rhs) {
        num *= rhs.den;
        den *= rhs.num;
        if(den < 0) {
            num = -num;
            den = -den;
        }
        return *this;
    }
    friend Frac operator + (Frac lhs, const Frac &rhs) {
        return lhs += rhs;
    }
    friend Frac operator - (Frac lhs, const Frac &rhs) {
        return lhs -= rhs;
    }
    friend Frac operator * (Frac lhs, const Frac &rhs) {
        return lhs *= rhs;
    }
    friend Frac operator / (Frac lhs, const Frac &rhs) {
        return lhs /= rhs;
    }
    friend Frac operator - (const Frac &a) {
        return Frac(-a.num, a.den);
    }
    friend bool operator == (const Frac &lhs, const Frac &rhs) {
        return lhs.num * rhs.den == rhs.num * lhs.den;
    }
    friend bool operator != (const Frac &lhs, const Frac &rhs) {
        return lhs.num * rhs.den != rhs.num * lhs.den;
    }
    friend bool operator < (const Frac &lhs, const Frac &rhs) {
        return lhs.num * rhs.den < rhs.num * lhs.den;
    }
    friend bool operator > (const Frac &lhs, const Frac &rhs) {
        return lhs.num * rhs.den > rhs.num * lhs.den;
    }
    friend bool operator <= (const Frac &lhs, const Frac &rhs) {
        return lhs.num * rhs.den <= rhs.num * lhs.den;
    }
    friend bool operator >= (const Frac &lhs, const Frac &rhs) {
        return lhs.num * rhs.den >= rhs.num * lhs.den;
    }
    friend std::ostream &operator << (std::ostream &os, Frac x) {
        T g = __gcd(x.num, x.den);
        if(x.den == g) {
            return os << x.num / g;
        }
        else {
            return os << x.num / g << "/" << x.den / g;
        }
    }
};
 
using F = Frac<__int128>;

void solve() {
    int n;
    cin >> n;
    vector<array<int, 3>> p(n);
    for(auto &[x, y, z] : p) {
        cin >> x >> y >> z;
    }
    map<array<F, 4>, LL> line;
    // same line
    for(int i = 0; i < n; i ++) {
        auto [x1, y1, z1] = p[i];
        for(int j = 0; j < n; j ++) {
            auto [x2, y2, z2] = p[j];
            if(x1 < x2) {
                F ky(y2 - y1, x2 - x1);
                F kz(z2 - z1, x2 - x1);
                F by = y1 - ky * x1;
                F bz = z1 - kz * x1;
                // map判是否相等来加，因为我们判等是分式的值的判等，所以插入是一样的！
                // ky.reduce(), kz.reduce(), by.reduce(), bz.reduce();
                line[{ky, kz, by, bz}] |= 1LL << j;
            }
        }
    }
    int ans = 0;
    for(auto [_, v] : line) {
        ans = max(ans, __builtin_popcountll(v));
    }
    // cross point
    map<array<F, 3>, LL> point;
    for(auto [a, va] : line) {
        auto [ky1, kz1, by1, bz1] = a;
        for(auto [b, vb] : line) {
            if(a == b) break; // i, [0, i)
            auto [ky2, kz2, by2, bz2] = b;
            F x = 0;
            if(ky1 != ky2) {
                x = (by1 - by2) / (ky2 - ky1);
            }
            else if(kz1 != kz2) {
                x = (bz1 - bz2) / (kz2 - kz1);
            }
            if(x < 0 && ky1 * x + by1 == ky2 * x + by2 && kz1 * x + bz1 == kz2 * x + bz2) {
                point[{x, ky1 * x + by1, kz1 * x + bz1}] |= va | vb;
            }
        }
    }
    for(auto [_, v] : point) {
        ans = max(ans, __builtin_popcountll(v));
    }
    ans = n - ans;
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed;  // << setprecision(20); // double
    // freopen("i.txt", "r", stdin);
    // freopen("o.txt", "w", stdout);
    // time_t t1 = clock();
    int Tcase = 1;
    // cin >> Tcase; // scanf("%d", &Tcase);
    while (Tcase--) 
        solve();
    // cout << "time: " << 1000.0 * ((clock() - t1) / CLOCKS_PER_SEC) << "ms\n";
    return 0;
}