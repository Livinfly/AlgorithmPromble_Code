// #pragma GCC optimize(2)

#include <bits/stdc++.h>

#define fi first
#define se second
#define mkp(x, y) make_pair((x), (y))
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long LL;
typedef double db;
typedef pair<int, int> PII;

template<class T>
T qpm(T a, LL b) {
    T res = 1;
    for (; b; b /= 2, a *= a) {
        if (b % 2) {
            res *= a;
        }
    }
    return res;
}
LL mul(LL a, LL b, LL p) {
    LL res = a * b - LL(1.L * a * b / p) * p;
    res %= p;
    if (res < 0) {
        res += p;
    }
    return res;
}
template<LL P>
struct MLong {
    LL x;
    MLong() : x{} {}
    MLong(LL x) : x{norm(x % getMod())} {}
    
    static LL Mod;
    static LL getMod() {
        if (P > 0) {
            return P;
        } else {
            return Mod;
        }
    }
    static void setMod(LL Mod_) {
        Mod = Mod_;
    }
    LL norm(LL x) const {
        if (x < 0) {
            x += getMod();
        }
        if (x >= getMod()) {
            x -= getMod();
        }
        return x;
    }
    LL val() const {
        return x;
    }
    explicit operator LL() const {
        return x;
    }
    MLong operator - () const {
        MLong res;
        res.x = norm(getMod() - x);
        return res;
    }
    MLong inv() const {
        assert(x != 0);
        return qpm(*this, getMod() - 2);
    }
    MLong &operator *= (MLong rhs) & {
        x = mul(x, rhs.x, getMod());
        return *this;
    }
    MLong &operator += (MLong rhs) & {
        x = norm(x + rhs.x);
        return *this;
    }
    MLong &operator -= (MLong rhs) & {
        x = norm(x - rhs.x);
        return *this;
    }
    MLong &operator /= (MLong rhs) & {
        return *this *= rhs.inv();
    }
    friend MLong operator * (MLong lhs, MLong rhs) {
        MLong res = lhs;
        res *= rhs;
        return res;
    }
    friend MLong operator + (MLong lhs, MLong rhs) {
        MLong res = lhs;
        res += rhs;
        return res;
    }
    friend MLong operator - (MLong lhs, MLong rhs) {
        MLong res = lhs;
        res -= rhs;
        return res;
    }
    friend MLong operator / (MLong lhs, MLong rhs) {
        MLong res = lhs;
        res /= rhs;
        return res;
    }
    friend std::istream &operator >> (std::istream &is, MLong &a) {
        LL v;
        is >> v;
        a = MLong(v);
        return is;
    }
    friend std::ostream &operator << (std::ostream &os, const MLong &a) {
        return os << a.val();
    }
    friend bool operator == (MLong lhs, MLong rhs) {
        return lhs.val() == rhs.val();
    }
    friend bool operator != (MLong lhs, MLong rhs) {
        return lhs.val() != rhs.val();
    }
};
 
template<>
LL MLong<0LL>::Mod = 1;
 
template<int P>
struct MInt {
    int x;
    MInt() : x{} {}
    MInt(LL x) : x{norm(x % getMod())} {}
    
    static int Mod;
    static int getMod() {
        if (P > 0) {
            return P;
        } else {
            return Mod;
        }
    }
    static void setMod(int Mod_) {
        Mod = Mod_;
    }
    int norm(int x) const {
        if (x < 0) {
            x += getMod();
        }
        if (x >= getMod()) {
            x -= getMod();
        }
        return x;
    }
    int val() const {
        return x;
    }
    explicit operator int() const {
        return x;
    }
    MInt operator - () const {
        MInt res;
        res.x = norm(getMod() - x);
        return res;
    }
    MInt inv() const {
        assert(x != 0);
        return qpm(*this, getMod() - 2);
    }
    MInt &operator *= (MInt rhs) & {
        x = 1LL * x * rhs.x % getMod();
        return *this;
    }
    MInt &operator += (MInt rhs) & {
        x = norm(x + rhs.x);
        return *this;
    }
    MInt &operator -= (MInt rhs) & {
        x = norm(x - rhs.x);
        return *this;
    }
    MInt &operator /= (MInt rhs) & {
        return *this *= rhs.inv();
    }
    friend MInt operator * (MInt lhs, MInt rhs) {
        MInt res = lhs;
        res *= rhs;
        return res;
    }
    friend MInt operator + (MInt lhs, MInt rhs) {
        MInt res = lhs;
        res += rhs;
        return res;
    }
    friend MInt operator - (MInt lhs, MInt rhs) {
        MInt res = lhs;
        res -= rhs;
        return res;
    }
    friend MInt operator / (MInt lhs, MInt rhs) {
        MInt res = lhs;
        res /= rhs;
        return res;
    }
    friend std::istream &operator >> (std::istream &is, MInt &a) {
        LL v;
        is >> v;
        a = MInt(v);
        return is;
    }
    friend std::ostream &operator << (std::ostream &os, const MInt &a) {
        return os << a.val();
    }
    friend bool operator == (MInt lhs, MInt rhs) {
        return lhs.val() == rhs.val();
    }
    friend bool operator != (MInt lhs, MInt rhs) {
        return lhs.val() != rhs.val();
    }
};
 
template<>
int MInt<0>::Mod = 1;
 
template<int V, int P>
MInt<P> CInv = MInt<P>(V).inv();
 
const int MO = 998244353;
using Z = MInt<MO>;

void solve() {
    int n; cin >> n;
    vector<int> a(n+1), b(n+1);
    for(int i = 1; i <= n; i ++) cin >> a[i];
    for(int i = 1; i <= n; i ++) {
        for(int j = i; j <= n; j += i) {
            b[i] = max(b[i], a[j]);
        }
    }
    sort(1+all(b));
    Z ans = 0;
    for(int i = 1; i <= n; i ++) {
        ans += (Z)b[i] * qpm(Z(2), i-1);
    }
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
    // cout << "time: " << 1000.0 * (1.*(clock() - t1) / CLOCKS_PER_SEC) << "ms\n";
    return 0;
}