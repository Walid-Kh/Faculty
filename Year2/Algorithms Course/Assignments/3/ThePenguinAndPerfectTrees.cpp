#include <bits/stdc++.h>
using namespace std;
int di[] = {0, 0, 1, -1};
int dj[] = {1, -1, 0, 0};
class solution
{
    void printBfs(vector<int> &arr)
    {
        queue<pair<int, int>> q;
        q.push({0, arr.size() - 1});
        int count = 1;
        while (q.size() && count <= arr.size())
        {
            pair<int, int> p = q.front();
            q.pop();
            int mid = p.first + ((p.second - p.first) / 2);
            if (p.first != p.second)
            {
                q.push({p.first, mid});
                q.push({mid + 1, p.second});
            }
            cout << arr[mid] << ' ';
            count++;
        }
    }

public:
    solution()
    {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (auto &i : arr)
            cin >> i;
        printBfs(arr);
    }
};
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solution *x = new solution();
    delete x;
    return 0;
}