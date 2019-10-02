/*
 * @lc app=leetcode id=297 lang=cpp
 *
 * [297] Serialize and Deserialize Binary Tree
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
private:
    void serialize(TreeNode* node, ostringstream& out) {
        if (node) {
            out << node->val << " ";
            serialize(node->left, out);
            serialize(node->right, out);
        } else {
            out << "# ";
        }
    }

    TreeNode* deserialize(istringstream& in) {
        string v_str;
        in >> v_str;
        if (v_str == "#") return nullptr;
        int v_int = stoi(v_str);
        TreeNode* node = new TreeNode(v_int);
        node->left = deserialize(in);
        node->right = deserialize(in);
        return node;
    }
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        ostringstream out;
        serialize(root, out);
        return out.str();
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        istringstream in(data);
        return deserialize(in);
    }

    // Tips: to use istringstream or ostringstream, "sstream" header file needs to be included
    // istringstream and ostringstream separates elements by space
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
// @lc code=end

