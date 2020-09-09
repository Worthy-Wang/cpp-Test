#include <iostream>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <queue>
#include <set>
#include <vector>
#include <fstream>
#include <sstream>
#include <string.h>
#include <memory>
#include <limits>
#include <list>
#include <regex>
#include <functional>
#include <math.h>
#include <unordered_set>
using namespace std;

/*
begin:
end:
Time Complexity:
Space Complexity:
Method:
*/
struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL)
    {
    }
};
class Solution
{
    TreeNode *pre;

public:
    void DFS(TreeNode *root)
    {
        if (!root)
            return;
        DFS(root->left);
        pre->right = root;
        root->left = pre;
        pre = root;
        DFS(root->right);
        return;
    }

    TreeNode *Convert(TreeNode *pRootOfTree)
    {
        TreeNode *dummy = new TreeNode(-1);
        pre = dummy;
        DFS(pRootOfTree);
        TreeNode *head = dummy->right, *tail = pre;
        head->left = nullptr, tail->right = nullptr;
        return head;
    }
};
int main()
{
    Solution s;
    TreeNode *root = new TreeNode(10);
    TreeNode *l = new TreeNode(6);
    TreeNode *r = new TreeNode(14);
    root->left = l, root->right = r;
    TreeNode* ll = new TreeNode(4);
    TreeNode* lr = new TreeNode(8);
    TreeNode* rl = new TreeNode(12);
    TreeNode* rr = new TreeNode(16);
    l->left = ll, l->right = lr, r->left = rl, r->right = rr;
    TreeNode* head = s.Convert(root);
    for (; head->right; head = head->right)
        cout << head->val << endl;
    cout << "--------------------------------" << endl;
    for (; head; head = head->left)
        cout << head->val << endl;
    return 0;
}
