/*
 * Binary_Tree_Inorder_Traversal.cpp
 *
 *  Created on: Nov 4, 2016
 *      Author: mohammra
 */

#include "common.h"


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        stack<pair<TreeNode*, bool>> s;
        if (root != NULL) s.push(pair<TreeNode*, bool>(root, false));
        vector<int> res;
        while(!s.empty()) {
            TreeNode* p = s.top().first;
            bool visited = s.top().second;
            s.pop();
            if (!visited) {
                if (p->right != NULL) {
                    s.push(pair<TreeNode*, bool>(p->right, false));
                }
                s.push(pair<TreeNode*, bool>(p, true));
                if (p->left != NULL) {
                    s.push(pair<TreeNode*, bool>(p->left, false));
                }
            } else {
                res.push_back(p->val);
            }
        }
        return res;
    }
};
