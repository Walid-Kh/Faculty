#include <bits/stdc++.h>
using namespace std;
int di[] = {0, 0, 1, -1};
int dj[] = {1, -1, 0, 0};
struct node
{
    int value;
    node *left, *right;
};
node *createNode(int value)
{
    node *x = new node;
    x->value = value;
    x->left = nullptr;
    x->right = nullptr;
    return x;
}
class solution
{
    int recAns(node *x, int &size)
    {
        int res = x->value;
        queue<node *> q;
        if (x->left)
            q.push(x->left);
        if (x->right)
            q.push(x->right);
        while (q.size())
        {
            x = q.front();
            q.pop();
            res += x->value;
            size = size + 1;
            if (x->left)
                q.push(x->left);
            if (x->right)
                q.push(x->right);
        }
        return res;
    }

public:
    solution()
    {
        int n, m;
        cin >> n >> m;
        vector<node *> arr(n);
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            node *Node = createNode(x);
            arr[i] = Node;
        }
        int e;
        cin >> e;
        for (int i = 0; i < e; i++)
        {
            char dir;
            int parent;
            int child;
            cin >> dir >> parent >> child;
            if (dir == 'L')
                arr[parent]->left = arr[child];
            else
                arr[parent]->right = arr[child];
        }
        set<pair<int, int>> setofres;
        int res = 0;
        for (auto i : arr)
        {
            int size = 1;
            int x = recAns(i, size);
            if (setofres.find({size, x}) != setofres.end())
                res++;
            else if (size > m)
                setofres.insert({size, x});
        }
        cout << (res != 0) ? 1 : 0;
        for (auto i : arr)
            delete i;
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