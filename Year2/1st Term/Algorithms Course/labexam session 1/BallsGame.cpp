#include <bits/stdc++.h>
using namespace std;
#define ll long long;
int di[] = {0, 0, 1, -1};
int dj[] = {1, -1, 0, 0};
class Solution
{
public:
    Solution()
    {
        int v, b;
        cin >> v >> b;
        vector<int> balls(b);
        vector<int> rec(v + 1, INT16_MAX);
        for (auto &i : balls)
        {
            cin >> i;
            rec[i] = 1;
        }
        rec[0] = 1;
        for (int i = 1; i <= v; i++)
        {
            for (int j = 0; j < b; j++)
            {
                if (i >= balls[j] || i - balls[j] > 0)
                    rec[i] = min(rec[i], 1 + rec[i - balls[j]]);
            }
        }
        if (rec[v] != INT16_MAX)
            cout << rec[v];
        else
            cout << "no solution";
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