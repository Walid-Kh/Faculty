#include <bits/stdc++.h>
using namespace std;
int di[] = {0, 0, 1, -1};
int dj[] = {1, -1, 0, 0};
class Solution
{
    int n;
    int greedy(vector<pair<int, int>> assignments)
    {
        multiset<int> answer;
        int clock = 1;
        for (int i = 0; i < assignments.size(); i++)
        {
            if (assignments[i].first >= clock)
            {
                answer.insert(assignments[i].second);
                clock++;
            }
            else
            {
                if (assignments[i].second > *answer.begin())
                {
                    answer.erase(answer.begin());
                    answer.insert(assignments[i].second);
                }
            }
        }
        long long res = 0;
        for (auto i : answer)
            res += i;
        return res;
    }

public:
    Solution()
    {
        cin >> n;
        long long acc = 0;
        vector<pair<int, int>> assignments(n);
        for (auto &i : assignments)
            cin >> i.first;
        for (auto &i : assignments)
        {
            cin >> i.second;
            acc += i.second;
        }
        sort(assignments.begin(), assignments.end());
        cout << acc - greedy(assignments);
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