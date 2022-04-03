#include<bits/stdc++.h>

using namespace std;

#warning "use 0 based indexing";
class UnionFind {
public:
    int n{};
    vector<int> size;
    vector<int> parent;

    explicit UnionFind(int n) {
        this->n = n;
        parent.resize(n);
        parent.shrink_to_fit();
        size.assign(n, 1);
        iota(parent.begin(), parent.end(), 0);
    }

    int find(int u) {
        if (parent[u] == u) return u;
        return parent[u] = find(parent[u]);
    }

    bool uni(int u, int v) {
        int rootU = find(u);
        int rootV = find(v);
        if (rootU == rootV) return false;

        if (size[rootU] < size[rootV]) {
            parent[rootU] = rootV;
            size[rootV] += size[rootU];
            size[rootU] = 0;
        } else {
            parent[rootV] = rootU;
            size[rootU] += size[rootV];
            size[rootV] = 0;
        }
        return true;
    }

    bool isUnion(int u, int v) {
        return find(u) == find(v);
    }

    auto getSets() {
        vector <vector<int>> sets;
        set<int> roots;
        for (int i = 0; i < n; i++) {
            roots.insert(find(i));
        }
        sets.resize(roots.size());
        for (int i = 0; i < n; i++) {
            sets[find(i)].push_back(i);
        }
        return sets;
    }
};


int main() {
    int n, m;
    cin >> n >> m;
    auto dsu = UnionFind(n);
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        x--, y--;
        dsu.uni(x, y);
    }
}