// test case 1
// 3 3
// 3 -3 4
// 2 2 0
// 7 -2 -2

// 5

// test case 2
// 2 3
// -3 0 3
// 2 1 0

// 4

#include <bits/stdc++.h>
using namespace std;
#define ll long long;
int di[] = {0, 0, 1, -1};
int dj[] = {1, -1, 0, 0};
map<int, int> mx;
set<int> s;
class Solution
{
    int n, m;

    int dp(int i, int sum, const vector<int> &matrix, set<int> s)
    {
        if (i == matrix.size())
            return sum == 0 ? s.size() : 0;
        else
        {
            int c0 = dp(i + 1, sum, matrix, s);
            int c1 = 0;
            if (s.find(matrix[i]) == s.end())
            {
                s.insert(matrix[i]);
                c1 = dp(i + 1, sum + matrix[i], matrix, s);
            }
            return max(c1, c0);
        }
    }

public:
    Solution()
    {
        cin >> n >> m;
        int size = m * n;
        vector<int> matrix(size);
        for (int i = 0; i < size; i++)
            cin >> matrix[i];
        cout << dp(0, 0, matrix, s);
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