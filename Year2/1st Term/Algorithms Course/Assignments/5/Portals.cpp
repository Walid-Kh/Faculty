#include <bits/stdc++.h>
using namespace std;
#define ll long long;
int di[] = {0, 0, 1, -1};
int dj[] = {1, -1, 0, 0};
map<int, vector<pair<int, int>>> graph;
int mx = 0;
class Solution
{
public:
    Solution()
    {
        int n, m, s;
        cin >> n >> m >> s;
        for (int i = 0; i < m; i++)
        {
            int c0, c1, p;
            cin >> c0 >> c1 >> p;
            graph[c0].push_back({c1, p});
        }
        set<int> citiesReachable;
        vector<int> distance(n, INT16_MAX);
        set<pair<int, int>> q;
        q.insert({0, s});
        distance[s] = 0;
        while (!q.empty())
        {
            int v = q.begin()->second;
            q.erase(q.begin());
            for (auto i : graph[v])
            {
                int c1 = i.first;
                int len = i.second;
                if (distance[v] + len < distance[c1])
                {
                    q.erase({distance[c1], c1});
                    distance[c1] = distance[v] + len;
                    q.insert({distance[c1], c1});
                }
            }
            citiesReachable.insert(v);
        }
        for (auto i : distance)
            if (i != INT16_MAX)
                mx = max(mx, i);
        cout << citiesReachable.size() << " " << mx;
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