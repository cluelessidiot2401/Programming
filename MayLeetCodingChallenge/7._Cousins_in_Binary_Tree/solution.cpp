#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for a binary tree node.
 */

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

#define parent_n_depth pair<TreeNode*, int>

class Solution {
public:

    void getDepth(TreeNode*& root, TreeNode* parent, int& x, int& y, parent_n_depth& pd_x, parent_n_depth& pd_y, int cur_depth){
        if(root == nullptr)
            return;
        if(root -> val == x)    pd_x = {parent, cur_depth};
        if(root -> val == y)    pd_y = {parent, cur_depth};
        
        getDepth(root->left, root, x, y, pd_x, pd_y, cur_depth + 1);
        getDepth(root->right, root, x, y, pd_x, pd_y, cur_depth + 1);
    }

    bool isCousins(TreeNode*& root, int& x, int& y) {
        int depth_x = -1, depth_y = -1, depth = 0;

        parent_n_depth pd_x = {nullptr, -1};
        parent_n_depth pd_y = {nullptr, -1};
        
        getDepth(root, nullptr, x, y, pd_x, pd_y, depth);
        
        // if(pd_x.second == -1 || pd_y.second == -1 || pd_x.second != pd_y.second || pd_x.first == pd_y.first)    return false;
        // return true;
        return !(pd_x.second == -1 || pd_y.second == -1 || pd_x.second != pd_y.second || pd_x.first == pd_y.first);        
    }
};