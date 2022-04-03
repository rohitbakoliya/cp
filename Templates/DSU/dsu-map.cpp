#include<bits/stdc++.h>

using namespace std;

#warning "use 0 based indexing";
template<typename T, typename Compare = std::less<T>>
class UnionFind {
public:
    map<T, T, Compare> parent;
    map<T, int> sizes;

    UnionFind() = default;

    explicit UnionFind(int n) {
        for (int i = 0; i < n; i++) {
            parent[i] = i;
            sizes[i] = 1;
        }
    }

    T find(T u) {
        if (parent[u] == u || !parent.count(u)) return u;
        return parent[u] = find(parent[u]);
    }

    bool uni(T u, T v) {
        if (parent.count(u) == 0) {
            parent[u] = u;
            sizes[u] = 1;
        }
        if (parent.count(v) == 0) {
            parent[v] = v;
            sizes[v] = 1;
        }

        int rootU = find(u);
        int rootV = find(v);
        if (rootU == rootV) return false;

        if (sizes[rootU] < sizes[rootV]) {
            parent[rootU] = rootV;
            sizes[rootV] += sizes[rootU];
            sizes.erase(rootU);
        } else {
            parent[rootV] = rootU;
            sizes[rootU] += sizes[rootV];
            sizes.erase(rootV);
        }
        return true;
    }

    bool isUnion(T u, T v) {
        return find(u) == find(v);
    }

    auto getGroups() {
        map<T, vector<T>, Compare> groups;
        for (auto const &x: parent) {
            T u = x.first;
            groups[find(u)].push_back(u);
        }
        return groups;
    }
};

int main() {
    int n, m;
    cin >> n >> m;
    auto dsu = UnionFind<int>(n);

    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        x--, y--;
        dsu.uni(x, y);
        multiset<int> st;
        for (int j = 0; j < n; j++) {
            if (dsu.sizes.count(j))
                st.insert(dsu.sizes[j]);
        }
        for (auto k : st) cout << k << " ";
        cout << endl;
    }
}