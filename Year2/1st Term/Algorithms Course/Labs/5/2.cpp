#include <bits/stdc++.h>
using namespace std;
int di[] = {0, 0, 1, -1};
int dj[] = {1, -1, 0, 0};
class Solution
{
    int k, n;
    unsigned long long solve(vector<vector<unsigned long long>> &dp,
                             int people,
                             int teams)
    {
        if (teams > people)
            return 0;
        if (people == 0)
            return 0;
        if (teams == 0 && people == 0)
            return 1;
        if (teams == 0 || teams == people || teams == 1)
            return 1;
        if (dp[people][teams] != 0)
            return dp[people][teams];
        /*
            decrement k
            include person[i] in his own team
            or in a existing team


         */

        else
        {
            unsigned long long res1 = 0;
            unsigned long long res2 = 0;
            res1 += solve(dp, people - 1, teams - 1);
            res2 += teams * solve(dp, people - 1, teams);

            return dp[people][teams] = res1 + res2;
        }
    }

public:
    Solution()
    {
        cin >> n >> k;
        vector<vector<unsigned long long>> dp(n + 1, vector<unsigned long long>(k + 1, 0));
        cout << solve(dp, n, k);
    }
};
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    Solution *x = new Solution();
    delete x;
    return 0;
}