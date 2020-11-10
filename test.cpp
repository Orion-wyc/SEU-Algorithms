#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

const int MAXN = 365+5;
const int INF = 0x3f3f3f3f;
int solve(const int days[], const int price[], int n)
{
    int dp[MAXN];
    for(int i=0;i<MAXN;i++)dp[i] = 0;
    
    int N = days[n-1];
    int cntDay = 0;
    for (int i = 1; i <= N; i++)
    {
        if (dp[i]!=-1)
        {
            dp[i] = dp[i - 1];
        }
        else
        {
            // cntDay ++;
            int p = dp[i - 1] + price[0];
            int q = i > 7 ? dp[i - 7] + price[1] : price[1];
            int z = i > 30 ? dp[i - 30] + price[2] : price[2];
        
            dp[i] = min(min(p, q), z);
            // dp[i] = min(dp[i - 1] + price[0], 
            //             min(dp[max(i-7, 0)] + price[1], dp[max(i-30, 0)] + price[2]));
        }
    }
    return dp[N];
}

int main()
{
    int m;
    cin >> m;
    while (m--)
    {
        int n;
        cin >> n;
        int days[MAXN];
        int price[3];

        for (int i = 0; i < n; i++)
        {
            int num;
            cin >> num;
            days[i] = num;
        }
        for (int i = 0; i < 3; i++)
        {
            int x;
            cin >> x;
            price[i] = x;
        }
        cout << solve(days, price, n) << endl;
    }
    // system("pause")
    return 0;
}