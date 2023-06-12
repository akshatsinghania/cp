#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
    int s = 0;
    int l = 4000000;
    int a = 1;
    int b = 2;
    int count = 1;
    while (true)
    {
        int c = a + b;
        if (c > l)
            break;
        if (c % 2 == 0)
            count += c;
        a = b;
        b = c;
        cout << c << " " << endl;
    }
    cout << count << endl;
}

signed main()
{

    int t = 1;
    while (t--)
    {
        solve();
    }
    return 0;
}