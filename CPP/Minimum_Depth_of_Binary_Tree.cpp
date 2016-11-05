/*
 * Minimum_Depth_of_Binary_Tree.cpp
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
    int minDepth(TreeNode* root) {
        if (root == NULL) return 0;
        int left_depth = minDepth(root->left);
        int right_depth = minDepth(root->right);
        if (left_depth > 0 && right_depth > 0) {
            return min(left_depth, right_depth) + 1;
        }
        else {
            return left_depth + right_depth + 1;
        }
    }
};
