#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
    vector<int> preorder;
    vector<int> inorder;

public:
    TreeNode *getTree(int p, int l, int h)
    {
        if (l > h)
            return NULL;
        if (l == h)
            return new TreeNode(inorder[l]);

        TreeNode *root = new TreeNode(preorder[p]);
        int mid = find(inorder.begin() + l, inorder.begin() + h, preorder[p]) - inorder.begin();

        root->left = getTree(p + 1, l, mid - 1);
        root->right = getTree(p + (mid - l) + 1, mid + 1, h);

        return root;
    }
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        this->preorder = preorder;
        this->inorder = inorder;

        getTree(0, 0, inorder.size() - 1);
    }
};
int main()
{
    Solution s = Solution();
    vector<int> v = {-10, -3, 0, 5, 9};
    TreeNode *p = s.buildTree(v, v);

    return 0;
}