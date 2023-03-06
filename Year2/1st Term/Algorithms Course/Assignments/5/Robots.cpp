#include <bits/stdc++.h>
using namespace std;
#define ll long long;
int di[] = {0, 0, 1, -1};
int dj[] = {1, -1, 0, 0};
long long n;
class Solution
{
    void stackDFS(const vector<vector<int>> &adjMat, map<int, bool> &vis, stack<int> &s, int i)
    {
        vis[i] = 1;
        for (long long j = 0; j < adjMat[i].size(); j++)
        {
            int x = adjMat[i][j];
            if (vis[x] == 0)
                stackDFS(adjMat, vis, s, x);
        }
        s.push(i);
    }
    void DFS(const vector<vector<int>> &adjMat, map<int, bool> &vis, stack<int> &s)
    {
        for (long long i = 0; i < n; i++)
        {
            if (vis[i] == 0)
                stackDFS(adjMat, vis, s, i);
        }
    }

public:
    Solution()
    {
        cin >> n;
        vector<vector<int>> adjMat(n, vector<int>(0));
        map<int, bool> vis;
        stack<int> ans;
        for (long long i = 0; i < n; i++)
        {
            int t1, t2;
            cin >> t1 >> t2;
            if (t1 != -1)
                adjMat[t1].push_back(i);
            if (t2 != -1)
                adjMat[t2].push_back(i);
            vis[i] = 0;
        }
        DFS(adjMat, vis, ans);
        while (ans.size())
        {
            int x = ans.top();
            ans.pop();
            cout << x << " ";
        }
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