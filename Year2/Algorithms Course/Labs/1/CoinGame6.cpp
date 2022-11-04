#include <bits/stdc++.h>
using namespace std;
int di[] = {0, 0, 1, -1};
int dj[] = {1, -1, 0, 0};
class solution
{
    int t, n;
    bool found = 0;
    void recAns(const vector<int> &arr, int acc = 0, int i = 0)
    {
        if (i > arr.size())
            return;
        if (acc == t)
        {
            found = 1;
            return;
        }
        recAns(arr, acc, i + 1);
        recAns(arr, acc + arr[i], i + 1);
    }

public:
    solution()
    {
        cin >> t >> n;
        vector<int> coins(n);
        for (auto &i : coins)
            cin >> i;
        sort(coins.begin(), coins.end());
        recAns(coins, 0, 0);
        if (found)
            cout << 1;
        else
            cout << 0;
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