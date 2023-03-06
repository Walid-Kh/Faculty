#include <bits/stdc++.h>
using namespace std;
class Solution
{
    long long n;
    map<pair<long long, bool>, long long> rec;
    long long dp(const vector<long long> &a, const vector<long long> &b, long long i, bool top)
    {
        if (i >= n)
            return 0;
        if (rec.find({i, top}) != rec.end())
            return rec[{i, top}];
        else
        {
            long long c1 = 0, c2 = 0, c3 = 0, c4 = 0;
            if (top)
                c1 = a[i] + dp(a, b, i + 1, !top);
            else
                c2 = b[i] + dp(a, b, i + 1, !top);
            c3 = dp(a, b, i + 1, top);
            c4 = dp(a, b, i + 1, !top);
            return rec[{i, top}] = max(c1, max(c2, max(c3, c4)));
        }
    }
    long long dpIterative(const vector<long long> &a, const vector<long long> &b)
    {
        vector<vector<long long>> recIterative(n + 1, vector<long long>(2, -1));
        recIterative[n][0] = 0;
        recIterative[n][1] = 0;
        for (long long i = n - 1; i >= 0; i--)
        {
            recIterative[i][0] = max(recIterative[i + 1][1] + a[i], max(recIterative[i + 1][0], recIterative[i + 1][1]));
            recIterative[i][1] = max(recIterative[i + 1][0] + b[i], max(recIterative[i + 1][0], recIterative[i + 1][1]));
        }
        return max(recIterative[0][0], recIterative[0][1]);
    }

public:
    Solution()
    {
        cin >> n;
        vector<long long> a(n);
        vector<long long> b(n);
        for (long long i = 0; i < n; i++)
            cin >> a[i];
        for (long long i = 0; i < n; i++)
            cin >> b[i];
        cout << dpIterative(a, b);
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