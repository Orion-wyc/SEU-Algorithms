#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

const int MAXN = 1e4 + 5;
const int INF = 0x3f3f3f3f;
typedef vector<pair<int, int>> VP;

int solve(const VP &price, int n)
{
    int dp[MAXN];
    for (int i = 0; i <= n; i++)
        dp[i] = 0;

    for (int len = 0; len <= n; len++)
    {
        for (int j = 0; j < price.size(); j++)
        {
            if (len >= price[j].first)
            {
                dp[len] = max(dp[len], dp[len - price[j].first] + price[j].second);
            }
        }
    }
    return dp[n];
}

int main()
{
    int m;
    cin >> m;
    while (m--)
    {
        int n, k;
        cin >> n >> k;
        // int longitude[MAXN];
        // int price[MAXN];

        VP price;
        for (int i = 0; i < k; i++)
        {
            pair<int, int> p;
            cin >> p.first >> p.second;
            price.push_back(make_pair(p.first, p.second));
        }
        cout << solve(price, n) << endl;
    }
    // system("pause")
    return 0;
}