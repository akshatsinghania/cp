#include <bits/stdc++.h>
using namespace std;
int n, m, s, t;

void fastio()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void find_all_shortest_path(vector<vector<int>> adj, int u, vector<int> &xd)
{
    queue<pair<int, int>> q;
    vector<bool> visited(n + 1);
    q.push({u, 0});
    while (!q.empty())
    {
        pair<int, int> current = q.front();
        q.pop();
        visited[current.first] = true;
        xd[current.first] = current.second;
        for (auto node : adj[current.first])
            if (!visited[node])
                q.push({node, current.second + 1});
    }
}

void solve()
{
    cin >> n >> m >> s >> t;
    vector<vector<int>> adj(n + 1);
    vector<vector<int>> direct(n + 1, vector<int>(n + 1));
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        direct[u][v] = true;
        direct[v][u] = true;
    }
    vector<int> s_d(n + 1), t_d(n + 1);
    find_all_shortest_path(adj, s, s_d);
    find_all_shortest_path(adj, t, t_d);
    cout << "Adj list" << endl;
    for (int i = 1; i <= n; i++)
    {
        cout << i << "-> ";
        for (auto x : adj[i])
            cout << x << " ";
        cout << endl;
    }
    cout << "Directions" << endl;
    for (int i = 1; i <= n; i++)
    {
        for (auto y : direct[i])
            cout << y << " ";
        cout << endl;
    }
    cout << "From s to all" << endl;
    for (int i = 1; i <= n; i++)
        cout << s_d[i] << " ";
    cout << endl;
    cout << "From t to all" << endl;
    for (int i = 1; i <= n; i++)
        cout << t_d[i] << " ";
}
signed main()
{
    fastio();
    int t = 1;
    while (t--)
        solve();
}