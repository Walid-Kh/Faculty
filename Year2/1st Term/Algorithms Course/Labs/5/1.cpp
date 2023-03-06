#include <bits/stdc++.h>
using namespace std;
int di[] = {0, 0, 1, -1};
int dj[] = {1, -1, 0, 0};
class Solution
{
    int n, k, r, x, y;
    unsigned long long solve(const vector<pair<int, int>> &moves,
                             vector<vector<vector<unsigned long long>>> &dp,
                             int posx, int posy, int trails)
    {
        if ((posx >= n  || posy >= n || posx < 0 || posy < 0))
            return 1;
        if (trails <= 0)
            return 0;
        if (dp[posx][posy][trails] != 0)
            return dp[posx][posy][trails];
        else
        {
            unsigned long long res = 0;
            for (auto i : moves)
                res += solve(moves, dp, posx + i.first, posy + i.second, trails - 1);
            return dp[posx][posy][trails] = res;
        }
    }

public:
    Solution()
    {
        cin >> n >> k >> r >> x >> y;
        vector<pair<int, int>> moves(r);
        vector<vector<vector<unsigned long long>>> dp(101, vector<vector<unsigned long long>>(101, vector<unsigned long long>(101, 0)));
        for (auto &i : moves)
            cin >> i.first >> i.second;
        cout << solve(moves, dp, x, y, k);
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