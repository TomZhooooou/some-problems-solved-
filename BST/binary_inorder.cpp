//
// Created by Tom on 11/05/2020.
//
#include "binary_inorder.h"
#include <vector>
#include <climits>
#include <stack>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) :val(x),left(nullptr),right(nullptr){}
};

class Solution {
public:
    //using recursion method
    int getMinimumDifference(TreeNode* root) {
    int pre = -1;
    int res = INT_MAX;
    dfs(root,pre,res);
    return res;
    }
    void dfs(TreeNode* root, int& pre,int& res)
    {
        if(root == NULL) return;
        dfs(root->left,pre, res);
        if(pre>=0) res = min(res, root->val-pre);
        pre = root->val;
        dfs(root->right,pre,res);
    }

    // using stack method
    int getMinimumDifferenceWithStack(TreeNode* root)
    {
        int pre = -1;
        stack<TreeNode*> stack;
        int res = INT_MAX;
        while(root != NULL || !stack.empty())
        {
            while(root != NULL) {
                stack.push(root);
                root = root->left;
            }
            root = stack.top();
            stack.pop();

            if(res > root->val - pre)
            {
                res = root->val- pre;
            }
            pre = root->val;
            root = root->right;
        }
            return res;
    }

};

