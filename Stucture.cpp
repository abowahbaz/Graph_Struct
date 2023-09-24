struct Graph
{
    int nodes = 1;
    int edges = 0;
    int cc_count = 0;
    vector<vector<int>> adj;
    vector<int> dis;
    vector<bool> vis;
    Graph(int n, int m)
    {
        nodes = n;
        edges = m;
        adj = vector<vector<int>>(n + 1);
        vis = vector<bool>(n + 1, false);
        dis = vector<int>(n + 1);
    }
    void addEdge(int u, int v)
    {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    void build()
    {
        int u, v;
        for (int i = 0; i < edges; i++)
        {
            cin >> u >> v;
            addEdge(u, v);
            addEdge(v, u);
        }
    }

    void DFS(int node)
    {
        vis[node] = true;
        for (auto child : adj[node])
            if (!vis[child])
                DFS(child);
    }

    void CC()
    {

        for (int i = 1; i <= nodes; i++)
        {
            if (!vis[i])
            {
                cc_count++;
                DFS(i);
            }
        }
    }

    bool isTree()
    {
        CC();
        if (cc_count > 1 || edges > nodes - 1)
            return 0;
        else
            return 1;
    }
};
