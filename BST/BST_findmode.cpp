//
// Created by Tom on 11/05/2020.
//

#include "BST_findmode.h"
#include <vector>
#include <climits>
#include <stack>
#include "binary_inorder.cpp"
using namespace std;


class SolutionMode {
public:
    //using iteration method
    // 使用了额外一个 O(n) 的空间来储存 每个叶子节点
    vector<int> findMode(TreeNode* root) {
        int cur = 1 , max =1, pre = INT_MIN;
        vector<int>res;
        stack<TreeNode*> stack;
        while(root != NULL || !stack.empty())
        {
            while(root!= NULL)
            {
                stack.push(root);
                root = root->left;
            }
            root = stack.top();
            stack.pop();
            if(pre == root->val){cur++;}
            else{cur =1;}
            if(cur > max)
            {
                max = cur;
                while(!res.empty())
                {
                    res.pop_back();
                }
            }
            if (cur == max)
            {
                res.push_back(root->val);
            }
            pre = root->val;
            root = root->right;
        }
        return res;
    }
    //using recursion
    //无额外空间使用
    vector<int> findModeRecusion(TreeNode* root) {
        vector<int> res;
        int pre = INT_MIN, max = 1, cur =  1;
        if(root == NULL)
            return res;
        dfs(root,pre, res, cur, max);
        return res;
    }
    void dfs(TreeNode* root, int&pre, vector<int>& res, int& cur, int& max)
    {
        if(root == NULL) return;
        dfs(root->left, pre, res, cur, max);
        if(pre == root->val) cur++;
        else cur =1;
        if(cur == max) res.push_back(root->val);
        else if(cur > max)
        {
            max = cur;
            res.clear();
            res.push_back(root->val);
        }
        pre = root->val;
        dfs(root->right, pre,res, cur, max );
    }
};

