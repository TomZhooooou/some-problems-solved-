//
// Created by Tom on 12/05/2020.
//

#include <cstddef>
#include <stack>

/* 拿TreeNode 定义 */
#include "../BST/binary_inorder.cpp"

using namespace std;

class SolutionCumulative {
    int num = 0;
public:
    // BackTracking Time: O(n) Space: O(n)
    // 本题只需反转 中序遍历
    TreeNode* convertBST(TreeNode* root) {
        if(root == NULL) return NULL;
        convertBST(root->right);
        root->val += num;
        num = root->val;
        convertBST(root->left);
        return root;
    }

    //using stack same as above
    TreeNode* convertBSTStack(TreeNode* root) {
        if(root == NULL )return NULL;
        stack<TreeNode*> stack;
        TreeNode* p = root;
        int num = 0;
        while(p!= NULL || !stack.empty())
        {
            while(p!=NULL)
            {
                stack.push(p);
                p = p->right; //先找到最优树节点
            }
            p = stack.top();
            stack.pop();
            num +=p->val;
            p->val = num;
            p = p->left;
        }
        return root;
    }

    //Morris traverse Time: O(n) Space: O(1)
    TreeNode* getSuccussor(TreeNode* node)
    {
        TreeNode* succ = node->right;
        while(succ->left!= node && succ->left!=NULL)// 防止死循环
        {
            succ = succ->left;
        }
        return succ;
    }
    TreeNode* convertBSTMorris(TreeNode* root) {
    int sum = 0;
    TreeNode* node = root;
    while(node!= NULL)
    {
        if(node->right == NULL)
        {
            sum += node->val;
            node->val = sum;
            node = node->left;
        }
        else{
            TreeNode* succ = getSuccussor(node);
            if(succ->left == NULL)
            {
                succ->left = node;
                node = node->right;
            }
            else{
                sum+= node->val;
                node->val = sum;
                node = node->left;
                succ->left = NULL;
            }
        }
    }
    return root;
    }
};