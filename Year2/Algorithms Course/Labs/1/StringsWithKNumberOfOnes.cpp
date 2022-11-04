#include <bits/stdc++.h>
using namespace std;
int di[] = {0, 0, 1, -1};
int dj[] = {1, -1, 0, 0};
class solution
{
    int res = 0;
    int n, k;
    void recAns(string ans = "", int ones = 0)
    {
        if (ans.size() == n)
        {
            if (ones == k)
                res++;
            return;
        }
        recAns(ans + "0", ones);
        recAns(ans + "1", ones + 1);
    }

public:
    solution()
    {
        cin >> n >> k;
        recAns();
        cout << res;
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