class UnionFind
{
private:
    vector<int> par;
    vector<int> sz;

public:
    UnionFind(int n)
    {
        par = vector<int>(n);
        iota(par.begin(), par.end(), 0);
        sz = vector<int>(n, 1);
    }

    int find(int u)
    {
        // this optimisation was good.
        if (par[u] != par[par[u]])
            par[u] = find(par[par[u]]);
        return par[u];
    }

    bool connected(int u, int v)
    {
        u = find(u);
        v = find(v);
        if (u == v)
            return true;
        return false;
    }

    bool join(int u, int v)
    {
        u = find(u);
        v = find(v);
        if (u == v)
            return false;
        if (sz[u] <= sz[v])
        {
            sz[v] += sz[u];
            par[u] = v;
        }
        else
        {
            sz[u] += sz[v];
            par[v] = u;
        }
        return true;
    }
};
