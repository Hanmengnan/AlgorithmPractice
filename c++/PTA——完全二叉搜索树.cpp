#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int getLeftNum(int total)
{
    int n = log(total) / log(2);
    int leafnodes_num = total - (pow(2, n) - 1);
    int leafnode_max = pow(2, n - 1);
    int other = pow(2, n - 1) - 1;
    return other + (leafnodes_num < leafnode_max ? leafnodes_num : leafnode_max);
}

void createTree(vector<int> &num, vector<int> &tree, int left, int right, int root)
/*  
    将num数组中，left---right范围的数按照层次遍历的顺序存入tree中，
    root是层次遍历时的索引值。
*/
{
    int total = right - left + 1;
    //一共有多少结点
    if (total == 0)
        return;

    int leftNodes_num = getLeftNum(total);
    //当前树的左子树有多少结点
    tree[root] = num[leftNodes_num + left];
    //因为根结点必然大于左子树上所有的结点，故必然是从left起的 leftNodes_num+1 个数作为根结点的值
    int leftRoot = root * 2 + 1;
    //左子树根节点，在层次遍历中的索引值
    int rightRoot = leftRoot + 1;
    //右子树根节点，在层次遍历中的索引值
    /*参照下图，层次遍历时的顺序
            0
        1       2
     3     4  5    6
    */
    createTree(num, tree, left, left + leftNodes_num - 1, leftRoot);
    createTree(num, tree, left + leftNodes_num + 1, right, rightRoot);
}

int main()
{
    int n;
    cin >> n;
    vector<int> num(n);
    vector<int> tree(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> num[i];
    }
    sort(num.begin(), num.end());
    createTree(num, tree, 0, n - 1, 0);
    cout << tree[0];
    for (int i = 1; i < n; ++i)
    {
        cout << " " << tree[i];
    }

    return 0;
}
