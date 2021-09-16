#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// int dp[101][10001];

int solve0(int K, int N)
{

    vector< vector<int> > dp(K+1, vector<int>(N+1,0));
    //no egg:dp[0][j] = 0  only one egg:dp[1][j] = j  zero floor:dp[i][0] = 0
    for(int j = 1; j <= N; j++)
    {
        dp[1][j] = j;
        dp[0][j] = 0;
    }

    for(int i = 0; i <= K; i++)
    {
        dp[i][0] = 0;
    }
    for(int k = 2; k <= K; k++)
    {
        for(int n = 1; n <= N; n++)
        {
            int mint = N;
            for(int f = 1; f <= n; f++)
            {
                mint = min(mint, 1 + max(dp[k-1][f-1], dp[k][n-f]));
            }
            dp[k][n] = mint;
        }
    }

    return dp[K][N];
}

int solve1(int K, int N)
{   
    int ans = N;
    vector< vector<int> > dp(K+1, vector<int>(N+1,0));
    //  for(int j = 1; j <= N; j++)
    // {
    //     dp[1][j] = j;
    // }
    for(int k = 1; k <= K; k++)
    {
        for(int n = 1; n <= N; n++)
        {
            dp[k][n] = dp[k-1][n-1] + dp[k][n-1] + 1;
        }
    }

    for(int n = 1; n <= N; n++)
    {
        if(dp[K][n] >= N)
        {
            ans = n;
            break;
        }
    }

    return ans;
}


int solve2(int K, int N) //滚动数组优化
{   
    int ans = N;
    vector< vector<int> > dp(2, vector<int>(N+1,0));
    for(int k = 1; k <= K; k++)
    {
        for(int n = 1; n <= N; n++)
        {
            dp[k%2][n] = dp[(k-1)%2][n-1] + dp[k%2][n-1] + 1;
        }
    }

    for(int n = 1; n <= N; n++)
    {
        if(dp[K%2][n] >= N)
        {
            ans = n;
            break;
        }
    }

    return ans;
}

int main(){
    int m;
    cin >> m;
    while(m--)
    {
        int K, N;
        cin >> K >> N;
        cout << solve2(K, N) << endl;
    } 
    return 0;
}