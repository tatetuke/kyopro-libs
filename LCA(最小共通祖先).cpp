/*
* 
* https://penguinshunya.hatenablog.com/entry/2019/07/08/155325
template <typename T = ll>
struct LowestCommonAncestor {
    struct Edge {
        int to;
        T cost;
        Edge(int to, T cost) : to(to), cost(cost) {}
    };
    int n;
    int l;
    vector<vector<Edge>> es;
    vector<vector<int>> par;
    vector<int> dep;
    vector<T> dists;
    LowestCommonAncestor(int n) : n(n), es(n), dep(n), dists(n + 1) {
        l = 0;
        while ((1 << l) < n) l++;
        par.assign(n + 1, vector<int>(l, n));
    }
    void add_edge(int v, int u, T c = 0) {
        es[v].emplace_back(u, c);
        es[u].emplace_back(v, c);
    }
    void dfs(int v = 0, int d = 0, T c = 0, int p = -1) {
        if (p != -1) par[v][0] = p;
        dep[v] = d;
        dists[v] = c;
        for (auto e : es[v]) {
            if (e.to == p) continue;
            dfs(e.to, d + 1, c + e.cost, v);
        }
    }
    void build() {//lca‚ğ‹‚ß‚é‘Oˆ—
        dfs();
        for (int i = 0; i < l - 1; i++) {
            for (int v = 0; v < n; v++) {
                par[v][i + 1] = par[par[v][i]][i];
            }
        }
    }
    int lca(int v, int u) {
        if (dep[v] < dep[u]) swap(v, u);
        int gap = dep[v] - dep[u];
        for (int i = l - 1; i >= 0; i--) {
            if ((1 << i) & gap) v = par[v][i];
        }
        if (v == u) return v;
        for (int i = l - 1; i >= 0; i--) {
            int pv = par[v][i];
            int pu = par[u][i];
            if (pv != pu) v = pv, u = pu;
        }
        return par[v][0];
    }
    int length(int v, int u) {//v,uŠÔ‚Ì‹——£
        int a = lca(v, u);
        return dep[v] + dep[u] - dep[a] * 2;
    }
    T dist(int v, int u) {
        int a = lca(v, u);
        return dists[v] + dists[u] - dists[a] * 2;
    }
};



*/