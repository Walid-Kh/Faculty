#include <bits/stdc++.h>
using namespace std;
vector<vector<long long>> rec(10001, vector<long long>(2, INT_MAX));
class Solution
{
    // long long m;
    // long long minWeapons = INT_MAX;
    // long long dp(const vector<long long> &weapons, long long monster, long long i, long long &mn)
    // {
    //     if (monster < 0)
    //         return INT16_MAX;
    //     if (i == m)
    //     {
    //         return 1;
    //     }
    //     if (monster > minWeapons)
    //         return INT16_MAX;
    //     if (monster == 0)
    //     {
    //         mn = min(mn, monster);
    //         return 1;
    //     }
    //     else
    //     {
    //         mn = min(mn, monster);
    //         if (monster - minWeapons < 0)
    //             return 0;
    //         int c1 = 0, c2 = 0;
    //         c1 = 1 + dp(weapons, monster - weapons[i], i, mn);
    //         c2 = dp(weapons, monster, i + 1, mn);
    //         return min(c1, c2);
    //     }
    // }
    void Iterative(const vector<long long> &weapons)
    {
        for (long long int i = 0; i < rec.size(); i++)
        {
            bool flag = 1;
            for (long long int j = 0; j < weapons.size(); j++)
            {
                if (i - weapons[j] >= 0 && weapons[j] != 0)
                {
                    if (rec[i][1] > rec[i - weapons[j]][1])
                    {
                        rec[i][0] = rec[i - weapons[j]][0] + 1;
                        rec[i][1] = rec[i - weapons[j]][1];
                    }
                    else if (rec[i][1] == rec[i - weapons[j]][1])
                        rec[i][0] = min(rec[i][0], rec[i - weapons[j]][0] + 1);
                    flag = 0;
                }
            }
            if (flag)
            {
                rec[i][0] = 0;
                rec[i][1] = i;
            }
        }
    }

public:
    Solution()
    {
        long long n, m;
        cin >> n;
        vector<long long> monsters(n);
        for (auto &i : monsters)
            cin >> i;
        cin >> m;
        vector<long long> weapons(m);
        for (auto &i : weapons)
            cin >> i;
        Iterative(weapons);
        for (long long i : monsters)
            cout << rec[i][1] << " " << rec[i][0] << '\n';
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