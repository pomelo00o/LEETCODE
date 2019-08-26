/*
 * @lc app=leetcode id=173 lang=cpp
 *
 * [173] Binary Search Tree Iterator
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
private:
    stack<TreeNode*> stk;
public:
    BSTIterator(TreeNode* root) {
        pushLeft(root);
    }
    
    /** @return the next smallest number */
    int next() {
        TreeNode* n = stk.top();
        stk.pop();
        pushLeft(n->right);
        return n->val;
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !(stk.empty());
    }

    void pushLeft(TreeNode* root) {
        while (root) {
            stk.push(root);
            root = root->left;
        }
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */

