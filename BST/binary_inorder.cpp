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
        long int pre = INT_MIN; //如果只是int 会导致 p->val - pre 为INT_MIN, 因为这是int能表示的最小值
        stack<TreeNode*> stack;
        int res = INT_MAX;
        TreeNode* p = root;
        while(p != NULL || !stack.empty())
        {
            while(p != NULL) {
                stack.push(p);
                p = p->left;
            }
            p = stack.top();
            stack.pop();
            if(res > (p->val - pre))
            {
                res = p->val - pre;
            }
            pre = p->val;
            p= p->right;
        }
            return res;
    }

};

