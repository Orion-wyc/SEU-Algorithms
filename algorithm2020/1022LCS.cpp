#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

const int MAXL = 505;

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int len1 = text1.length();
        int len2 = text2.length();
        vector<vector<int>> dp(len1+1,vector<int>(len2+1,0));
        for (int i = 1; i <= len1; i++)
        {
            for (int j = 1; j <= len2; j++)
            {
                if (text1[i-1] == text2[j-1])
                {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }
                else
                {
                    dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
                }
            }
        }
        return dp[len1][len2];
    }
};

int solve(const string &s1, const string &s2)
{
    int dp[MAXL][MAXL];
    int len1 = s1.length();
    int len2 = s2.length();
    for (int i = 1; i <= len1; i++)
    {
        for (int j = 1; j <= len2; j++)
        {
            if (s1[i-1] == s2[j-1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else
            {
                dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
            }
        }
    }
    return dp[len1][len2];
}

int main()
{
    int m;
    cin >> m;
    while (m--)
    {
        string s1, s2;
        cin >> s1 >> s2;
        cout << solve(s1, s2) << endl;
    }

    return 0;
}



/*
滚动数组优化
//#pragma comment(linker, "/STACK:16777216") //for c++ Compiler
#include <stdio.h>
#include <iostream>
#include <cstring>
#include <cmath>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
#define ll long long
#define Max(a,b) (((a) > (b)) ? (a) : (b))
#define Min(a,b) (((a) < (b)) ? (a) : (b))
#define Abs(x) (((x) > 0) ? (x) : (-(x)))

using namespace std;

const int INF  = 0x3f3f3f3f;
const int MAXN = 500;

int dp[2][5005];

int main(){
    int i, j, t, k, n, m;
    string str1, str2;
    while(EOF != scanf("%d",&n)){
        cin >> str1;
        str2 = str1;
        reverse(str1.begin(), str1.end());
        memset(dp, 0, sizeof(dp));
        for(i = 1; i <= n; ++i){
            for(j = 1; j <= n; ++j){
                if(str1[i - 1] == str2[j - 1]){
                    dp[i % 2][j] = max(dp[i % 2][j], dp[(i - 1) % 2][j - 1] + 1);
                }
                else{
                    dp[i % 2][j] = max(dp[(i - 1) % 2][j], dp[i % 2][j - 1]);
                }
            }
        }
        cout << n - dp[n % 2][n] << endl;   //answer = X.length() - LCS(X, Y)
    }
    return 0;
}

https://blog.csdn.net/fnzsjt/article/details/40424401?utm_medium=distribute.pc_relevant_t0.none-task-blog-BlogCommendFromBaidu-1.channel_param&depth_1-utm_source=distribute.pc_relevant_t0.none-task-blog-BlogCommendFromBaidu-1.channel_param
*/