#include <bits/stdc++.h>
using namespace std;
int di[] = {0, 0, 1, -1};
int dj[] = {1, -1, 0, 0};
struct Node
{
    int value;
    Node *left, *right;
};
class BST
{
    Node *root;
    void destroyTree(Node *root)
    {
        if (root)
        {
            destroyTree(root->left);
            destroyTree(root->right);
            root->left = nullptr;
            root->right = nullptr;
            delete root;
        }
    }
    Node *createNode(int x)
    {
        Node *node = new Node();
        node->value = x;
        node->left = nullptr;
        node->right = nullptr;
        return node;
    }
    Node *insert(Node *&root, int x)
    {
        if (root == nullptr)
        {
            Node *node = createNode(x);
            root = node;
        }
        else if (root->value >= x)
        {
            root->left = insert(root->left, x);
        }
        else if (root->value < x)
        {
            root->right = insert(root->right, x);
        }
        return root;
    }
    Node *remove(Node *&root, int x)
    {
        if (root == nullptr)
            return nullptr; // corner case empty tree
        else if (root->value < x)
            root->right = remove(root->right, x);
        else if (root->value > x)
            root->left = remove(root->left, x);
        else
        {
            // NO CHILD
            if (root->left == nullptr && root->right == nullptr) // leaf
            {
                delete root;
                root = nullptr;
            }
            // ONE CHILD
            else if (root->left == nullptr)
            {
                Node *temp = root;
                root = root->right;
                delete temp;
            }
            else if (root->right == nullptr)
            {
                Node *temp = root;
                root = root->left;
                delete temp;
            }
            else
            {
                Node *temp = root->left;
                while (temp->right != nullptr)
                    temp = temp->right;
                root->value = temp->value;
                remove(root->left, temp->value);
            }
        }
        return root;
    }
    Node *search(Node *root, int x, int &n)
    {
        if (root == nullptr)
            return nullptr;
        else if (root->value == x)
        {
            n++;
            return root;
        }
        else
        {
            Node *res;
            n++;
            switch (root->value >= x)
            {
            case 1:
                res = search(root->left, x, n);
                break;
            case 0:
                res = search(root->right, x, n);
                break;
            };
            return res;
        }
    }

public:
    BST()
    {
        this->root = nullptr;
    }
    ~BST()
    {
        destroyTree(root);
    }
    void insert(int x)
    {
        insert(this->root, x);
    }
    void remove(int x)
    {
        remove(this->root, x);
    }
    Node *getRoot()
    {
        return root;
    }
    Node *search(int x, int &n)
    {
        return search(this->root, x, n);
    }
};
class solution
{
public:
    solution()
    {
        int n, q;
        cin >> n >> q;
        BST departments;
        unordered_map<int, BST> ids;
        for (int i = 0; i < n; i++)
        {
            int d, id;
            cin >> d >> id;
            if (ids.find(d) == ids.end())
                departments.insert(d);
            ids[d].insert(id);
        }
        queue<pair<int, int>> output;
        for (int i = 0; i < q; i++)
        {
            int d, id;
            cin >> d >> id;
            int res = 0;
            bool found = 0;
            if (departments.search(d, res))
                ids[d].search(id, res) != nullptr ? found = 1 : found = 0;
            output.push({res, found});
        }
        while (output.size())
        {
            cout << output.front().first << " " << output.front().second << '\n';
            output.pop();
        }
        
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