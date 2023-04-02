#include <bits/stdc++.h>
using namespace std;

#define int long long

int sum_(int a, int n)
{
    return (a * n) + ((pow(n, 2) - n) / 2);
}

void solve()
{
    cout << sum_(2, 10) << endl;
}

signed main()
{
    // in();
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}