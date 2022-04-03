#include<bits/stdc++.h>

using namespace std;
#define int long long
#define all(c) c.begin(), c.end()
#define FAST ios_base::sync_with_stdio(false) , cin.tie(NULL);
#define pii pair<int,int>
#define pb push_back
#define F first
#define S second
#define endl "\n"
#define bitcnt(n) __builtin_popcountll(n)
#define setpre(n) cout << fixed << setprecision(n)
#define tr(c) for(const auto& x : c ) cout << x << " "; cout << "\n";
#define PI acos(-1LL)

const int M = 1000000007;
const int N = 6e5 + 5;
const long long INF = 2e18 + 12;

#ifdef LOCAL

string to_string(const string &s) {
    return '"' + s + '"';
}

string to_string(const char *s) {
    return to_string((string) s);
}

string to_string(bool b) {
    return (b ? "true" : "false");
}

template<typename A, typename B>
string to_string(pair<A, B> p) {
    return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}

template<typename T>
string to_string(T v) {
    bool first = true;
    string res = "{";
    for (const auto &x: v) {
        if (!first) res += ", ";
        first = false;
        res += to_string(x);
    }
    res += "}";
    return res;
}

void bug() { cerr << endl; }

template<typename Head, typename... Tail>
void bug(Head H, Tail... T) {
    cerr << " " << to_string(H);
    bug(T...);
}

#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", bug(__VA_ARGS__);
#else
#define debug(...) 11;
#endif

int fact[N], invfact[N];

int pow(int a, int b) {
    int ans = 1;
    while (b) {
        if (b & 1LL)
            ans = (ans * a) % M;
        b /= 2;
        a = (a * a) % M;
    }
    return ans;
}

int modinv(int k) {
    return pow(k, M - 2);
}

int nCr(int x, int y) {
    if (y > x)
        return 0;
    int num = fact[x];
    num *= invfact[y];
    num %= M;
    num *= invfact[x - y];
    num %= M;
    return num;
}

void precompute() {
    fact[0] = fact[1] = 1;
    for (int i = 2; i < N; i++) {
        fact[i] = fact[i - 1] * i;
        fact[i] %= M;
    }
    invfact[N - 1] = modinv(fact[N - 1]);
    for (int i = N - 2; i >= 0; i--) {
        invfact[i] = invfact[i + 1] * (i + 1);
        invfact[i] %= M;
    }
}

int n, k;

vector<vector<int>> v;
vector<int> cnt;

void util_resize() {
    v.clear();
    cnt.clear();
    v.resize(n);
    cnt.resize(n);
}


vector<int> find_centers() {
    vector<int> degree(n, 0), leaves;
    for (int i = 0; i < n; i++) {
        degree[i] = v[i].size();
        if (v[i].size() == 1) {
            leaves.pb(i);
        }
    }
    int count = leaves.size();
    while (count < n) {
        vector<int> new_leaves;
        for (auto &i: leaves) {
            for (auto &x: v[i]) {
                degree[x]--;
                if (degree[x] == 1) {
                    new_leaves.pb(x);
                }
            }
            degree[i] = 0;
        }
        count += new_leaves.size();
        leaves = new_leaves;
    }
    return leaves;
}

void solve() {
    cin >> n >> k;
    util_resize();
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    if (n == 1) {
        cout << 1 << " " << 1 << endl;
        return;
    }
    //  1 <= centers.size() <= 2
    vector<int> centers = find_centers();
}

signed main() {
    FAST
    int tc = 1;
//    TODO: check for tc
    cin >> tc;
    while (tc--) {
        solve();
    }
}
