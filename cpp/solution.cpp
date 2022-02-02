#include <bits/stdc++.h>
using namespace std;

#define int long long

void fastio()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}
int n, m, s, t;
void all_shortest_path(vector<vector<int>> adj, int u, vector<int> &xd)
{
	vector<bool> visited(n + 1, false);
	queue<int> q;
	q.push(u);
	xd[u] = 0;
	visited[u] = true;
	while (!q.empty())
	{
		int current = q.front();
		q.pop();
		for (auto node : adj[current])
			if (!visited[node])
			{
				visited[current] = true;
				q.push(node);
				xd[node] = xd[current] + 1;
			}
	}
}

void solve()
{

	cin >> n >> m >> s >> t;
	vector<vector<int>> adj(n + 1);
	vector<vector<int>> direct(n + 1, vector<int>(n + 1));
	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
		direct[a][b] = true;
		direct[b][a] = true;
	}
	vector<int> s_d(n + 1), t_d(n + 1);
	all_shortest_path(adj, s, s_d);
	all_shortest_path(adj, t, t_d);
	// cout << "S_D" << endl;
	// for (int i = 1; i <= n; i++)
	// 	cout << s_d[i] << " ";

	// cout << endl;
	// cout << "T_D" << endl;
	// for (int i = 1; i <= n; i++)
	// 	cout << t_d[i] << " ";
	// cout << endl;
	int D = s_d[t];
	int ans = 0;
	vector<vector<bool>> done(n + 1, vector<bool>(n + 1, false));
	for (int i = 1; i <= n; i++)
	{
		for (int j = i + 1; j <= n; j++)
		{
			// if (done[i][j] || done[j][j])
			// 	continue;
			// done[i][j] = true;
			// done[j][i] = true;

			// if (i == j)
			// 	continue;
			// if (i == s && j == t || j == s && i == t)
			// 	continue;
			// if (direct[i][j])
			// 	continue;
			// int a = (s_d[i] + t_d[j]) + 1;
			// int b = (t_d[i] + s_d[j]) + 1;
			// if ((a >= D) && (b >= D))
			// 	ans++;
			// // cout << i << " " << j << endl;

			// // cout << a << " " << b << endl;
			// // 	 << endl;
			if ((direct[i][j] == 0) && (s_d[i] + t_d[j] + 1 >= D) && (s_d[j] + t_d[i] + 1 >= D) && i != j)
			{

				ans++;
			}
		}
	}
	cout << ans << endl;
}
signed main()
{
	fastio();
	int t = 1;
	// cin >> t;
	while (t--)
		solve();
}