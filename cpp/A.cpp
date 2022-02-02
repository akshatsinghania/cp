#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl "\n"

void setIO(string s)
{
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}

void solve()
{
    vector<vector<char>> grid(3, vector<char>(3));
    map<char, int> exist;
    for (auto &x : grid)
    {
        for (auto &y : x)
        {
            cin >> y;
            exist[y]++;
        }
    }

    int green = 0, yellow = 0;
    map<char, int> extras;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            char c;
            cin >> c;
            if (grid[i][j] == c)
            {
                green++;
                exist[c]--;
            }
            else if (exist.find(c) != exist.end())
            {
                if (exist[c] > 0)
                {
                    yellow++;
                    exist[c]--;
                }
            }
        }
    }
    cout << green << endl;
    cout << yellow << endl;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    // cin>>t;
    while (t--)
        solve();
    return 0;
}