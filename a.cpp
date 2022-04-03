#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define FAST ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define int long long
#define pii pair<int, int>
#define pb push_back
#define F first
#define S second
#define all(c) c.begin(), c.end()
#define each(x, a) for (auto &x : a)
#define sz(c) int32_t(c.size())
#define bitcnt(n) __builtin_popcountll(n)
#define setpre(n) cout << fixed << setprecision(n)
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define tr(c) each(x, c) cout << x << " ";
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

template <typename T>
istream &operator>>(istream &is, vector<T> &v) {
    for (auto &data : v) is >> data;
    return is;
}

template <typename T>
ostream &operator<<(ostream &os, const vector<T> &v) {
    for (auto &data : v) os << data << " ";
    return os;
}

template <typename T, typename U>
istream &operator>>(istream &is, pair<T, U> &p) {
    is >> p.first >> p.second;
    return is;
}

template <typename T, typename U>
ostream &operator<<(ostream &os, pair<T, U> p) {
    os << p.first << ' ' << p.second;
    return os;
}

template <typename... T>
void read(T &...args) {
    ((cin >> args), ...);
}

template <typename... T>
void print(T... args) {
    ((cout << args << " "), ...);
    cout << "\n";
}

const int M = 1000000007;
const int N = 2e6 + 5;
const long long INF = 2e18 + 12;

void solve() {
    
}

signed main() {
    FAST int tc;
    read(tc);
    while (tc--) {
        solve();
    }
}